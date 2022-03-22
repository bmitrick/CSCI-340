#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>

/*
a. Take as a parameter the number of consumer tasks to run.
b. The main program will start up the number of tasks specified on the command
   line. Each task will be assigned a task number that is passed to the
   task as a parameter.
c. Read lines from stdin. The reason for using stdin is that you can either
   type in lines to test with or produce a text file that you redirect
   into the program. To grade the program, I will be using a larg text
   file (I'm thinling the text for one of Shakespeare's plays). You will
   need to figure out how to detet end of file on stdin.
d. Each line from the file will be pushed to a queue by the main task.
e. The comsumer tasks will pop lines off the queue when available. The order
   of lines popped is not important.
f. For each line a consumer task pops from the queue it will:
  I. Print the task number and the line.
  II. Count the words on the line (don't worry about punctuation, my test file
      will have all non-alphabetic character removed) and accumulate the sum
      of the number of words.
g. When all lines of the input have been read:
  I. Signal all consumer tasks to terminate.
  II. Accumulate the word counts.
  III. Print the total word count.
*/

#define DATASIZE 100000

//Globals
char emptyString[DATASIZE] = {'\0'};
pthread_mutex_t lock;

struct node {
  char data[DATASIZE];      //Space for the string to be stored
  struct node *next; //Next item in the queue
};

struct queue {
  struct node *front;  //Item at the front of the queue
  struct node *rear;   //Item at the end of the queue
};

//Generates new node
struct node* newNode(char data[DATASIZE]){
  struct node* i = (struct node*)malloc(sizeof(struct node));
  strcat(i->data, data);
  i->next = NULL;
  return i;
}

//Generates empty queue
struct queue* createQueue(){
  struct queue* q = (struct queue*)malloc(sizeof(struct queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
};

//Add item to the back of the queue
void push(struct queue* q, char data[DATASIZE]){
  //Generates node to be added
  struct node* i = newNode(data);

  //Check if queue is empty
  if(q->rear == NULL){
    //If empty, add i and set rear and front to be i since it is the only thing in the queue
    q->rear = i;
    q->front = i;
    //printf("checkpoint 1 \n");
  } else {
    //If not empty, add i to the back of the queue
    q->rear->next = i;
    q->rear = i;
  }

}

//Pop first item off queue
char * pop(struct queue* q){
  //Check if queue is empty
  if(q->rear == NULL){
    return emptyString;
  }

  //Take item from front of queue and save it in a tep var
  struct node* poppedNode = q->front;

  //Redefine the front of the queue as the second to front, essentially removing the actual front of the queue
  q->front = q->front->next;

  //check to see of the queue is now empty, if it is, make sure the rear reflects that
  if(q->front == NULL){
    q->rear = NULL;
  }

  //Return the popped items key (contents)
  return poppedNode->data;
}

//Global Queue
struct queue* q;
int sum = 0;

void *thread_function(void *arg){
  pthread_mutex_lock(&lock);

  int id = (int) (uintptr_t) arg;
  char *nodeData = pop(q);

  int localSum = 0;

  if(strcmp(nodeData, emptyString) != 0 && strcmp(nodeData, "\n") != 0){
    localSum++;
    for(int i = 0; nodeData[i] != '\0'; i++){
      if(nodeData[i] == ' ' && nodeData[i+1] != ' '){
        localSum++;
      }
    }
  }

  printf("Thread %d has found %d words in string %s \n", id, localSum, nodeData);

  sum += localSum;

  pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[]){
  q = createQueue();

  int numConsumers = atoi(argv[1]);

  //Init mutex
  if (pthread_mutex_init(&lock, NULL) != 0){
    printf("\n mutex init failed \n");
    return 1;
  }

  printf("If you would like to input with a text file, enter \'f\'. If you would like to enter input line by line, enter any other character \n");
  printf("\n");
  char inputSelect = getchar();

  if(inputSelect == 'f'){
    printf("You have selected input by text file. \n");
    printf("\n");

    //Pulls file name
    printf("Please input the name of the file to be used \n");
    printf("\n");

    char fileName[100];
    scanf("%s", fileName);

    printf("You have input the file: %s \n", fileName);
    printf("\n");

    //Open file
    FILE *file = fopen(fileName, "r");

    //Double check file was actually opened
    assert(file);

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    //Pushes each line to the queue
    while ((read = getline(&line, &len, file)) != -1){
      push(q, line);
    }

    fclose(file);

    printf("The data for your file has been read and added to the queue \n");
  } else {
    printf("You have selected to input your data line by line. Please type in the data and press enter at the end of each line. When you are done, please leave the input empty and press enter \n");
    printf("\n");

    /*
    char line[DATASIZE];
    scanf("%s", line);

    while(strcmp(line ,"EXIT_CODE_ABORT") != 0){
      push(q, line);
      scanf("%s", line);
    }
    */

    char *line = NULL;
    size_t len = 0;
    ssize_t linesize = 0;

    linesize = getline(&line, &len, stdin);
    linesize = getline(&line, &len, stdin);

    while(linesize != 1){
      push(q, line);
      linesize = getline(&line, &len, stdin);
    }

    printf("The data you have input has been processed and added to the queue \n");
  }

  /*
  //Test to see all data was collected
  char *nodeData;
  nodeData = pop(q);
  while(strcmp(nodeData, emptyString) != 0){
    printf("%s \n", nodeData);
    nodeData = pop(q);
  }
  */

  while(q->rear != NULL){
    pthread_t thread_id[numConsumers];

    //Create the threads
    for(int i = 0; i < numConsumers; i++){
      pthread_create (&thread_id[i], NULL, &thread_function, (void*) (uintptr_t)(i+1));
    }

    //Joins threads
    for(int i = 0; i < numConsumers; i++){
      pthread_join(thread_id[i], NULL);
    }
  }

  printf("in total, %d words were found \n", sum);
}

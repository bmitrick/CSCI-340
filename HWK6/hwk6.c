#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <stdint.h>

//Globals
char *str_address;
int len_str;
int str_len_counter = 0;
int last_thread_ID;

void *thread_function(void *arg){
  //Pulls thread ID
  int id = (int) (uintptr_t) arg;
  char *current_address = str_address;

  //Checks to see if string is currently full
  if (str_len_counter < len_str) {

    //Takes the thread with the highest ID and makes it fill all the empty spaces that would be left due to lack of threads
    if (id == last_thread_ID && (len_str - last_thread_ID > 0)){
      //Calc the number of blank spaces that should exist in the string
      int difference = len_str - last_thread_ID;

      //Loop the standard fill for each expected blank space
      for(int i = 0; i <= difference; i++){

        for (int j = 0; j <= len_str; j++){

          if (*current_address != 'a'){
            *current_address = 'a';
            str_len_counter += 1;

            printf("Thread %d added %c to the string \n", id, *current_address);
            break;
          }

          current_address++;
        }
      }
    } else {
      for (int j = 0; j <= len_str; j++){

        if (*current_address != 'a'){
          *current_address = 'a';
          str_len_counter += 1;

          printf("Thread %d added %c to the string \n", id, *current_address);
          break;
        }

        current_address++;
      }
    }
  }
}

int main(int argc, char *argv[]){
  int num_threads = atoi(argv[1]);
  last_thread_ID = num_threads;
  len_str = atoi(argv[2]);

  //Allocates memory for string and fills it with 'b's to show if each char was filled or not
  str_address = malloc(len_str + 1);
  memset(str_address, 'b', (len_str + 1));

  pthread_t thread_id[num_threads];

  //Create the threads
  for(int i = 0; i < num_threads; i++){
    pthread_create (&thread_id[i], NULL, &thread_function, (void*) (uintptr_t)(i+1));
  }

  //Joins threads
  for(int i = 0; i < num_threads; i++){
    pthread_join(thread_id[i], NULL);
  }

  //Prints string
  for(int i = 0; i < len_str; i++) {
    printf("%c", *(str_address + i));
  }

  printf("\n");
  return 0;
}

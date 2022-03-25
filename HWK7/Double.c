// CSCI-340 - Homework #7

// Starter file for the double linked list


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


// basic node structure

typedef struct __node_t {

    int key;
    struct __node_t *next;
    struct __node_t *prev;

} node_t;

// basic list structure (one used per list)

typedef struct {

    node_t *head;
    node_t *tail;

    pthread_mutex_t head_lock;
    pthread_mutex_t tail_lock;
} list_t;

// Initialize the list

void List_Init(list_t *L) {

    // Add code here to initialize the list
    node_t *tmp = malloc(sizeof(node_t));
    tmp->next = NULL;
    tmp->prev = NULL;
    L->head = L->tail = tmp;

    pthread_mutex_init(&L->head_lock, NULL);
    pthread_mutex_init(&L->tail_lock, NULL);
}

// Insert into the list (At the front)

void List_Insert(list_t *L,
                 int key) {

    // Add code here to safely insert a new node at the beginning of the list
    node_t *tmp = malloc(sizeof(node_t));         /* Get a new node */
    if (tmp == NULL) {                            /* Did the allocation fail? */
        perror("malloc");
        return;
    }

    tmp->key = key;
    tmp-> prev = NULL;

    pthread_mutex_lock(&L->head_lock);
    tmp->next = L->head;

    if (L->head != NULL){
      L->head->prev = tmp;
    }

    if (L->tail == NULL){
      L->tail = tmp;
    }

    L->head = tmp;
    pthread_mutex_unlock(&L->head_lock);
}

// Insert into the list (At the end)

void List_Append(list_t *L,
                 int key) {

    // Add code here to safely insert a new node at the end of the list
    node_t *tmp = malloc(sizeof(node_t));         /* Get a new node */
    if (tmp == NULL) {                            /* Did the allocation fail? */
        perror("malloc");
        return;
    }

    tmp->key = key;
    tmp->next = NULL;


    pthread_mutex_lock(&L->tail_lock);
    tmp->prev = L->tail;

    if(L->tail != NULL){
      L->tail->next = tmp;
    }

    if(L->head == NULL){
      L->head = tmp;
    }

    L->tail = tmp;
    pthread_mutex_unlock(&L->tail_lock);
}

//Returns index of the first occurence of the key in the queue, if it is not contained in the queue, it will return -1
int List_Lookup(list_t *L,
                int key) {

    // Add code here to lookup an item in the list
    pthread_mutex_lock(&L->head_lock); //Lock the whole list
    pthread_mutex_lock(&L->tail_lock);

    int i = 0;
    node_t *viewing = L->head;

    while(viewing != NULL){
      if(viewing->key == key){

        pthread_mutex_unlock(&L->head_lock); //Unlock the whole list
        pthread_mutex_unlock(&L->tail_lock);

        return i;
      }

      i++;
      viewing = viewing->next;
    }

    pthread_mutex_unlock(&L->head_lock); //Unlock the whole list
    pthread_mutex_unlock(&L->tail_lock);
    return -1;

}

int main()
{

    // Add code here to test your list
    list_t *L = malloc(sizeof(list_t));


    List_Append(L, 1); //Current List = [1]
    List_Append(L, 2); //Current List = [1,2]
    List_Insert(L, 3); //Current List = [3,1,2]


    printf("Node that contains 1 should be at index 1, is actually at index %d \n", List_Lookup(L, 1));
    printf("Node that contains 2 should be at index 2, is actually at index %d \n", List_Lookup(L, 2));
    printf("Node that contains 3 should be at index 0, is actually at index %d \n", List_Lookup(L, 3));
    printf("Node that contains 4 should be at index -1, is actually at index %d \n", List_Lookup(L, 4));
}

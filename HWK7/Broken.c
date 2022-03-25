// CSCI-340 "Broken"


#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct __node_t {

    int               value;
    struct __node_t * next;

} node_t;

typedef struct {

    node_t *        head;
    node_t *        tail;
    pthread_mutex_t head_lock;
    pthread_mutex_t tail_lock;

} queue_t;

void Queue_Init(queue_t *q) {

    node_t *tmp = malloc(sizeof(node_t));
    tmp->next = NULL;
    q->head = q->tail = tmp;

    pthread_mutex_init(&q->head_lock, NULL);
    pthread_mutex_init(&q->tail_lock, NULL);

}

void Queue_Enqueue(queue_t * q,
                   int       value) {

    // Problem 1 - Not releasing lock prior to error exit (or locking too soon)


    node_t *tmp = malloc(sizeof(node_t));         /* Get a new node */
    if (tmp == NULL) {                            /* Did the allocation fail? */
        perror("malloc");
        return -1;
    }

    tmp->value = value;                           /* Set the node's contents */
    tmp->next  = NULL;                            /* Show it's the tail */

    pthread_mutex_lock(&q->tail_lock);
    q->tail->next = tmp;                          /* Point old tail to new tail */
    q->tail = tmp;                                /* Point tail to new node */

    pthread_mutex_unlock(&q->tail_lock);

}

int Queue_Dequeue(queue_t * q,
                  int *     value) {

    // Failure is always an option
    int rc = -1;

    //Problem 2 - Lock should occur before getting value

    if (q->head->next != NULL) {
        pthread_mutex_lock(&q->head_lock);        /* Lock the list */
        *value = q->head->next->value;             /* Return the value */
        node_t *tmp = q->head;                    /* Save the old head node pointer */
        q->head = q->head->next;                   /* Reset the head */
        pthread_mutex_unlock(&q->head_lock);      /* Unlock the list */
        free(tmp);                                /* Free the old head node */
        rc = 0;
    }


    return rc;
}

int main(){}

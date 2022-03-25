#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int state = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void thread_exit(){
  pthread_mutex_lock(&mutex);
  state = 1;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);
}

void *thread_fun(void *arg){
  //Do something here
  thread_exit();
  return NULL;
}

void thr_join(){
  pthread_mutex_lock(&mutex);

  while(state == 0){
    pthread_cond_wait(&cond, &mutex);
  }

  pthread_mutex_unlock(&mutex);
}

int main(){
  pthread_t p1;
  pthread_t p2;
  pthread_create(&p1, NULL, thread_fun, NULL);
  pthread_create(&p2, NULL, thread_fun, NULL);
}

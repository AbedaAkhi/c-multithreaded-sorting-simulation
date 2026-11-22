#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

#define MAX_SIZE 200

/* Shared data used by the two sorting threads. */
typedef struct {
    int A[MAX_SIZE];
    int n;
    int swap;
    int turn;
    int complete;
    int noSwapT1;
    int noSwapT2;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} SharedData;

typedef struct {
    int id;
    SharedData *data;
} ThreadArgs;

void *sort(void *arg);

#endif

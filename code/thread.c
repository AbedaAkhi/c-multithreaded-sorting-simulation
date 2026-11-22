#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread.h"

void *sort(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    SharedData *data = args->data;
    int id = args->id;
    int localSwap = 0;

    while (1) {
        pthread_mutex_lock(&data->lock);

        while (data->turn != id && !data->complete) {
            pthread_cond_wait(&data->cond, &data->lock);
        }

        if (data->complete) {
            pthread_mutex_unlock(&data->lock);
            break;
        }

        int swapCount = 0;
        if (id == 0) {
            /* T1 compares even-indexed adjacent pairs. */
            for (int i = 0; i <= (data->n - 1) / 2; i++) {
                int idx = 2 * i;
                if (idx + 1 < data->n) {
                    int a = data->A[idx];
                    int b = data->A[idx + 1];
                    if (a > b) {
                        data->A[idx] = b;
                        data->A[idx + 1] = a;
                        swapCount++;
                    }
                }
            }
        } else {
            /* T2 compares odd-indexed adjacent pairs. */
            for (int i = 1; i <= (data->n - 1) / 2; i++) {
                int idx = 2 * i - 1;
                if (idx + 1 < data->n) {
                    int a = data->A[idx];
                    int b = data->A[idx + 1];
                    if (a > b) {
                        data->A[idx] = b;
                        data->A[idx + 1] = a;
                        swapCount++;
                    }
                }
            }
        }

        data->swap += swapCount;
        localSwap += swapCount;

        if (id == 0) {
            data->noSwapT1 = (swapCount == 0);
        } else {
            data->noSwapT2 = (swapCount == 0);
        }

        if (data->noSwapT1 && data->noSwapT2) {
            data->complete = 1;
            pthread_cond_signal(&data->cond);
            pthread_mutex_unlock(&data->lock);
            break;
        }

        data->turn = 1 - id;
        pthread_cond_signal(&data->cond);
        pthread_mutex_unlock(&data->lock);
    }

    printf("Thread ID %ld: total number of swaps = %d\n",
           (long)pthread_self(), localSwap);
    return NULL;
}

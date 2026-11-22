#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "thread.h"

int main(void) {
    SharedData data = {
        .n = 0, .swap = 0, .turn = 0, .complete = 0,
        .noSwapT1 = 0, .noSwapT2 = 0
    };

    pthread_mutex_init(&data.lock, NULL);
    pthread_cond_init(&data.cond, NULL);

    FILE *fp = fopen("ToSort", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (fscanf(fp, "%d", &data.A[i]) != 1) {
            break;
        }
        data.n++;
    }
    fclose(fp);

    pthread_t T1, T2;
    ThreadArgs *args1 = malloc(sizeof(ThreadArgs));
    ThreadArgs *args2 = malloc(sizeof(ThreadArgs));
    args1->id = 0;
    args2->id = 1;
    args1->data = args2->data = &data;

    pthread_create(&T1, NULL, sort, args1);
    pthread_create(&T2, NULL, sort, args2);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);

    printf("Sorted array:\n");
    for (int i = 0; i < data.n; i++) {
        printf("%d ", data.A[i]);
    }
    printf("\nTotal number of swaps to sort array A = %d\n", data.swap);

    pthread_mutex_destroy(&data.lock);
    pthread_cond_destroy(&data.cond);
    return 0;
}

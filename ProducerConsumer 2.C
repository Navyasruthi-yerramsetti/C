#include <stdio.h>
#include <stdlib.h>     // for rand()
#include <unistd.h>     // for sleep()
#include <pthread.h>
#include <semaphore.h>

int item;
sem_t empty, full;

void* producer() {
    while (1) {
        sem_wait(&empty);
        item = rand() % 100;
        printf("Produced: %d\n", item);
        sem_post(&full);
        sleep(1);
    }
}

void* consumer() {
    while (1) {
        sem_wait(&full);
        printf("Consumed: %d\n", item);
        sem_post(&empty);
        sleep(1);
    }
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}

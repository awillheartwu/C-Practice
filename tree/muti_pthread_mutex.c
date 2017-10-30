#include<stdio.h>
#include<pthread.h>

void *ticketsell1(void *);
void *ticketsell2(void *);
int tickets = 20;
pthread_mutex_t mutex;

int main() {
    pthread_t id1,id2;
    pthread_mutex_init(&mutex,NULL);
    int error;
    error = pthread_create(&id1,NULL,ticketsell1,NULL);
    if(error != 0){
        printf("pthread is not created!\n");
        return -1;
    }
    error = pthread_create(&id2,NULL,ticketsell2,NULL);
    if (error != 0) {
        printf("pthread is not created!\n");
        return -1;
    }
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    return 0;
}

void *ticketsell1(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (tickets > 0) {
            usleep(1000);
            printf("ticketse1 sells tickets:%d\n", tickets--);
            pthread_mutex_unlock(&mutex);
        } else{
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return (void *)0;
}

void *ticketsell2(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (tickets > 0) {
            usleep(2000);
            printf("ticketse2 sells tickets:%d\n", tickets--);
            pthread_mutex_unlock(&mutex);
        } else{
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return (void *)0;
}

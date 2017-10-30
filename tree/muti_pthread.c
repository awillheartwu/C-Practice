#include<stdio.h>
#include<pthread.h>

void *ticketsell1(void *);
void *ticketsell2(void *);
int tickets = 20;
int main() {
    pthread_t id1,id2;
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
    return (void *)0;
}

void *ticketsell1(void *arg) {
    while (1) {
        if (tickets > 0) {
            usleep(1000);
            printf("ticketse1 sells tickets:%d\n", tickets--);
        } else{
            break;
        }
    }
    return (void *)0;
}

void *ticketsell2(void *arg) {
    while (1) {
        if (tickets > 0) {
            usleep(1000);
            printf("ticketse2 sells tickets:%d\n", tickets--);
        } else{
            break;
        }
    }
    return (void *)0;
}

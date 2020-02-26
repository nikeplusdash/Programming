#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

/* Item for storing */
typedef char item;
int pos = 0;

/**
 * n        buffers
 * mutex    Semaphore(1) : mutual exclusivity
 * full     Semaphore(0) : if buffer is full
 * empty    Semaphore(n) : if buffer is empty
 */ 
typedef struct {
    item value;
    item* buffer;
    sem_t mutex;
    sem_t full;
    sem_t empty;
} State;

/**
 * Initialising State S
 * 
 * @param   S   State communicator
 * @param   n   size of buffer
 * @return NULL
 */
void Initialize(State* S,int n)
{
    S->buffer = (item*) malloc(n*sizeof(item));
    sem_init(&S->mutex,1,1);
    sem_init(&S->full,1,0);
    sem_init(&S->empty,1,n);
    S->value='A';
}

/**
 * Produces item for buffer
 * @param   s   void pointer(State)
 * @return      NULL
 */ 
void *Producer(void* s)
{
    State* S = (State*)s;
    usleep(500);
    sem_wait(&S->empty);
    sem_wait(&S->mutex);
        S->buffer[pos++] = S->value;
        printf("\nProduced: [ %c ]",S->value++);
    sem_post(&S->mutex);
    sem_post(&S->full);
    pthread_exit(0);
}

/**
 * Consumes item from buffer
 * @param   s   void pointer (State)
 * @return      NULL
 */ 
void *Consumer(void* s)
{
    State* S = (State*)s;
    usleep(1000);
    item consumed;
    sem_wait(&S->full);
    sem_wait(&S->mutex);
        consumed = S->buffer[--pos];
        printf("\nConsumed: [ %c ]",consumed);
        S->value--;
    sem_post(&S->mutex);
    sem_post(&S->empty);
    pthread_exit(0);
}


int main(int argv,char* argc[])
{
    int i,n = atoi(argc[1]),max = atoi(argc[2]);
    char file[50];
    pthread_t *proc,*cons;
    State S;
    FILE* fp;
    Initialize(&S,n);
    proc = (pthread_t*) malloc(max*sizeof(pthread_t));
    cons = (pthread_t*) malloc(max*sizeof(pthread_t));
    sprintf(file,"output_%d.txt",rand()%25);
    fp = freopen(file,"w+",stdout);
    for(i=0;i<max;i++)
    {
        pthread_create(&proc[i],NULL,Producer,(void*)&S);
        pthread_create(&cons[i],NULL,Consumer,(void*)&S);
    }
    for(i=0;i<max;i++)
    {
        pthread_join(proc[i], NULL);
        pthread_join(cons[i],NULL);
    }
    fclose(fp);
    printf("\n");
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define RIGHT ((i+1)%(n))
#define LEFT ((i+(n)-1)%(n))

char* philosopher_state[3] = {"THINKING\0","HUNGRY\0","EATING\0"};
typedef enum {THINKING,HUNGRY,EATING} states;
int iterations = 0;
int n;
sem_t *self;
sem_t mutex; 
states *state;
void Test(int i)
{
    if(state[LEFT] != EATING && state[RIGHT] != EATING && state[i] == HUNGRY)
    {
        state[i] = EATING;
        // sleep(2);
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[2]);
        sem_post(&self[i]);
    }
}

void Pickup(int i)
{
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[1]);
    Test(i);
    sem_post(&mutex);
    sem_wait(&self[i]);
    // sleep(1);
}

void Putdown(int i)
{
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher[%d] is now %s again\n",i+1,philosopher_state[0]);
    Test(LEFT);
    Test(RIGHT);
    sem_post(&mutex);
}

void Initialize(int max)
{
    int i;
    n = max;
    state = (states*) malloc(max*sizeof(states));
    self = (sem_t*) malloc(max*sizeof(sem_t));
    sem_init(&mutex,0,1);
    for(i=0;i<max;i++) 
    {
        sem_init(&self[i],0,0);
        state[i] = THINKING;
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[0]);
    }
    printf("\n");
}

void *Philosopher(void* x)
{
    int j = iterations;
    while(1)
    {
        int *i=(int*)x;
        // sleep(1);
        Pickup(*i);
        // sleep(0);
        Putdown(*i);
    }
}

int main(int argv,char* argc[])
{
    int heads = atoi(argc[1]),i;
    iterations = atoi(argc[2]);
    char file[50];
    FILE* fp;
    pthread_t *philosopher;
    sprintf(file,"output_%d.txt",rand()%25);
    // fp = freopen(file,"w+",stdout);
    Initialize(heads);
    philosopher = (pthread_t*) malloc(heads*sizeof(pthread_t));
    for(i=0;i<heads;i++)
    {
        pthread_create(&philosopher[i],NULL,Philosopher,(void*)&i);
    }
    for(i=0;i<heads;i++)
    {
        pthread_join(philosopher[i], NULL);
    }
    // fclose(fp);
    printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#define LEFT (i+1)%(M->n)
#define RIGHT (i+(M->n)-1)%(M->n)

char* philosopher_state[3] = {"THINKING\0","HUNGRY\0","EATING\0"};
typedef enum {THINKING,HUNGRY,EATING} states;
int iterations = 0;
typedef struct Monitor
{
    int n;
    pthread_cond_t *self;
    pthread_mutex_t mutex; 
    states *state;
} Monitor;

void Test(Monitor* M,int i)
{
    if(M->state[LEFT] != EATING && M->state[RIGHT] != EATING && M->state[i] == HUNGRY)
    {
        pthread_mutex_lock(&M->mutex);
        M->state[i] = EATING;
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[2]);
        pthread_cond_signal(&M->self[i]);
        pthread_mutex_unlock(&M->mutex);
    }
}

void Pickup(Monitor* M,int i)
{
    M->state[i] = HUNGRY;
    Test(M,i);
    pthread_mutex_lock(&M->mutex);
    while(M->state[i] != EATING){
        pthread_cond_wait(&M->self[i],&M->mutex);
        printf("Philosopher[%d] is still %s\n",i+1,philosopher_state[1]);
    }
    pthread_mutex_unlock(&M->mutex);
}

void Putdown(Monitor* M,int i)
{
    M->state[i] = THINKING;
    printf("Philosopher[%d] is now %s again\n",i+1,philosopher_state[0]);
    Test(M,LEFT);
    Test(M,RIGHT);
}

void Initialize(Monitor* M,int max)
{
    int i;
    M->n = max;
    M->state = (states*) malloc(max*sizeof(states));
    M->self = (pthread_cond_t*) malloc(max*sizeof(pthread_cond_t));
    pthread_mutex_init(&M->mutex,NULL);
    for(i=0;i<max;i++) 
    {
        pthread_cond_init(&M->self[i],NULL);
        M->state[i] = THINKING;
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[0]);
    }
    printf("\n");
}

Monitor M;
void *Philosopher(void* x)
{
    int j = iterations,*i = x;
    while(j--)
    {
        Pickup(&M,*i);
        Putdown(&M,*i);
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
    fp = freopen(file,"w+",stdout);
    Initialize(&M,heads);
    philosopher = (pthread_t*) malloc(heads*sizeof(pthread_t));
    for(i=0;i<heads;i++)
    {
        pthread_create(&philosopher[i],NULL,Philosopher,(void*)&i);
    }
    for(i=0;i<heads;i++)
    {
        pthread_join(philosopher[i], NULL);
    }
    fclose(fp);
    printf("\n");
}

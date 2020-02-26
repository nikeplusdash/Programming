#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#define LEFT (i+1)%this->n
#define RIGHT (i+this->n-1)%this->n

char* philosopher_state[3] = {"THINKING\0","HUNGRY\0","EATING\0"};
typedef enum {THINKING,HUNGRY,EATING} states;
typedef struct Monitor
{
    int n;
    pthread_cond_t *self;
    pthread_mutex_t mutex; 
    states *state;
    void (*Pickup) (struct Monitor*,int i);
    void (*Putdown) (struct Monitor*,int i);
    void (*Test) (struct Monitor*,int i);
} Monitor;

void Up(Monitor* this,int i)
{
    this->state[i] = HUNGRY;
    this->Test(this,i);
    pthread_mutex_lock(&this->mutex);
    while(this->state[i] != EATING){
        pthread_cond_wait(&this->self[i],&this->mutex);
        printf("Philosopher[%d] is still %s\n",i+1,philosopher_state[1]);
    }
    pthread_mutex_unlock(&this->mutex);
}

void Down(Monitor* this,int i)
{
    this->state[i] = THINKING;
    printf("Philosopher[%d] is now %s again\n",i+1,philosopher_state[0]);
    this->Test(this,LEFT);
    this->Test(this,RIGHT);
}

void Testing(Monitor* this,int i)
{
    if(this->state[LEFT] != EATING && this->state[RIGHT] != EATING && this->state[i] == HUNGRY)
    {
        pthread_mutex_lock(&this->mutex);
        this->state[i] = EATING;
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[2]);
        pthread_cond_signal(&this->self[i]);
        pthread_mutex_unlock(&this->mutex);
    }
}

void Initialize(Monitor* M,int max)
{
    int i;
    M->n = max;
    M->Pickup = &Up;
    M->Putdown = &Down;
    M->Test = &Testing;
    M->state = (states*) malloc(max*sizeof(states));
    M->self = (pthread_cond_t*) malloc(max*sizeof(pthread_cond_t));
    pthread_mutex_init(&M->mutex,NULL);
    for(i=0;i<max;i++) 
    {
        pthread_cond_init(&M->self[i],NULL);
        M->state[i] = THINKING;
        printf("Philosopher[%d] is now %s\n",i+1,philosopher_state[0]);
    }
}

Monitor M;
void *Philosopher(void* x)
{
    int j=6,*i = x;
    while(j--)
    {
        M.Pickup(&M,*i);
        // sleep(1);
        M.Putdown(&M,*i);
    }
}

int main(int argv,char* argc[])
{
    int heads = atoi(argc[1]),i;
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

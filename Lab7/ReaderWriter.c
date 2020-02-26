#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

/* Data type for shared data */
typedef char data;

/**
 * secret       shared between writer and reader
 * rw_mutex     Semaphore(1) : mutual exclusivity between reader and writer
 * mutex        Semaphore(1) : mutual exclusivity
 * read_count   number of readers at a time
 */ 
typedef struct 
{
    int n;
    data** secret;
    sem_t rw_mutex;
    sem_t mutex;
    int read_count;
} State;

/* Sample song data for writing*/
char song[11][60] = {{0}};

/**
 * Initializes song variable
 * @return      NULL
 */ 
void SongInit()
{  
    strcpy(song[0],"If you feel insignificant, you better think again\0");
    strcpy(song[1],"Better wake up because you're part of something way bigger\0");
    strcpy(song[2],"You're part of something way bigger\0");
    strcpy(song[3],"Not just a speck in the universe\0");
    strcpy(song[4],"Not just some words in a bible verse\0");
    strcpy(song[5],"You are the living word\0");
    strcpy(song[6],"Ahh, you're part of something way bigger\0");
    strcpy(song[7],"Bigger than you, bigger than we\0");
    strcpy(song[8],"Bigger than the picture they framed us to see\0");
    strcpy(song[9],"But now we see it\0");
    strcpy(song[10],"And it ain't no secret, no\0");
}

/**
 * Initializes State variable
 * @param   S   State
 * @param   n   size of secret data
 * @return      NULL
 */ 
void Initialize(State* S,int max)
{
    int i;
    S->n = 1;
    S->secret = (char**) malloc((max+1)*sizeof(char*));
    for(i=0;i<=max;i++)
        S->secret[i] = (char*) malloc(100*sizeof(char));
    sem_init(&S->rw_mutex,0,1);
    sem_init(&S->mutex,0,1);
    S->read_count = 0;
    strcpy(S->secret[0],"Bigger - Beyonce\0");
}

/**
 * Writes songs to secret
 * @param   s   void pointer(State)
 * @return      NULL
 */ 
void *Writer(void* s)
{
    int i;
    State* S = (State*) s;
    sem_wait(&S->rw_mutex);
        printf("Writer is currently writing...\n");
        strcpy(S->secret[S->n],song[(S->n-1)%11]);
        S->n++;
    sem_post(&S->rw_mutex);
}

/**
 * Reads songs from secret
 * @param   s   void pointer(State)
 * @return      NULL
 */ 
void *Reader(void* s)
{
    int i;
    State* S = (State*) s;
    sem_wait(&S->mutex);
        S->read_count++;
        printf("Reader<%d> is reading...\n",S->read_count);
        if(S->read_count == 1) sem_wait(&S->rw_mutex);
    sem_post(&S->mutex);
    for(i=0;i<S->n;i++)
        printf("\t%s\n",S->secret[i]);
    sem_wait(&S->mutex);
        printf("Reader<%d> is done with reading...\n",S->read_count);
        S->read_count--;
        if(S->read_count == 0) sem_post(&S->rw_mutex);
    sem_post(&S->mutex);
}

int main(int argv,char* argc[])
{
    int readers=atoi(argc[1]),writers=atoi(argc[2]),i,j;
    char file[50];
    pthread_t *read,*write;
    State S;
    FILE* fp;
    Initialize(&S,writers);
    SongInit();
    read = (pthread_t*) malloc(readers*sizeof(pthread_t));
    write = (pthread_t*) malloc(writers*sizeof(pthread_t));
    sprintf(file,"output_%d.txt",rand());
    fp = freopen(file,"w+",stdout);
    i=j=0;
    while(1)
    {
        int stay = 0;
        if(j<writers) {pthread_create(&write[j],NULL,Writer,(void*)&S);j++;stay=1;}
        if(i<readers) {pthread_create(&read[i],NULL,Reader,(void*)&S);i++;stay=1;}
        if(!stay) break;
    }
    i=j=0;
    while(1)
    {
        int stay = 0;
        if(j<writers) {pthread_join(write[j],NULL);j++;stay=1;}
        if(i<readers) {pthread_join(read[i], NULL);i++;stay=1;}
        if(!stay) break;
    }
    Reader((void*)&S);
    fclose(fp);
    printf("\n");   
}
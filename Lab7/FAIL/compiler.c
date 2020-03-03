#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int argv;
char* argc[];
void main(argv,argc)
{
    int i;
    char* c;
    char* command;
    char* masm = "masm.exe ";
    char* link = "link.exe ";
    char* td = "td.exe ";
    printf("%d %s",argv,argc);
    i = atoi(argc);
    strcpy(c,argc[1]);
    printf(command,"%s %s",&masm,&c);
    system(command);
    sprintf(command,"%s %s;",&link,&c);
    system(command);
    if(i)
    {
        sprintf(command,"%s %s",&td,&c);
        system(command);
    }
    else
    {
        sprintf(command,"%s%s",&c,".exe");
        system(command);
    }
    return 0;
}
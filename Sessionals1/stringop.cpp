#include <iostream>
#include <stdlib.h>
#include <bits\stdc++.h>

int strlen(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

char* strcat(char s1[],char s2[]){
    int x=-1;
    char* s = (char*) malloc((strlen(s1)+strlen(s2)-1)*sizeof(char));
    for(int i=0;s1[i]!='\0';i++)    s[++x]=s1[i];
    s[++x]=' ';
    for(int i=0;s2[i]!='\0';i++)    s[++x]=s2[i];
    s[++x]='\0';
    return s;
}

void strcom(char s1[],char s2[]){
    int i=0,a=strlen(s1),b=strlen(s2);
    for(i=0;s1[i]==s2[i]&&i!=a&&i!=b;i++);
    if(i==a&i==b) std::cout << "1=2";
    if(s1[i]>s2[i]) std::cout << "1>2";
    if(s1[i]<s2[i]) std::cout << "1<2";
}

int deepstrsearch(char s1[],char s2[]){
    int a=strlen(s1),b=strlen(s2);
    for(int i=0;i<=a-b;i++){
        if(s1[i]==s2[0]){
            int k = 1;
            while(s1[i+k]==s2[k]&&k<b) k++;
            if(k==b)    return i;
        }
        else {
            while(s1[i]!=' ') i++;
        }
    }
    return -1;
}

int strsearch(char s1[],char s2[]){
    int a=strlen(s1),b=strlen(s2);
    for(int i=0;i<=a-b;i++){
        if(s1[i]==s2[0]){
            int k = 1;
            while(s1[i+k]==s2[k]&&k<b) k++;
            if(k==b&&s1[i+k]==' '||s1[i+k]=='\0')    return i;
        }
        else {
            while(s1[i]!=' ') i++;
        }
    }
    return -1;
}

std::stack<int> strsrh(char s1[],char s2[]){
    int l1=strlen(s1),l2=strlen(s2),d=-1;
    std::stack<int> s;
    for(int i=0;i<=l1-l2;i++){
        if(s1[i]==s2[0]){
            int k=1;
            for(k=1;s1[i+k]==s2[k]&&k<l2;k++);
            if(k==l2&&s1[i+k]==' '||s1[i+k]=='\0')   s.push(i);
            else    i+=k;
        }
        else while(s1[i]!=' ')  i++;
    }
    return s;
}

void display(char s[]){
    for(int i=0;s[i]!='\0';i++)    std::cout << s[i];
    std::cout << std::endl;
}

void strdel(char s1[],char s2[]){
    int l1=strlen(s1),l2=strlen(s2);
    std::stack<int> s = strsrh(s1,s2);
    for (int x; !s.empty(); s.pop())
    {   
        x = s.top();
        if(s1[x+l2] != '\0'){
            for(int i = x;i<=l1-l2;i++){
                s1[i]=s1[i+l2+1];
            }
        }
        else s1[x]='\0';
    }
    display(s1);
}

int main(){
    char s1[] = "Hello friends..";
    char s2[] = "hey boi hey superboyyy boi hey";
    char s3[] = "Hello friends..";
    char s4[] = "hey";
    char* s;

    // std::cout << strlen(s1) << " " << strlen(s2) << std::endl;
    // s = strcat(s1,s2);
    // display(s);
    // strcom(s1,s3);
    // strsrh(s2,s4);
    strdel(s2,s4);
}
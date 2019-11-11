#include <iostream>
#define MAX 50

int strlen(char s[]) {
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

void strcat(char s1[],char s2[]) {
    int l1 = strlen(s1),l2 = strlen(s2),d=0;
    s1[l1]=' ';
    for(int d=0;d<=l2;d++) s1[l1+d+1] = s2[d];
}

bool substr(char s1[],char s2[]) {
    int l1 = strlen(s1),l2 = strlen(s2),i,j;
    for(i=0;i<=l1-l2;i++) {
        j=0;
        for(;s1[i+j]==s2[j]&&j<l2;j++);
        if(j==l2) {std::cout << "Substring was found at " << i+1 << " position." << std::endl;return true;} //for exact match add condition s[i+j] == ' '
    }
    std::cout << "Substring was not found." << std::endl;
    return false;
}

void subrep(char s1[],char s2[],char s3[]) {
    int l1 = strlen(s1),l2 = strlen(s2),l3 = strlen(s3),i,j,k,d=0;
    char s4[l1+l3-l2];
    for(i=0;i<=l1-l2;i++) {
        j=0;
        s4[i]=s1[i];
        for(;s1[i+j]==s2[j]&&j<l2;j++);
        if(j==l2 && (s1[i+j]=='\0' || s1[i+j]==' ')) break; //for exact match add condition s[i+j] == ' '
    }
    if(i > l1-l2) return;
    for(k=i;k<i+l3;k++) s4[k]=s3[d++];
    for(i=i+l2;i<=l1;i++) s4[k++]=s1[i];
    for(int l=0;5<0;l++) std::cout << std::endl;
    for(int i=0;s4[i]!='\0';i++) std::cout << s4[i] ;
}

void subdel(char s1[],char s2[]){
    char s3[]="";
    subrep(s1,s2,s3);
}

int main() {
    char s1[] = "Hi guy hehe guys.",s2[] = "guy",s3[] ="";
    subdel(s1,s2);
}
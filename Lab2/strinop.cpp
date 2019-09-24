#include<iostream>
#include<stdio.h>
#define MAX 50

int strlen(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

void strcat(char a[],char b[]){
    int i=strlen(a),j=strlen(b);
    a[i]=' ';
    int d=-1;
    for(int k=i+1;d<j;k++)  a[k]=b[++d];
    std::cout << "New string: " << a << std::endl;
}

void strcom(char a[],char b[]){
    int i=strlen(a),j=strlen(b),k=0;
    for(k=0;a[k]==b[k]&&k<i&&k<j;k++);
    if(a[k]<b[k]) std::cout << a << " is greater than " << b << std::endl;
    else if(a[k]>b[k]) std::cout << a << " is lesser than " << b << std::endl;
    else std::cout << a << " is equal to " << b << std::endl;
}

void strsub(char a[],char b[],int n){
    int i=strlen(a),j=strlen(b),k,d=-1,e=-1;
    char c[MAX];
    for(k=0;k<i+j;k++){
        if(k==n-1)
            while(b[++e]!='\0') c[k++]=b[e];
        c[k]=a[++d];
    }
    c[k]='\0';
    std::cout << "New string: " << c << std::endl;
}

int strsearch(char a[],char b[]){
    if(strlen(a)<strlen(b)) return -1;
    for(int i=0;i<strlen(a);i++){
        int j=0;
        if(a[i]==b[j]){
            int k = i;
            while(j<strlen(b)&&a[i]==b[j]){
                i++;
                j++;
                //std::cout<<a[i]<<"-"<<b[j]<<"-"<<j<<strlen(b)<<std::endl;
            }
            if(j==strlen(b)||a[i]==' ') return k;
            else i = k;
        }
    }
    return -1;
}

void strdel(char a[],char b[]){
    int n=strsearch(a,b);
    //std::cout<<n<<std::endl;
    if(n!=-1){
        int k;
        if(a[n+strlen(b)]!='\0')
            {for(k=0;k<=strlen(a);k++) a[n+k]=a[n+strlen(b)+1+k];a[k]='\0';}
        else a[n]='\0';
        std::cout << "New String: " << a << std::endl;
    } else std::cout << "Invalid Word" << std::endl;
}

int main(){
    int n;
    char a[MAX],b[MAX];
    std::cout << "Enter string: " << std::endl;
    gets(a);

/*
    std::cout << "Enter string to concatenate: " << std::endl;
    gets(b);
    strcat(a,b);

    std::cout << "Enter string to compare: " << std::endl;
    gets(b);
    strcom(a,b);

    std::cout << "Enter string to be inserted: " << std::endl;
    gets(b);
    std::cout << "Position to be inserted at: " << std::endl;
    std::cin >> n;
    strsub(a,b,n);
*/
    std::cout << "Enter string to be deleted: " << std::endl;
    gets(b);
    strdel(a,b);
}

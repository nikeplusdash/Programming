#include <iostream>
#include<cstdio>

const int MAX = 100;

int len(char str[]){
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}

void special(char str[]){
    int i=0,cont=0,norm=0;
    while(str[i]!='\0'){
        if((str[i]>=48&&str[i]<=57)||(str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)||str[i]==' ')
            norm++;
        else
            cont++;
        i++;
    }
    std::cout << cont << " non characters were found" << std::endl;
}

void palin(char str[]){
    bool palin = 1;
    int i = 0,length = len(str);
    while(i!=int(length/2)){
        if(str[i]!=str[length-i-1]){
            palin=0;
            break;
        }
        i++;
    }
    i=0;
    while(str[i]!='\0'){
        std::cout << str[i];
        i++;
    }
    if(palin){
        std::cout << " is a palindrome" << std::endl;
    } else {
        std::cout << "Is not a palindrome" << std::endl;
    }

}

void toLowUpp(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>=65&&str[i]<=90){
            str[i]+=32;
            i++;
            continue;
        }
        else if(str[i]>=97&&str[i]<=122){
            str[i]-=32;
            i++;
            continue;
        }
        i++;
    }
    i=0;
    while(str[i]!='\0'){
        std::cout << str[i];
        i++;
    }
    std::cout << " is the new string" << std::endl;
}

void notWorkingrep(char str[]){
    char str2[MAX];
    int i=0,j=-1;
    while(str[i]!='\0'){
        if(str[i]==str[i+1]){
            std::cout << "\t" << str2[j] << " " << str[i] << "\n";
            str2[++j]=str[i];
            std::cout << "\t" << str2[j] << " " << str[i] << "\n";
            str2[++j]='*';
            std::cout << "\t" << str2[j] << " " << str[i] << "\n";
            str2[++j]=str[i+1];
            std::cout << "\t" << str2[j] << " " << str[i] << "\n";
        } else {
            str2[++j]=str[i+1];
            std::cout << "\t" << str2[j] << " " << str[i] << "\n";
            i++;
        }
        i++;
    }
    puts(str2);
}

int main(){
    char str[MAX];
    std::cout << len(gets(str)) << " characters are present." << std::endl;
    special(gets(str));
    palin(gets(str));
    toLowUpp(gets(str));
    notWorkingrep(gets(str));
}

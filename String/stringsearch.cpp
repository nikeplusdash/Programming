#include <iostream>
#include <bits\stdc++.h>
#define MAX 100

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len++;
    return len;
}

int deepstrsearch(char str[], char substr[])
{
    int l1 = strlen(str), l2 = strlen(substr);
    for (int i = 0; i <= l1 - l2; i++)
    {
        if (str[i] == substr[0])
        {
            int j = 0;
            for (j = 1; str[i + j] == substr[j] && j < l2; j++)
                ;
            if (j == l2)
                std::cout << "Instance found at:" << i << std::endl;
        }
    }
}

std::stack<int> strsearch(char str[], char substr[])
{
    std::stack<int> s;
    int l1 = strlen(str), l2 = strlen(substr);
    bool f = true;
    for (int i = 0; i <= l1 - l2; i++)
    {
        if ((str[i] == substr[0]) && f)
        {
            int j = 0;
            for (j = 1; str[i + j] == substr[j] && j < l2; j++);
            if (j == l2)    s.push(i);
            else    f = false;
        }
        else
        {
            f = true;
            while (str[i] != ' ') i++;
        }
    }
    return s;
}

int strdel(char str[], char substr[])
{
    int l1 = strlen(str), l2 = strlen(substr);
    std::stack <int> s;
    s = strsearch(str, substr);
    for (int x; !s.empty(); s.pop())
    {   
        x = s.top();
        // std::cout << x <<std::endl;
        if(str[x+l2] != '\0'){
            for(int i = x;i<=l1-l2;i++){
                str[i]=str[i+l2+1];
            }
        }
        else str[x]='\0';
    }
    for(int i = 0;str[i]!='\0';i++){
        std::cout << str[i];
    }
}

int main()
{
    char str[MAX] = "eye eeeyeye eye okeyeu eye ok";
    char substr[MAX] = "ok";
    strdel(str, substr);
}
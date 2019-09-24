#include<iostream>
#include<stdlib.h>
#include<stdio.h>

class Student {
    private:
    char name[50];
    int rollno;
    float grade;
    public:
    void init(Student *s,int n);
    void display(Student *s,int n);
    void sorting(Student *s,int n);
};

void Student::display(Student *s,int n){
    for(int i=0;i<n;i++)
        std::cout << "\nStudent name: " << s[i].name << "\tStudent RollNo: " << s[i].rollno << "\tGrade: " << s[i].grade << std::endl;
}

int swap(Student a[],int j,int k){
    Student temp=a[k];
    a[k]=a[j];
    a[j]=temp;
}

void Student::sorting(Student *s,int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(s[j].rollno>s[j+1].rollno) swap(s,j,j+1);
    std::cout << "\n";
}

void Student::init(Student *s,int n){
    for(int i=0;i<n;i++){
        std::cout <<"Enter name: ";
        std::cin >> s[i].name;
        std::cout <<"Enter roll no: ";
        std::cin >> s[i].rollno;
        std::cout <<"Enter grade: ";
        std::cin >> s[i].grade;

    }
}

int main(){
    Student *s;
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    s = (Student *) malloc(n*sizeof(Student));
    s->init(s,n);
    s->sorting(s,n);
    s->display(s,n);
}

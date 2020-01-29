#include<iostream>
#include<stdlib.h>

class qll {
    private:
    int data;
    qll *point;
    public:
    void push(int n);
    void pop();
    int frontd();
    int backd();
} *back=NULL,*front=NULL;

void qll::push(int n){
    qll *node = new qll();
    node->data = n;
    if(back==NULL)  {back=node;front=node;}
    else {node->point = back;}
    back = node;
}

void qll::pop(){
    qll *prev = new qll();
    qll *curr = new qll();
    curr = back;
    if(curr->point==NULL){std::cout << curr->data << " has been popped." << std::endl;free(curr);back=NULL;front=NULL;return;}
    while(curr->point!=NULL){
        prev = curr;
        curr = prev->point;
        // std::cout << prev->data << " " << curr->data << std::endl;
    }
    prev->point = NULL;
    front = prev;
    std::cout << curr->data << " has been popped." << std::endl;
    free(curr);
}

int qll::backd(){
    if(back!=NULL) {std::cout << back->data << " is at the back." << std::endl;return back->data;} 
}

int qll::frontd(){
    if(front!=NULL) {std::cout << front->data << " is at the front." << std::endl;return front->data;} 
}

int main(){
    qll q;
    q.push(5);
    q.push(7);
    q.push(1);
    q.pop();
    q.pop();
    q.push(10);
    q.push(69);
    q.backd();
    q.pop();
    q.pop();
    q.backd();
    q.pop();
    q.push(1);
    q.pop();
}
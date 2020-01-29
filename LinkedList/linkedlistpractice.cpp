#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* next;
    public:
    void Insert(int);
    void Insert_beginning(int);
    void Insert_recursive(int,Node*);
    void Delete();
    void Delete_first();
    void Delete(int);
    void Display();
    void Display_recursive(Node*);
    void Reverse();
    void Sort();
} *head=NULL;

void Node::Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    Node* curr = head;
    while(curr->next!=NULL) curr = curr->next;
    curr->next=temp;
    return;
}

void Node::Insert_beginning(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return;
}

void Node::Insert_recursive(int x,Node* curr){
    if(curr == NULL) {Insert_beginning(x);return;}
    if(curr->next == NULL){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        curr->next = temp;
        return;
    }
    Insert_recursive(x,curr->next);
    
}

void Node::Delete(){
    if(head==NULL)  return;
    Node* curr = head;
    Node* prev = curr;
    while(curr->next!=NULL) {prev=curr;curr = curr->next;}
    if(head->next==NULL) {head=NULL;free(curr);return;}
    prev->next = NULL;
    free(curr);
    return;
}

void Node::Delete_first(){
    if(head==NULL)  return;
    Node* curr = head;
    head = curr->next;
    free(curr);
    return;
}

void Node::Delete(int x){
    if(head==NULL)  return;
    Node* curr = head;
    Node* prev = curr;
    while(curr!=NULL){
        if(head->data==x){Node* temp = curr;head=curr->next;curr=head;prev=curr;free(temp);}
        else if(curr->data==x){
            Node* temp = curr;
            prev->next = curr->next;
            curr = prev->next;
            free(temp);
            if(prev==NULL) return;
        }
        else {prev = curr;curr = curr->next;}
    }
    return;
}

void Node::Display(){
    if(head==NULL)  return;
    Node* curr = head;
    while(curr!=NULL) {std::cout << curr->data;if(curr->next!=NULL) std::cout << " -> ";curr = curr->next;}
    std::cout << std::endl;
    return;
}

void Node::Display_recursive(Node* curr){
    if(curr==NULL) {std::cout << std::endl;return;}
    std::cout << curr->data;
    if(curr->next!=NULL) std::cout << " -> ";
    Display_recursive(curr->next);
}

void Node::Reverse(){
    if(head==NULL||head->next==NULL) return;
    Node* prev = head;
    Node* curr = head->next;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next==NULL||next->next == NULL) {next = NULL;continue;}
        next = next->next;
    }
    head->next = NULL;
    head = prev;
}

void Node::Sort(){
    Node* i=head;
    while(i!=NULL){
        Node* j=i->next;
        while(j!=NULL){
            if(i->data>j->data){
                int x=i->data;
                i->data=j->data;
                j->data=x;
            }
            j=j->next;
        }
        i=i->next;
    }
}

int main(){
    Node n;
    n.Insert_recursive(5,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(7,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(8,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(5,head);
    n.Insert_recursive(8,head);
    n.Insert_beginning(79);
    // n.Sort();
    n.Display_recursive(head);
    n.Delete(5);
    // n.Display();
    // n.Reverse();
    n.Display();
}
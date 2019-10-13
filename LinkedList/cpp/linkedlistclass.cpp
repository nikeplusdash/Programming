#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* next;
    public:
    Node* Insert(int,Node*);
    Node* Insert_beginning(int,Node*);
    Node* Delete(Node*);
    Node* Delete_first(Node*);
    Node* Delete(int,Node*);
    Node* Display(Node*);
    Node* Reverse(Node*);
    Node* ReverseRecursive(Node*);
};

Node* Node::Insert(int x,Node* head){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    Node* curr = head;
    while(curr->next!=NULL) curr = curr->next;
    curr->next=temp;
    return head;
}

Node* Node::Insert_beginning(int x,Node* head){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

Node* Node::Delete(Node* head){
    if(head==NULL)  return head;
    Node* curr = head;
    Node* prev = curr;
    while(curr->next!=NULL) {prev=curr;curr = curr->next;}
    if(head->next==NULL) {head=NULL;free(curr);return head;}
    prev->next = NULL;
    free(curr);
    return head;
}

Node* Node::Delete_first(Node* head){
    if(head==NULL)  return head;
    Node* curr = head;
    head = curr->next;
    free(curr);
    return head;
}

Node* Node::Delete(int x,Node* head){
    if(head==NULL)  return head;
    Node* curr = head;
    Node* prev = curr;
    while(curr!=NULL){
        if(head->data==x){Node* temp = curr;head=curr->next;curr=head;prev=curr;free(temp);}
        else if(curr->data==x){
            Node* temp = curr;
            prev->next = curr->next;
            curr = prev->next;
            free(temp);
            if(prev==NULL) return head;
        }
        else {prev = curr;curr = curr->next;}
    }
    return head;
}

Node* Node::Display(Node* head){
    if(head==NULL)  return head;
    Node* curr = head;
    while(curr!=NULL) {std::cout << curr->data;if(curr->next!=NULL) std::cout << " -> ";curr = curr->next;}
    std::cout << std::endl;
    return head;
}

Node* Node::Reverse(Node* head){
    if(head==NULL||head->next==NULL) return head;
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

Node* Node::ReverseRecursive(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* rest = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main(){
    Node* head = NULL;
    Node n;
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(7,head);
    head = n.Insert(5,head);
    head = n.Insert(8,head);
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(8,head);
    head = n.Insert_beginning(79,head);
    head = n.Display(head);
    head = n.Delete(5,head);
    head = n.Display(head);
    head = n.ReverseRecursive(head);
    head = n.Display(head);
}
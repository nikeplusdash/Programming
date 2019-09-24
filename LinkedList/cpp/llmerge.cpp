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
    Node* Merge(Node*,Node*);
    Node* Merge_sorted(Node*,Node*);
    Node* Sort(Node*);
    void Display(Node*);
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

Node* Node::Sort(Node* head){
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
    return head;
}

Node* Node::Merge(Node* head,Node* head1){
    Node* x = head;
    Node* y = head1;
    Node* z = NULL;
    int i = -1;
    Display(x);Display(y);
    while(x!=NULL&&y!=NULL){
        if(++i%2==0){
            z = Insert(x->data,z);
            x = x->next;
        }
        else {
            z = Insert(y->data,z);
            y = y->next;
        }
    }
    while(x!=NULL){z=Insert(x->data,z);x=x->next;}
    while(y!=NULL){z=Insert(y->data,z);y=y->next;}
    return z;
}

Node* Node::Merge_sorted(Node* x,Node* y){

}

void Node::Display(Node* head){
    if(head==NULL)  return;
    Node* curr = head;
    while(curr!=NULL) {std::cout << curr->data;if(curr->next!=NULL) std::cout << " -> ";curr = curr->next;}
    std::cout << std::endl;
}

int main(){
    Node* head = NULL;
    Node* head1 = NULL;
    Node n;
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(5,head);
    head = n.Insert(7,head);
    head = n.Insert(5,head);
    head1 = n.Insert(8,head1);
    head = n.Insert(9,head);
    head = n.Insert(19,head);
    head = n.Insert(96,head);
    head1 = n.Insert(5,head1);
    head1 = n.Insert(5,head1);
    head1 = n.Insert(5,head1);
    head = n.Insert(5,head);
    head = n.Insert(8,head);
    head1 = n.Insert_beginning(79,head1);
    // head = n.Display(head);
    head = n.Delete(5,head);
    // n.Display(head);
    // n.Display(head1);
    n.Display(n.Merge(head,head1));
}
#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    Node* Insert(int,Node*);
    Node* Add(Node*,Node*);
    Node* Reverse(Node*);
    void Display(Node*);
};

Node* Node::Insert(int x,Node* head) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(head == NULL) {head=temp;return head;}
    Node* curr = head;
    while(curr->next != NULL) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

void Node::Display(Node* head){
    if(head == NULL) return;
    Node* curr = head;
    std::cout << "Number: ";
    while(curr!=NULL) {
        std::cout << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
    return;
}

Node* Convertify(std::string s) {
    Node* list = NULL;
    for(int i = s.length()-1;i>-1;i--)  list = list->Insert(s[i]-'0',list);
    return list;
}

Node* Node::Add(Node* head1,Node* head2) {
    Node* i = head1;
    Node* j = head2;
    Node* list = NULL;
    int sum = 0,carry = 0;
    while(i != NULL && j != NULL) {
        sum = i->data + j->data;
        if(sum < 10) {
            list = list->Insert(sum+carry,list);
            carry = 0;
        }
        else {
            list = list->Insert(sum-10+carry,list);
            carry = 1;
        }
        i = i->next;
        j = j->next;
    }
    if(i == NULL && j == NULL && carry != 0) list = list->Insert(carry,list);
    while(i != NULL) {list = list->Insert(i->data+carry,list);i = i->next;carry = 0;}
    while(j != NULL) {list = list->Insert(j->data+carry,list);j = j->next;carry = 0;}
    list = list->Reverse(list);
    return list;
}

Node* Node::Reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* curr = head->next;
    head->prev = curr;
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = curr->prev;
        curr->prev = next; 
        if(next == NULL) {head->next = NULL;head = curr;return head;}
        curr = next;
    }
    return head;
}

int main(){
	Node* head1 = NULL;
    Node* head2 = NULL;
    Node* list;
    std::string s1,s2;
    while(1) {
        std::cout<<"Number 1: "<<std::endl;
        std::cin >> s1;
        std::cout<<"Number 2: "<<std::endl;
        std::cin >> s2;
        head1 = Convertify(s1);
        head2 = Convertify(s2);
        list = list->Add(head1,head2);
        list->Display(list);
        int x;
        std::cout << "Continue: ";
        std::cin >> x;
        if(x == 0) return 0;
    }
}
#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    void Insert(int);
    void Delete();
    void Insert_at(int,int);
    void Delete(int);
    void Insert_after(int,int);
    void Insert_before(int,int);
    void Display();
    void Reverse();
} *head = NULL;

void Node::Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(head == NULL) {head=temp;return;}
    Node* curr = head;
    while(curr->next != NULL) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return;
}

void Node::Insert_before(int x,int n) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(head==NULL) return;
    if(head->data == n) {temp->next = head;head->prev = temp;head = temp;return;}
    Node* curr = head;
    while(curr!= NULL && curr->data!=n) curr = curr->next;
    if(curr == NULL) return;
    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;
    return;
}

void Node::Insert_at(int x,int n){
    Node* temp = new Node();
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(head == NULL && n == 1) {head = temp;return;}
    if(head != NULL && n == 1) {temp->next = head;head->prev = temp;head = temp;return;}
    Node* curr = head;
    while(curr != NULL && n > 1) {curr = curr->next;n--;}
    if(curr == NULL) {Insert(x);return;}
    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;
    return;
}

void Node::Insert_after(int x,int n){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL) return;
    Node* curr = head;
    while(curr != NULL && curr->data!=n) curr = curr->next;
    if(curr == NULL) return;
    temp->next = curr->next;
    temp->prev = curr;
    if(curr->next != NULL) curr->next->prev=temp;
    curr->next = temp;
    return;
}

void Node::Display(){
    if(head == NULL) return;
    Node* curr = head;
    while(curr!=NULL) {
        std::cout << curr->data;
        if(curr->next != NULL) std::cout << " <-> ";
        curr = curr->next;
    }
    std::cout << std::endl;
    return;
}

void Node::Delete(){
    if(head==NULL)  return;
    if(head->next == NULL) {Node* temp = head;head = NULL;free(temp);return;}
    Node* curr = head;
    while(curr->next!=NULL) curr = curr->next;
    curr->prev->next = NULL;
    free(curr);
    return;
}

void Node::Delete(int n){
    if(head==NULL)  return;
    if(n == 1) {Node* temp = head;head = temp->next;free(temp);return;}
    Node* curr = head;
    while(curr != NULL && n > 1) {curr = curr->next;n--;}
    if(curr == NULL) return;
    curr->prev->next = curr->next;
    if(curr->next != NULL) curr->next->prev = curr->prev;
    free(curr);
    return;
}

void Node::Reverse(){
    if(head == NULL || head->next == NULL) return;
    Node* curr = head->next;
    head->prev = curr;
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = curr->prev;
        curr->prev = next; 
        if(next == NULL) {head->next = NULL;head = curr;return;}
        curr = next;
    }
}

int main(){
	Node list;
    std::cout<<"\n0:Insert at\n1:Insert n\n2:Insert before x\n3:Insert after x\n4:Delete at\n5:Delete\n7:Display\n6:Reverse\n7:Display\n"<<std::endl;
	while(1){
		int ip,x,n;
		std::cin>>ip;
		switch(ip){
            case 0: 
                std::cin >> x >> n;
                list.Insert_at(x,n);
                break;
			case 1: 
                std::cin >> x;
                list.Insert(x);
                break;
            case 2:
                std::cin >> x >> n;
                list.Insert_before(x,n);
                break;
            case 3:
                std::cin >> x >> n;
                list.Insert_after(x,n);
                break;
            case 4:
                std::cin >> x;
                list.Delete(x);
                break;
            case 5:
                list.Delete();
                break;
            case 6:
                list.Reverse();
                break;
            case 7:
                list.Display();
                break;
            default:
                return 0;
		}
	}
}
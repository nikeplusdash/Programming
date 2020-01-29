#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    void Insert(int);
    void Delete(int);
    void Delete();
    void Insert_beg(int);
    void Delete_beg();
    void Display();
} *head = NULL;

void Node::Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = temp->next = NULL;
    if(head == NULL) {head=temp;return;}
    Node* curr = head;
    while(curr->next != NULL) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return;
}

void Node::Insert_beg(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = temp->next = NULL;
    if(head == NULL) {head=temp;return;}
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}

void Node::Display() {
    Node* curr = head;
    while(curr != NULL) {
        std::cout << curr->data;
        if(curr->next != NULL) std::cout << " <-> ";
        curr = curr->next;
    }
    std::cout << std::endl;
    return;
}

void Node::Delete() {
    if(head == NULL) return;
    Node* curr = head;
    if(head->next == NULL) {head = NULL;free(curr);return;}
    while(curr->next != NULL) curr = curr->next;
    curr->prev->next = NULL;
    free(curr);
}

void Node::Delete(int x) {
    Node* curr = head;
    Node* prev = curr;
    if(head == NULL) return;
    while(curr != NULL) {
        if(head->data == x) {head = head->next;free(curr);}
        else if(curr->data == x) {
            Node* temp = curr;
            if(curr->next == NULL) {free(curr);return;}
            curr = curr->next;
            free(temp);
            continue;
        }
        else {prev->next = curr;curr->prev = prev;prev = curr;curr = curr->next;}
    }
}

void Node::Delete_beg() {
    if(head == NULL) return;
    Node* curr = head;
    if(head->next == NULL) {head = NULL;free(curr);return;}
    head = head->next;
    head->prev = NULL;
    free(curr);
}

int main(){
    Node list;
	while(1){
		int ip,x,n;
		std::cout<<"\n1:Insert n\n2:Insert beg x\n3:Delete\n4:Delete x\n5:Delete beg\n6:Display\n"<<std::endl;
		std::cin>>ip;
		switch(ip){
			case 1: 
                std::cin >> x;
                list.Insert(x);
                break;
            case 2:
                std::cin >> x;
                list.Insert_beg(x);
                break;
            case 3:
                list.Delete();
                break;
            case 4:
                std::cin >> x;
                list.Delete(x);
                break;
            case 5:
                list.Delete_beg();
                break;
            case 6:
                list.Display();
                break;
            default:
                return 0;
		}
	}
}
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
    temp->prev = temp->next = temp;
    if(head == NULL) {head=temp;return;}
    Node* curr = head;
    while(curr->next != head) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    temp->next = head;
    head->prev = temp;
    return;
}

void Node::Insert_beg(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = temp->next = temp;
    if(head == NULL) {head=temp;return;}
    temp->prev = head->prev;
    temp->next = head;
    temp->prev->next = temp;
    head->prev = temp;
    head = temp;
    return;
}

void Node::Display() {
    if(head == NULL) return;
    Node* curr = head;
    do {
        std::cout << curr->data;
        if(curr->next != head) std::cout << " <-> ";
        curr = curr->next;
    } while(curr != head); 
    std::cout << std::endl;
    return;
}

void Node::Delete() {
    if(head == NULL) return;
    Node* curr = head->prev;
    if(curr == head) {head = NULL;free(curr);return;}
    head->prev = curr->prev;
    curr->prev->next = head;
    free(curr);
}

void Node::Delete(int x) {
    if(head == NULL) return;
    Node* curr = head;
    Node* prev = curr;
    do {
        if(head->data == x) {Node* temp = curr;Node* temp1 = head->prev;Node* temp2 = head->next;temp1->next = temp2;temp2->prev = temp1;head = temp2;curr = head;prev = curr;free(temp);}
        else if(curr->data == x) {
            Node* temp = curr;
            if(curr->next == head) {head->prev = prev;curr->prev->next = head;free(curr);return;}
            curr->next->prev = prev;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
            continue;
        }
        else {prev = curr;curr = curr->next;}
    }  while(curr != head); 
}

void Node::Delete_beg() {
    if(head == NULL) return;
    Node* curr = head;
    if(head->next == head) {head = NULL;free(curr);return;}
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
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
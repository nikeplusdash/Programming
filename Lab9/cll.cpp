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
    void Display();
} *head = NULL;

void Node::Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = temp->prev = NULL;
    if(head == NULL) {head = temp;head->next = head->prev = head;return;}
    Node* curr = head;
    while(curr->next != head) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    temp->next = head;
    head->prev = temp;
    return;
}

void Node::Display(){
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

void Node::Delete(int n){
    if(head==NULL)  return;
    Node* curr = head;
    do {
        if(head->data == n) {Node* temp = head;head = temp->next;head->prev = temp->prev;temp->prev->next = head;curr = head->next;free(temp);}
        else if(curr->next == head && curr->data == n) {
            curr->prev->next = head;
            head->prev = curr->prev;
            free(curr);
            return;
        }
        else if(curr->data == n) {
            Node* temp = curr;
            curr = curr->next;
            temp->prev->next = curr;
            curr->prev = temp->prev;
            free(temp);
        }
        else {curr = curr->next;}
    } while(curr != head);
    return;
}

int main(){
	Node list;
    std::cout<<"\n1:Insert n\n2:Delete\n3:Display\nHAHA"<<std::endl;
	while(1){
		int ip,x,n;
		std::cin>>ip;
		switch(ip){
			case 1: 
                std::cin >> x;
                list.Insert(x);
                break;
            case 2:
                std::cin >> x;
                list.Delete(x);
                break;
            case 3:
                list.Display();
                break;
            default:
                return 0;
		}
	}
}
#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    Node* Insert(int,Node*);
    void Display(Node*);
    Node* Concat(Node*,Node*);
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
    while(curr!=NULL) {
        std::cout << curr->data;
        if(curr->next != NULL) std::cout << " <-> ";
        curr = curr->next;
    }
    std::cout << std::endl;
    return;
}

Node* Node::Concat(Node* head1,Node* head2) {
    Node* last1 = head1;
    while(last1->next != NULL) last1 = last1->next;
    last1->next = head2;
    head2->prev = last1;
    return head1;
}

int main(){
	Node list;
    Node* head1 = NULL;
    Node* head2 = NULL;
    std::cout<<"\n1:Insert\n2:Display\n3:Concat"<<std::endl;
	while(1){
		int ip,x,n;
		std::cin>>ip;
		switch(ip){
			case 1: 
                std::cin >> x >> n;
                n==1 ? head1 = list.Insert(x,head1) : head2 = list.Insert(x,head2);
                break;
            case 2:
                std::cin >> n;
                n==1 ? list.Display(head1) : list.Display(head2);
                break;
            case 3:
                head1 = list.Concat(head1,head2);
                head2 = NULL;
                break;
            default:
                return 0;
		}
	}
}
#include <iostream>
#include <stdlib.h>

class Node {
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    Node* Insert(int,Node*);
    Node* Copy(Node*);
    void Display(Node*);
    Node* Concat(Node*,Node*);
    void Union(Node*,Node*);
    void Intersect(Node*,Node*);
    Node* Sort(Node*);
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

Node* Node::Copy(Node* head) {
    Node* list = NULL;
    Node* curr = head;
    while(curr != NULL) {list = curr->Insert(curr->data,list);curr = curr->next;}
    return list;
}

void Node::Display(Node* head) {
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

Node* Node::Sort(Node* head) {
    Node* x = Copy(head);
    Node* i = x;
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
    return x;
}

Node* Node::Concat(Node* head1,Node* head2) {
    Node* last1 = head1;
    while(last1->next != NULL) last1 = last1->next;
    last1->next = head2;
    head2->prev = last1;
    return head1;
}

void Node::Union(Node* head1,Node* head2) {
    Node* i = Sort(head1);
    Node* j = Sort(head2);
    Node* list = NULL;
    while(i != NULL && j != NULL) {
        if(i->data > j->data) {
            Node* trav = list;
            while(trav != NULL && trav->data != j->data) trav = trav->next;
            if(trav != NULL) {j = j->next;continue;}
            list = list->Insert(j->data,list);
            j = j->next;
        }
        else if(i->data < j->data) {
            Node* trav = list;
            while(trav != NULL && trav->data != i->data) trav = trav->next;
            if(trav != NULL) {i = i->next;continue;}
            list = list->Insert(i->data,list);
            i = i->next;   
        }
        else {
            Node* trav = list;
            while(trav != NULL && trav->data != j->data) trav = trav->next;
            if(trav != NULL) {i = i->next;j = j->next;continue;}
            list = list->Insert(i->data,list);
            i = i->next;
            j = j->next;
        }
    }
    while(i != NULL) {
        Node* trav = list;
        while(trav != NULL && trav->data != i->data) trav = trav->next;
        if(trav != NULL) {i = i->next;continue;}
        list = list->Insert(i->data,list);i = i->next;
    }
    while(j != NULL) {
        Node* trav = list;
        while(trav != NULL && trav->data != j->data) trav = trav->next;
        if(trav != NULL) {j = j->next;continue;}
        list = list->Insert(j->data,list);
        j = j->next;
    }
    Display(list);
    return;
}

void Node::Intersect(Node* head1,Node*head2) {
    Node* i = Sort(head1);
    Node* j = Sort(head2);
    Node* list = NULL;
    while(i != NULL && j != NULL) {
        if(i->data > j->data) {
            j = j->next;
        }
        else if(i->data < j->data) {
            i = i->next;   
        }
        else {
            Node* trav = list;
            while(trav != NULL && trav->data != j->data) trav = trav->next;
            if(trav != NULL) {i = i->next;j = j->next;continue;}
            list = list->Insert(i->data,list);
            i = i->next;
            j = j->next;
        }
    }
    Display(list);
    return;
}

int main(){
	Node list;
    Node* head1 = NULL;
    Node* head2 = NULL;
    std::cout<<"\n1:Insert\n2:Display\n3:Concat\n4:Copy from x to y\n5:Union\n6:Intersect\n"<<std::endl;
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
            case 4:
                std::cin >> x >> n;
                x==1?n==1?head1 = list.Copy(head1):head2 = list.Copy(head1):n==1?head1 = list.Copy(head2):head2 = list.Copy(head2);
                break;
            case 5:
                list.Union(head1,head2);
                break;
            case 6:
                list.Intersect(head1,head2);
                break;
            default:
                return 0;
		}
	}
}
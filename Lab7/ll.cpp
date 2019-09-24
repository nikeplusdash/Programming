#include<iostream>

class Node {
	public:
	int data;
	Node* next;
};

Node* head;

class ll {
	public:
	void insert(int x){
		Node* temp = new Node();
		temp->data=x;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			return;
		}
		Node* curr = head;
		while(curr->next!=NULL) curr=curr->next;
		curr->next=temp;
		return;
	}

	void insert_sorted(int n){
		Node* curr = head;
		Node* prev = curr;
		Node* temp = new Node();
		temp->data=n;
		temp->next=NULL;
		while(curr->data<n&&curr->next!=NULL){prev=curr;curr=curr->next;}
		if(curr->next==NULL){curr->next=temp;return;}
		temp->next=prev->next;
		prev->next=temp;
	}

	void insert_before(int x,int n){
		Node* temp = new Node();
		temp->data=x;
		temp->next=NULL;
		if(head->data==n){
			temp->next=head;
			head=temp;
			std::cout << head;
			return;
		}
		Node* curr = head;Node* prev=head;
		while(curr->data!=n&&curr!=NULL){
			prev=curr;
			curr=curr->next;
		}
		if(curr==NULL) return;
		temp->next=curr;
		prev->next=temp;
	}

	void insert_after(int x,int n){
		Node* temp = new Node();
		temp->data=x;
		temp->next=NULL;
		Node* curr = head;
		while(curr->data!=n&&curr!=NULL) {curr=curr->next;}
		if(curr==NULL){return;}
		temp->next=curr->next;
		curr->next=temp;
	}

	void del_alt(){
		Node* curr = new Node();Node* prev=head;
		int i=0;
		curr = head;
		while(curr!=NULL){
			if(++i%2==0)	prev->next=curr->next;
			prev=curr;
			curr=curr->next;
		}
		delete(curr);
	}

	void delete_ll(int n){
		Node* curr = new Node();Node* prev=head;
		curr = head;
		while(curr!=NULL){
			if(curr->data==n) prev->next=curr->next;
			prev=curr;
			curr=curr->next;
		}
		if(curr==NULL)return;
		
		delete(curr);
	}

	void traverse(){
		Node* curr = head;
		while(curr!=NULL) {std::cout<< curr->data << " "; curr=curr->next;}
		std::cout << std::endl;
	}

	void reverse(){
		ll list;
		Node* curr = head;
		Node* temp =curr->next;
		while(temp!=NULL) {
			Node* next = temp->next;		
			temp->next = curr;
			curr = temp;
			temp = next;
		}
		head->next=NULL;
		head=curr;
	}

	void sort(){
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
};

int main(){
	ll linkedlist;
	linkedlist.insert(4);linkedlist.traverse();
	linkedlist.insert_after(7,4);linkedlist.traverse();
	linkedlist.insert_before(2,7);linkedlist.traverse();
	linkedlist.insert(4);linkedlist.traverse();
	linkedlist.insert_after(7,4);linkedlist.traverse();
	linkedlist.insert_before(2,7);linkedlist.traverse();
	// linkedlist.delete_ll(2);linkedlist.traverse();
	linkedlist.reverse();
	linkedlist.sort();
	linkedlist.traverse();
	// linkedlist.del_alt();
	linkedlist.insert_sorted(9);
	linkedlist.insert_sorted(5);
	linkedlist.traverse();
}

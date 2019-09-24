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
		if(curr->data>n){temp->next=head;head=temp;return;}
		while(curr->data<n&&curr->next!=NULL){prev=curr;curr=curr->next;}
		if(curr->next==NULL&&curr->data<n){curr->next=temp;return;}
		temp->next=prev->next;
		prev->next=temp;
	}

	void insert_before(int x,int n){
		Node* temp = new Node();
		temp->data=x;
		temp->next=NULL;
		if(head==NULL) return;
		if(head->data==n){
			temp->next=head;
			head=temp;
			return;
		}
		Node* curr = head;Node* prev=head;
		while(curr!=NULL&&curr->data!=n){
			prev=curr;
			curr=curr->next;
		}
		if(curr==NULL) return;
		temp->next=curr;
		prev->next=temp;
	}

	void insert_after(int x,int n){
		Node* temp = new Node();
		if(head==NULL) return;
		temp->data=x;
		temp->next=NULL;
		Node* curr = head;
		while(curr!=NULL&&curr->data!=n) {curr=curr->next;}
		if(curr==NULL){return;}
		temp->next=curr->next;
		curr->next=temp;
	}

	void del_alt(){
		Node* curr = new Node();Node* prev=head;
		curr = head->next;
		while(curr!=NULL){
            Node* temp = curr;
			prev->next=curr->next;
            delete(temp);
			prev=prev->next;
			if(prev==NULL) return;
			curr=prev->next;
		}
	}

	void delete_ll(int x){
		if(head==NULL)  return;
		Node* curr = head;
		Node* prev = curr;
		while(curr!=NULL){
			if(head->data==x){Node* temp = curr;head=curr->next;curr=head;prev=curr;delete(temp);}
			else if(curr->data==x){
				Node* temp = curr;
				prev->next = curr->next;
				curr = prev->next;
				delete(temp);
				if(prev==NULL) return;
			}
			else {prev = curr;curr = curr->next;}
		}
		return;
	}

	void traverse(){
		if(head==NULL)  return;
		Node* curr = head;
		while(curr!=NULL) {std::cout << curr->data;if(curr->next!=NULL) std::cout << " -> ";curr = curr->next;}
		std::cout << std::endl;
		return;
	}

    void Reverse(){
        if(head==NULL||head->next==NULL) return;
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = NULL;
        head = prev;
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
	ll list;
	while(1){
		int ip,x,n;
		std::cout<<"\n1:Insert n\n2:Insert before x\n3:Insert after x\n4:Delete n\n5:Display\n6:Reverse\n7:Sort\n8:Delete alternate\n9:Insert Sorted\n"<<std::endl;
		std::cin>>ip;
		switch(ip){
			case 1: 
                std::cin >> x;
                list.insert(x);
                break;
            case 2:
                std::cin >> x >> n;
                list.insert_before(x,n);
                break;
            case 3:
                std::cin >> x >> n;
                list.insert_after(x,n);
                break;
            case 4:
                std::cin >> x;
                list.delete_ll(x);
                break;
            case 5:
                list.traverse();
                break;
            case 6:
                list.Reverse();
                break;
            case 7:
                list.sort();
                break;
            case 8:
                list.del_alt();
                break;
            case 9:
                std::cin>>x;
                list.insert_sorted(x);
                break;
            default:
                return 0;
		}
	}
}

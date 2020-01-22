#include <iostream>

template <class T>
class LinkedLists {
    private:
    LinkedLists* head;
    public:
    T data;
    LinkedLists* next;
    public:
    LinkedLists(){head = NULL;}
    LinkedLists(T x) {data = x;next = NULL;}
    LinkedLists* getHead() {return head;}
    void Clear(){
        while(head){
            LinkedLists* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
    void Insert(T x) {
        LinkedLists* temp = new LinkedLists(x);
        LinkedLists* curr = head;
        if(!head) {head = temp;
        // std::cout << x << " was inserted in the list." << std::endl;
        return;}
        while(curr->next) {curr = curr->next;}
        curr->next = temp;
        // std::cout << x << " was inserted in the list." << std::endl;
    }
    void InsertAt(T x,int pos) {
        LinkedLists* temp = new LinkedLists(x),*curr = head,*prev = curr;
        int apos = pos--;
        if(!pos && !head) {head = temp;return;}
        if(!pos) {temp->next = head;head = temp;return;}
        while(pos && curr) {prev = curr;curr = curr->next;pos--;}
        prev->next = temp;
        temp->next = curr;
        // std::cout << x << " was inserted at " << apos << " in the list." << std::endl;
    }
    bool Search(T x) {
        if(!head) return 0;
        LinkedLists* curr = head;
        while(curr) {
            if(curr->data == x) {
                // std::cout << x << " was found." << std::endl;
                return 1;}
            curr = curr->next;
        }
        // std::cout << x << " was not found." << std::endl;
        return 0;
    }
    void Display() {
        if(!head) {
            std::cout << "Empty List" << std::endl;
            return;
        }
        std::cout << "List: ";
        LinkedLists* curr = head;
        while(curr) {
            std::cout << curr->data;
            if(curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void Display(T i) {
        if(!head) {
            std::cout << "Vertex <V" << i << ">: Empty" << std::endl ;
            return;
        }
        std::cout << "Vertex <V" << i << ">: " ;
        LinkedLists* curr = head;
        while(curr) {
            std::cout << curr->data;
            if(curr->next) std::cout << " - ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void Delete( T x) {
        if(!head) return ;
        LinkedLists* curr = head,*prev = curr;
        while(curr) {
            if(head->data == x) {LinkedLists* temp = head;head = head->next;curr=head;delete temp;}
            else if(curr->data == x) {
                LinkedLists* temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            }
            else {prev = curr;curr = curr->next;}
        }
        // std::cout << x << " was deleted from the list." << std::endl;
    }
};
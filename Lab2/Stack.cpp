#include <iostream>

template <class T>
class Stacks {
    private:
    Stacks* head;
    protected:
    T data;
    Stacks* next;
    public:
    Stacks(){head = NULL;}
    Stacks(T x) {data = x;next = NULL;}
    void Push(T x) {
        Stacks* temp = new Stacks(x);
        if(!head) {
            head = temp;
            // std::cout << x << " was pushed to the stack." << std::endl;
            return;
        }
        temp->next = head;
        head = temp;
        // std::cout << x << " was pushed to the stack." << std::endl;
    }
    void Display() {
        if(!head) {std::cout << "Empty Stack" << std::endl;return;}
        std::cout << "Stack: ";
        Stacks* curr = head;
        while(curr) {
            std::cout << curr->data;
            if(curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void Pop() {
        if(!head) return;
        Stacks* temp = head;
        head = head->next;
        // std::cout << temp->data << " was popped from the stack." << std::endl;
        delete temp;
    }
};
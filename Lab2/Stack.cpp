#include <iostream>

template <class T>
class Stacks {
    private:
    Stacks* head;
    public:
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
    T Pop() {
        if(Empty()) return T();
        Stacks* temp = head;
        if(head->next) head = head->next;
        else head = NULL;
        T x = temp->data;
        // std::cout << temp->data << " was popped from the stack." << std::endl;
        delete temp;
        return x;
    }
    bool Contains(T x) {
        if(!head) return 0;
        Stacks* curr = head;
        while(curr) {
            if(curr->data == x) {
                // std::cout << x << " was found." << std::endl;
                return 1;}
            curr = curr->next;
        }
        // std::cout << x << " was not found." << std::endl;
        return 0;
    }
    bool Empty() {
        return !head;
    }
    T Top() {
        return head->data;
    }
};
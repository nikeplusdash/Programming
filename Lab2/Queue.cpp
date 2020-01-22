#include <iostream>

template <class T>
class Queue {
    private:
    Queue* front;
    Queue* tail;
    public:
    T data;
    Queue* next;
    public:
    Queue(){front= tail = NULL;}
    Queue(T x) {data = x;next = NULL;}
    void Enqueue(T x) {
        Queue* temp = new Queue(x);
        if(!front) {
            front = tail = temp;
            // std::cout << x << " was added to the queue." << std::endl;
            return;
        }
        tail->next = temp;
        tail = temp;
        // std::cout << x << " was added to the queue." << std::endl;
    }
    void Display() {
        if(!front) {
            std::cout << "Empty queue" << std::endl;
            return;
        }
        std::cout << "Queue: ";
        Queue* curr = front;
        while(curr) {
            std::cout << curr->data;
            if(curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    T Dequeue() {
        if(Empty()) return T();
        Queue* temp = front;
        T x = temp->data;
        if(front == tail) {
            front = tail = NULL;
            // std::cout << temp->data << " was removed from the queue." << std::endl;
            delete temp;
            return x;
        }
        front = front->next;
        // std::cout << temp->data << " was removed from the queue." << std::endl;
        delete temp;
        return x;
    }
    bool Contains(T x) {
        if(!front) return 0;
        Queue* curr = front;
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
        return !front;
    }
    T Front(){
        return front->data;
    }
    T Back(){
        return tail->data;
    }
};
#include <iostream>

template <class T>
class Queue {
    private:
    Queue* front;
    Queue* tail;
    protected:
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
    void Dequeue() {
        if(!front) return;
        Queue* temp = front;
        if(front == tail) {
            front = tail = NULL;
            // std::cout << temp->data << " was removed from the queue." << std::endl;
            delete temp;
            return;
        }
        front = front->next;
        // std::cout << temp->data << " was removed from the queue." << std::endl;
        delete temp;
    }
};
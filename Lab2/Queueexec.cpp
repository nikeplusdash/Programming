#include "./Queue.cpp"

int main() {
    Queue<char> ref;
    char v1;
    int v;
    std::cout << "1:Enqueue 2:Dequeue 3:Display" << std::endl;
    while(true) {
        std::cin >> v;
        switch(v) {
            case 1:
            std::cin >> v1;
            ref.Enqueue(v1);
            break;
            case 2:
            ref.Dequeue();
            break;
            case 3:
            ref.Display();
            break;
            default:
            return 0;
        }
    }
};
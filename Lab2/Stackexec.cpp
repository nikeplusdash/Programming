#include "./Stack.cpp"

int main() {
    Stacks<char> ref;
    char v1;
    int v;
    std::cout << "1:Push 2:Pop 3:Display" << std::endl;
    while(true) {
        std::cin >> v;
        switch(v) {
            case 1:
            std::cin >> v1;
            ref.Push(v1);
            break;
            case 2:
            ref.Pop();
            break;
            case 3:
            ref.Display();
            break;
            default:
            return 0;
        }
    }
};
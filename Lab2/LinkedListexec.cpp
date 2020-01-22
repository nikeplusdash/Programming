#include "./LinkedList.cpp"

int main() {
    LinkedLists<char> ref;
    char v1;
    int v;
    std::cout << "1:Insert 2:InsertAt 3:Search 4:Delete 5:Display" << std::endl;
    while(true) {
        std::cin >> v;
        switch(v) {
            case 1:
            std::cin >> v1;
            ref.Insert(v1);
            break;
            case 2:
            std::cin >> v1 >> v;
            ref.InsertAt(v1,v);
            break;
            case 3:
            std::cin >> v1;
            ref.Search(v1);
            break;
            case 4:
            std::cin >> v1;
            ref.Delete(v1);
            break;
            case 5:
            ref.Display();
            break;
            default:
            return 0;
        }
    }
};
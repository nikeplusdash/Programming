#include <iostream>
#include <bits\stdc++.h>

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

Node* Create() {
    Node* p;
    int x;
    std::cin >> x;
    if(x == -1) return NULL;
    p = new Node();
    p->data = x;
    std::cout << "Enter left child: " ; p->left = Create();
    std::cout << "Enter right child: " ; p->right = Create();
    return p;
}

Node* Copy(Node* head) {
    Node* p = new Node();
    p->data = head->data;
    if(head->left) p->left = Copy(head->left);
    if(head->right) p->right = Copy(head->right);
    return p;
}

bool Check(Node* head1,Node* head2) {
    if(head1 == NULL && head2 == NULL) return true;
    else if(head1 && head2) return head1->data == head2->data && Check(head1->left,head2->left) && Check(head1->right,head2->right);
    else return false;
}

void PostorderRecursive(Node* head) {
    if(head){
        PostorderRecursive(head->left);
        PostorderRecursive(head->right);
        std::cout << head->data << " ";
    }
}

void PreorderIterative(Node* head) {
    std::stack <Node*> s;
    s.push(head);
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
        std::cout << curr->data << " ";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
    std::cout << std::endl;
}

int main(){
    Node* node = Create();
    Node* copied = new Node();
    copied = Copy(node);
    Check(node,copied)? std::cout<< "Tree is same" : std::cout <<"Tree is not same";
}

// 5 10 2 6 -1 -1 -1 3 -1 -1 11 4 -1 -1 1 -1 -1
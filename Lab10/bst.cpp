#include <iostream>
#include <bits\stdc++.h>

class Node {
	private:
	int data;
	Node* left;
	Node* right;
	public:
	Node* Init();
	void InorderIterative(Node*);
	void PreorderIterative(Node*);
	// void PostorderIterative(Node*);
	int Count(Node*);
	Node* Copy(Node*);
	bool Check(Node*,Node*);
	void Parent(Node*,int);
	void Depth(Node*);
};

Node* Node::Init() {
    Node* p;
    int x;
    std::cin >> x;
    if(x == -1) return NULL;
    p = new Node();
    p->data = x;
    std::cout << "Enter left child of " << p->data << ": " << std::endl; p->left = Init();
    std::cout << "Enter right child of " << p->data << ": " << std::endl; p->right = Init();
    return p;
}

void Node::InorderIterative(Node* head) {
	if(head == NULL) return;
	std::stack<Node*> s;
	Node* curr = head;
	while(1) {
		for(;curr;curr = curr->left) s.push(curr);
		if(curr == NULL) break;
		curr = s.top();
		s.pop();
		std::cout << curr->data << " ";
		curr = curr->right;
	}
	std::cout << std::endl;
}

void Node::PreorderIterative(Node* head) {
	if(head == NULL) return;
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

// void Node::PostorderIterative(Node* head) {
// 	if(head == NULL) return;
//     std::stack <Node*> s;
//     s.push(head);
//     while(!s.empty()) {
//         Node* curr = s.top();
// 		s.push(curr->right);
// 		s.push(curr->left);
//         s.pop();
//         std::cout << curr->data << " ";
//         if(curr->right) s.push(curr->right);
//         if(curr->left) s.push(curr->left);
//     }
//     std::cout << std::endl;
// }

int Node::Count(Node* head) {
	static int nodes = 1;
	if(head) return 1+Count(head->left)+Count(head->right);
	else return 0;;
}

Node* Node::Copy(Node* head) {
    Node* p = new Node();
    p->data = head->data;
    if(head->left) p->left = Copy(head->left);
    if(head->right) p->right = Copy(head->right);
    return p;
}

bool Node::Check(Node* head1,Node* head2) {
    if(head1 == NULL && head2 == NULL) return true;
    else if(head1 && head2) return head1->data == head2->data && Check(head1->left,head2->left) && Check(head1->right,head2->right);
    else return false;
}

void Node::Parent(Node* head, int x) {
	if(head == NULL) return;
    std::stack <Node*> s;
    s.push(head);
	if(head->data == x) {std::cout << "This is the root" << std::endl;return;}
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
		if(curr->left || curr->right) if(curr->left->data == x || curr->right->data == x) {std::cout << "Parent: " << curr-> data << std::endl;return;}
    }
	std::cout << "Parent: Not found" << std::endl;
	return;
}

void Node::Depth(Node* head) {
	if(head == NULL) return;
    std::stack <Node*> s;
	static int depth = 1;
    s.push(head);
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
		if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
	return;
}


int main() {
	Node ref;
	Node* node;
	int search;
	node = ref.Init();
	ref.InorderIterative(node);
	std::cout << "Number of Nodes: " << ref.Count(node) << std::endl;
	std::cin >> search;
	ref.Parent(node,search);
}
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
	void PostorderIterative(Node*);
	void Inorder(Node*);
	void Preorder(Node*);
	void Postorder(Node*);
	int Count(Node*);
	int Leaf(Node*);
	Node* Copy(Node*);
	bool Check(Node*,Node*);
	bool Mirror(Node*,Node*);
	void Parent(Node*,int);
	void Ancestors(Node*,int);
	int Depth(Node*);
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
	while(curr || !s.empty()) {
		while(curr) {s.push(curr);curr = curr->left;}
		if(s.empty()) break;
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

void Node::PostorderIterative(Node* head) {
	if(head == NULL) return;
    std::stack <Node*> s;
	Node* curr = head;
    do {
		while(curr) {
			if(curr->right) s.push(curr->right);
			s.push(curr);
			curr = curr->left;
		}
		
		curr = s.top();
		s.pop();
		if(curr->right && !s.empty() && s.top() == curr->right) {s.pop();s.push(curr);curr = curr->right;}
        else {std::cout << curr->data << " ";curr = NULL;}
    } while(!s.empty());
    std::cout << std::endl;
}

void Node::Inorder(Node* head) {
	if(head->left) Inorder(head->left);
	std::cout << head->data << " ";
	if(head->right) Inorder(head->right);
}

void Node::Preorder(Node* head) {
	std::cout << head->data << " ";
	if(head->left) Preorder(head->left);
	if(head->right) Preorder(head->right);
}

void Node::Postorder(Node* head) {
	if(head->left) Postorder(head->left);
	if(head->right) Postorder(head->right);
	std::cout << head->data << " ";
}

int Node::Count(Node* head) {
	if(head) return 1+Count(head->left)+Count(head->right);
	else return 0;
}

int Node::Leaf(Node* head) {
	static int leafnodes = 0;
	if(head->left == NULL && head->right == NULL) leafnodes++;
	if(head->left) Leaf(head->left);
	if(head->right) Leaf(head->right);
	else return leafnodes;
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

bool Node::Mirror(Node* head1,Node* head2) {
	if(head1 == NULL || head2 == NULL) return true;
	return head1->data == head2->data && Mirror(head1->left,head2->right) && Mirror(head1->right,head2->left);
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
		if(curr->left && curr->left->data == x) {std::cout << "Parent: " << curr-> data << std::endl;return;}
		if(curr->right && curr->right->data == x) {std::cout << "Parent: " << curr-> data << std::endl;return;}
	}
	std::cout << "Parent: Not found" << std::endl;
	return;
}

void Node::Ancestors(Node* head,int x) {
	static bool found = false;
	if(head->data == x) found =true;
	if(head->left && !found) Ancestors(head->left,x);
	if(head->right && !found) Ancestors(head->right,x);
	if(found) std::cout << head->data << " ";
	return;
}

int Node::Depth(Node* head) {
	if(head == NULL) return -1;
	static int depth = 1;
	static int max = 0;
	max < depth? max = depth:max = max;
    if(head->left) {depth += 1;Depth(head->left);}
	if(head->right) {depth += 1;Depth(head->right);}
	depth -= 1;
	return max;
}

int main() {
	Node ref;
	Node* node;
	Node* copy;
	int search;
	
	std::cout << " -- Init node1 -- " << std::endl;
	node = ref.Init();

	std::cout << "Displaying Tree in Postorder: "; ref.PostorderIterative(node);
	std::cout << "Displaying Tree in Inorder: "; ref.InorderIterative(node);
	std::cout << "Displaying Tree in Preorder: "; ref.PreorderIterative(node);

	std::cout << "Number of Nodes: " << ref.Count(node) << std::endl;
	std::cout << "Number of Leaf Nodes: " << ref.Leaf(node) << std::endl;
	std::cout << "Depth of Tree: " << ref.Depth(node) << std::endl;

	//Searching for Parent Node
	std::cout << "Search for Parent Node in Tree: ";
	std::cin >> search;
	ref.Parent(node,search);

	//Searching for Ancestor Nodes
	std::cout << "Search for Ancestor Nodes in Tree: ";
	std::cin >> search;
	ref.Ancestors(node,search);
	std::cout << std::endl;

	//Copying Node
	std::cout << " -- Copy to node2 -- " << std::endl;
	copy = ref.Copy(node);

	//Checking if Trees are same
	ref.Check(node,copy) ? std::cout << "Tree is same" : std::cout << "Tree is not same";
	std::cout << std::endl;

	std::cout << " -- Init node2 -- " << std::endl;
	copy = ref.Init();
	
	//Checking if Tree is a mirror Image of the other
	ref.Mirror(node,copy) ? std::cout << "Tree is a mirror copy" : std::cout << "Tree is not a mirror copy";
	std::cout << std::endl;

}
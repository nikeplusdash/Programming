#include <iostream>

class NodeStack {
	private:
	Node* node[50];
	int n;
	public:
	NodeStack(){n=-1;}
	void push(Node* root){node[++n] = root;}
	void pop(){if(!empty()) n--;}
    bool empty(){return n == -1;}
	Node* top(){return node[n];}
};

class NodeQueue {
    private:
    Node* node[50];
    int front,rear;
    public:
    NodeQueue(){front=-1;rear=-1;}
    void enqueue(Node* root){
        if(front == rear && front == -1) front = 0;
        node[++rear] = root;
    }
    void dequeue(){
        if(front==rear) {front = rear = -1;return;}
        ++front;
    }
    void poprear(){
        if(front==rear) {front = rear = -1;return;}
        --rear;
    }
    Node* peeprear(){return node[rear];}
    Node* peek(){return node[front];}
    bool empty(){return front == rear && front == -1;}
};

class Node {
    private:
    int data;
    Node* lc;
    Node* rc;
    public:
    Node(int x) {data = x;lc=rc=NULL;}
    Node* init();
    void Inorder(Node*);
    void Preorder(Node*);
    void Postorder(Node*);
    void Postorder2(Node*);
};

Node* Node::init() {
    int x;
    std::cin >> x;
    if(x == -1) return NULL;
    Node* p = new Node(x);
    std::cout << "Enter left child of " << x << ": "; p->lc = init();
    std::cout << "Enter right child of " << x << ": "; p->rc = init();
    return p;
}

void Node::Inorder(Node* head) {
    Node* curr = head;
    NodeStack s;
    while(curr || !s.empty()) {
        while(curr) {s.push(curr);curr=curr->lc;}
        if(s.empty()) break;
        Node* curr = s.top();
        curr = s.top();s.pop();
        std::cout << curr->data << " ";
        curr = curr->rc;
    }
    std::cout << std::endl;
}

void Node::Preorder(Node* head) {
    NodeStack s;
    s.push(head);
    while(!s.empty()) {
        Node* curr = s.top();s.pop();
        std::cout << curr->data << " ";
        if(curr->rc) s.push(curr->rc);
        if(curr->lc) s.push(curr->lc);
    }
    std::cout << std::endl;
}

void Node::Postorder(Node* head) {
    Node* curr = head;
    NodeStack s;
    do {
        while(curr){
            if(curr->rc) s.push(curr->rc);
            s.push(curr);
            curr = curr->lc;
        }
        curr = s.top();s.pop();
        if(curr->rc && !s.empty() && curr->rc == s.top()) {s.pop();s.push(curr);curr = curr->rc;}
        else {std::cout << curr->data << " ";curr = NULL;}
    } while(!s.empty());
}

void Node::Postorder2(Node* head) {
    NodeStack s1,s2;
    s1.push(head);
    while(!s1.empty()) {
        Node* curr = s1.top();s1.pop();
        s2.push(curr);
        if(curr->lc) s1.push(curr->lc);
        if(curr->rc) s1.push(curr->rc);
    }
    while(!s2.empty()) {
        Node* curr = s2.top();s2.pop();
        std::cout << curr->data << " ";
    }
    std::cout << std::endl;
}
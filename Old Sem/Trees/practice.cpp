#include <iostream>
#include <stdlib.h>

class Tree {
    private:
    int data;
    Tree* lc;
    Tree* rc;
    public:
    Tree(){};
    Tree(int);
    Tree* Init();
    void Inorder(Tree*);
    void Preorder(Tree*);
    void Postorder(Tree*);
    void InorderIterative(Tree*);
    void PreorderIterative(Tree*);
    void PostorderIterative(Tree*);
    void PostorderIterativeTwo(Tree*);
    void Levelorder(Tree*);
    void LevelorderReverse(Tree*);
    void Parent(Tree*,int);
    void Ancestors(Tree*,int);
    void Descendants(Tree*,int);
    void Siblings(Tree*,int);
    int Depth(Tree*);
    Tree* Reverse(Tree*,Tree*);
    Tree* Mirror(Tree*);
    Tree* Copy(Tree*);
};

class TreeStack {
	private:
	Tree* node[50];
	int n;
	public:
	TreeStack(){n=-1;}
	void push(Tree* root){node[++n] = root;}
	void pop(){if(!empty()) n--;}
    bool empty(){return n == -1;}
	Tree* top(){return node[n];}
};

class TreeQueue {
    private:
    Tree* node[50];
    int front,rear;
    public:
    TreeQueue(){front=-1;rear=-1;}
    void enqueue(Tree* root){
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
    Tree* peeprear(){return node[rear];}
    Tree* peek(){return node[front];}
    bool empty(){return front == rear && front == -1;}
};

Tree::Tree(int x) {
    data = x;
}

Tree* Tree::Init() {
    int x;
    std::cin >> x;
    if(x == -1) return NULL;
    Tree* p = new Tree(x);
    std::cout << "Enter left child of " << p->data << " :"; p->lc = Init();
    std::cout << "Enter right child of " << p->data << " :"; p->rc = Init();
    return p;
}

void Tree::Inorder(Tree* head) {
    if(!head) return;
    Inorder(head->lc);
    std::cout << head->data << " ";
    Inorder(head->rc);
}

void Tree::Preorder(Tree* head) {
    if(!head) return;
	std::cout << head->data << " ";
    Inorder(head->lc);
    Inorder(head->rc);
}

void Tree::Postorder(Tree* head) {
    if(!head) return;
    Inorder(head->lc);
    Inorder(head->rc);
	std::cout << head->data << " ";
}

void Tree::InorderIterative(Tree* head) {
	TreeStack s;
    Tree* curr = head;
    while(curr || !s.empty()) {
        while(curr) {s.push(curr);curr = curr->lc;}
        if(s.empty()) break;
        curr = s.top();
        s.pop();
        std::cout << curr->data << " ";
        curr = curr->rc;
    }
    std::cout << std::endl;
}

void Tree::PreorderIterative(Tree* head) {
    if(!head) return;
    TreeStack s;
    s.push(head);
    while(!s.empty()) {
        Tree* curr = s.top();
        s.pop();
        std::cout << curr->data << " ";
        if(curr->rc) s.push(curr->rc);
        if(curr->lc) s.push(curr->lc);
    }
    std::cout << std::endl;
}

void Tree::PostorderIterative(Tree* head) {
    if(!head) return;
    TreeStack s;
    Tree* curr = head;
    do {
        while(curr) {
            if(curr->rc) s.push(curr->rc);
            s.push(curr);
            curr = curr->lc;
        }
        curr = s.top();
        s.pop();
        if(curr->rc && !s.empty() && curr->rc == s.top()) {s.pop();s.push(curr);curr = curr->rc;}
        else { std::cout << curr->data << " ";curr = NULL;}
    } while(!s.empty());
    std::cout << std::endl;
}

void Tree::PostorderIterativeTwo(Tree* head) {
    TreeStack s1,s2;
    s1.push(head);
    while(!s1.empty()) {
        Tree* curr = s1.top();s1.pop();
        s2.push(curr);
        if(curr->lc) s1.push(curr->lc);
        if(curr->rc) s1.push(curr->rc);
    }
    while(!s2.empty()) {
        Tree* curr = s2.top();s2.pop();
        std::cout << curr->data << " ";
    }
    std::cout << std::endl;
}

void Tree::Levelorder(Tree* head) {
    TreeQueue q;
    q.enqueue(head);
    while(!q.empty()) {
        Tree* curr = q.peek();
        q.dequeue();
        if(curr->lc) q.enqueue(curr->lc);
        if(curr->rc) q.enqueue(curr->rc);
        std::cout << curr->data << " ";
    }
    std::cout << std::endl;
}

void Tree::LevelorderReverse(Tree* head) {
    TreeQueue q;
	TreeStack s;
    q.enqueue(head);
	while(!q.empty()) {
		Tree* curr = q.peek();q.dequeue();
		s.push(curr);
		if(curr->rc) q.enqueue(curr->rc);
		if(curr->lc) q.enqueue(curr->lc);
    }
	while(!s.empty()) {
		Tree* curr = s.top();s.pop();
		std::cout << curr->data << " ";
	}
	std::cout << std::endl;
}

void Tree::Parent(Tree* head,int x) {
    if(!head) return;
    static bool found = false,skip = false;
    if(head->data == x) {skip = found = true;return;}
    if(head->lc && !found) Parent(head->lc,x);
    if(head->rc && !found) Parent(head->rc,x);
    if(skip) {std::cout << "Parent of " << x << ": "<< head->data << std::endl;skip = false;}
}

void Tree::Ancestors(Tree* head,int x) {
    if(!head) return;
    static bool found = false;
    if(head->data == x) {found = true;return;}
    if(head->lc && !found) Ancestors(head->lc,x);
    if(head->rc && !found) Ancestors(head->rc,x);
    if(found) std::cout << head->data << " ";
}

void Tree::Descendants(Tree* head,int x) {
    if(head->data == x) {std::cout << "Descedants of " << head->data << ": ";Levelorder(head);return;}
    if(head->lc) Descendants(head->lc,x);
    if(head->rc) Descendants(head->rc,x);
}

void Tree::Siblings(Tree* head, int x) {
    TreeStack s;
    Tree* parent = NULL;
    s.push(head);
    while(!s.empty()) {
        Tree* curr = s.top();s.pop();
        if(curr->lc) {
            if(curr->lc->data == x) {
                parent = curr;
                break;
            }
            else s.push(curr->lc);
        }
        if(curr->rc) {
            if(curr->rc->data == x) {
                parent = curr;
                break;
            }
            else s.push(curr->rc);
        }
    }
    if(!parent || !parent->lc || !parent->rc) {std::cout << "No siblings" << std::endl;return;}
    std::cout << "Sibling: " << (parent->lc->data == x ? parent->rc->data : parent->lc->data) << std::endl;
}

int Tree::Depth(Tree* head){
    if(!head) return 0;
    static int depth = 1;
    static int max = 1;
    max = max < depth ? depth : max;
    if(head->lc) {depth += 1;Depth(head->lc);}
    if(head->rc) {depth += 1;Depth(head->rc);}
    depth-=1;
    return max;
}

Tree* Tree::Reverse(Tree* head,Tree* prev) {
    if(!head) return NULL;
    if(head->lc) head->rc = Reverse(head->lc,head->rc);
    if(head->rc) head->lc = Reverse(head->rc,head->lc);
    return head;
}

Tree* Tree::Mirror(Tree* head){
    if(!head) return NULL;
    Tree* m = new Tree(head->data);
    m->lc = Mirror(head->rc);
    m->rc = Mirror(head->lc);
    return m;
}

Tree* Tree::Copy(Tree* head){
    if(!head) return NULL;
    Tree* m = new Tree(head->data);
    m->rc = Mirror(head->rc);
    m->lc = Mirror(head->lc);
    return m;
}

int main() {
	Tree ref;
	Tree* Tree,* MirrorTree;
    int x;
	
	std::cout << " -- Init Tree -- " << std::endl;
	Tree = ref.Init();
    MirrorTree = ref.Mirror(Tree);

	std::cout << "Displaying Tree in Inorder: "; ref.InorderIterative(Tree);
	std::cout << "Displaying Tree in Preorder: "; ref.PreorderIterative(Tree);
    std::cout << "Displaying Tree in Postorder: "; ref.PostorderIterative(Tree);
    std::cout << "Displaying Tree in Postorder: "; ref.PostorderIterativeTwo(Tree);
    std::cout << "Displaying Tree in Levelorder: "; ref.Levelorder(Tree);
    std::cout << "Displaying Tree in Levelorder Reverse: "; ref.LevelorderReverse(Tree);
    MirrorTree = ref.Reverse(MirrorTree,MirrorTree);

    std::cout << "Displaying Mirror Tree in Levelorder: "; ref.Levelorder(MirrorTree);
    std::cout << "Find Ancestors: ";
    std::cin >> x;
    std::cout << "Ancestors of " << x << ": ";
    ref.Ancestors(Tree,x);
    std::cout << std::endl;
    std::cout << "Find Descedants: ";
    std::cin >> x;
    ref.Descendants(Tree,x);
    std::cout << "Find Parent: ";
    std::cin >> x;
    ref.Parent(Tree,x);
    std::cout << "Find Sibling: ";
    std::cin >> x;
    ref.Siblings(Tree,x);
}
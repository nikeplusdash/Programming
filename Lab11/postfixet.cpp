#include <iostream>

class Tree {
    public:
    char c;
    Tree* lc;
    Tree* rc;
    Tree(char num){
        c = num;
        lc = rc = NULL;
    }
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

Tree* ptree(std::string s) {
    TreeStack stk;
    for(int i=0;i<s.length();i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            Tree* node = new Tree(s[i]);
            stk.push(node);
        }
        else if(s[i] >= 'a' && s[i] <= 'z'|| s[i] >='A' && s[i] <= 'Z') {
            Tree* node = new Tree(s[i]);
            stk.push(node);
        }
        else {
            Tree* node1 = stk.top();stk.pop();
            Tree* node2 = stk.top();stk.pop();
            Tree* node = new Tree(s[i]);
            node->rc = node1;
            node->lc = node2;

            stk.push(node);
        }
    }
    return stk.top();
}

int eval (Tree* head) {
    if(!head) return 0;
    if(!head->lc && !head->rc) return head->c - '0';
    int left = eval(head->lc);
    int right = eval(head->rc);
    if(head->c == '+') return left+right;
    if(head->c == '-') return left-right;
    if(head->c == '*') return left*right;
    if(head->c == '/') return left/right;

}

void Inorder(Tree* head) {
    if(!head) return;
    Inorder(head->lc);
    std::cout << head->c << " ";
    Inorder(head->rc);
}

void Preorder(Tree* head) {
    if(!head) return;
	std::cout << head->c << " ";
    Preorder(head->lc);
    Preorder(head->rc);
}

int main() {
    std::string s;
    std::cout << "Enter postfix expression: ";
    std::cin >> s;
    Tree* tree = ptree(s);
    std::cout << "Infix: "; Inorder(tree); std::cout << std::endl;
	std::cout << "Prefix: "; Preorder(tree); std::cout << std::endl;
    std::cout << "Evaluation: " << eval(tree);
}

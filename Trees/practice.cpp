#include <iostream>

class Tree {
    private:
    int data;
    Tree* lc;
    Tree* rc;
    public:
    Tree* init(Tree*);
    void Inorder(Tree*);
    void Preorder(Tree*);
    void Postorder(Tree*);
    void InorderIterative(Tree*);
    void PreorderIterative(Tree*);
    void PostorderIterative(Tree*);
};

Tree* Tree::init(Tree* root) {
    
}
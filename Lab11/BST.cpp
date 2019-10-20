#include <iostream>
#include <bits\stdc++.h>

using namespace std;
class Node {
    private:
    int data;
    Node* lc;
    Node* rc;
    public:
    Node* Insert(Node* root) {
        Node* prev,* curr,* temp;
        temp = new Node();
        cout << "Enter data: ";
        cin >> temp->data;
        temp->lc = temp->rc = NULL;
        if(!root) return temp;
        prev = NULL; curr = temp;
        while(curr) {
            prev = curr;
            if (curr->data < temp->data) {
                curr = curr->rc;    
            }
            else if(curr->data > temp->data) {
                curr = curr->rc;
            }
            else {
                delete temp;
                cout << "ILLEGAL" << std::endl;
                return root;
            }
        }
        if (prev->data > temp->data) prev->lc = temp;
        else prev->rc = temp;
        return root;
    }
    Node* Search (Node* root,int x) {
        Node* curr = root;
        while(curr) {
            if(curr->data == x || curr->lc->data == x || curr->rc->data == x) {
                cout << "Found";return curr;
            }
            if(x > curr->data) curr = curr->rc;
            else curr = curr->lc;
        }
        cout << "Not found";
        return NULL;
    }
    void Traverse (Node* root) {
        queue <Node*> s;
        s.push(root);
        while (!s.empty())
        {
            Node* curr = s.front();s.pop();
            std::cout << curr->data;
            if(curr->lc) s.push(curr->lc);
            if(curr->rc) s.push(curr->rc);
        }
        std::cout << std::endl;
    }
    Node* Delete(Node* root,int x) {
        if(!root) return NULL;
        else if(root->data > x) root->lc = Delete(root,x);
        else if(root->data < x) root->rc = Delete(root,x);
        else {
            if(!root->lc && !root->rc) {
                delete root;
                return NULL;
            }
            else if(!root->lc) {
                Node* temp = root;
                root = root->rc;
                delete temp;
                return root;
            }
            else if(!root->rc) {
                Node* temp = root;
                root = root->lc;
                delete temp;
                return root;
            }
            else {
                Node* temp = root->rc;
                while(temp->lc) temp = temp->lc;
                root->data = temp->data;
                root->rc = Delete(root->rc,temp->data);
            }
        }
        return root;
    }
};
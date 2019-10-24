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
        curr = root;
        while(curr) {
            prev = curr;
            if (curr->data < temp->data) {
                cout << temp->data <<" went to right of " << curr->data << endl;
                curr = curr->rc;    
            }
            else if(curr->data > temp->data) {
                cout << temp->data <<" went to left of " << curr->data << endl;
                curr = curr->lc;
            }
            else {
                delete temp;
                cout << "ILLEGAL" << endl;
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
            if(curr->data == x) {
                cout << "Found" << endl;return curr;
            }
            if(x > curr->data) curr = curr->rc;
            else curr = curr->lc;
        }
        cout << "Not found" << endl;
        return NULL;
    }
    void Inorder(Node* root) {
        if(!root) return;
        Inorder(root->lc);
        cout << root->data << " ";
        Inorder(root->rc);
    }
    void Traverse (Node* root) {
        queue <Node*> s;
        s.push(root);
        while (!s.empty())
        {
            Node* curr = s.front();s.pop();
            std::cout << curr->data << " ";
            if(curr->lc) s.push(curr->lc);
            if(curr->rc) s.push(curr->rc);
        }
        std::cout << "\nInorder: ";
        Inorder(root);
        cout << endl;
    }
    Node* Delete(Node* root,int x) {
        if(!root) return NULL;
        else if(root->data > x) root->lc = Delete(root->lc,x);
        else if(root->data < x) root->rc = Delete(root->rc,x);
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

int main() {
    cout << "1:Insert 2:Delete 3:Traverse 4:Search" << endl;
    Node ref;
    Node* root = NULL;
    int x,i;
    while(1){
        cout << "Enter: ";
        cin >> x;
        switch(x) {
            case 1:
            root = ref.Insert(root);
            break;
            case 2:
            cout << "Delete: ";
            cin >> i;
            root = ref.Delete(root,i);
            break;
            case 3:
            ref.Traverse(root);
            break;
            case 4:
            cout << "Search: ";
            cin >> i;
            ref.Search(root,i);
            break;
            default:
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* addNode(int val, Node* root) {
    if (root == NULL) return new Node(val);

    if (root->data >= val) root->left = addNode(val, root->left);
    else root->right = addNode(val, root->right);

    return root;
}

void traverseLevel(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            Node* node = q.front();
            q.pop();

            cout << node->data << ":";

            if (node->left != NULL) {q.push(node->left); cout << node->left->data << ",";}
            else cout << "-1,";
            
            if (node->right != NULL) {q.push(node->right);cout << node->right->data << " ";}
            else cout << "-1 ";
        }

        cout << endl;
    }
}
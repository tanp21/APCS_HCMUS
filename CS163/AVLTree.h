#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;
};

int getHeight(Node* x) { return x ? x->height : 0; }
int getBalance(Node* x) { return x ? getHeight(x->left) - getHeight(x->right) : 0; }

void updHeight(Node* &root) {
    if (!root) return;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

void rotateNode(Node* &root, bool ccw) {
    Node* &F1 = ccw ? root->right : root->left;
    Node* &F2 = ccw ? F1->left : F1->right;

    swap(F1, F2); swap(root, F2);
    updHeight(F2); updHeight(root);
}

void insertAVL(Node* &root, int x) {
    if (!root || root->data == x) return void(root ? : root = new Node{x, 1, NULL, NULL});
    insertAVL(x < root->data ? root->left : root->right, x);

    updHeight(root); int bal = getBalance(root);
    if(bal >= -1 && bal <= 1) return;

    int needCmp = bal > 1 ? root->left->data : root->right->data;
    if((bal > 1) == (x > needCmp))
        rotateNode(bal > 1 ? root->left : root->right, bal > 1);
    rotateNode(root, bal < -1);
}
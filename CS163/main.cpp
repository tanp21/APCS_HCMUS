#include <bits/stdc++.h>
#include "AVLTree.h"
using namespace std;

void delAVL(Node* &node) {
    if(!node) return;
    delAVL(node->left); delAVL(node->right);
    delete node;
}

pair<bool,int> validAVL(Node* node) {
    if(!node) return {true, 0};
    if (node->left && node->data <= node->left->data) {
        return {false, 1e9};
    }
    if (node->right && node->data >= node->right->data) {
        return {false, 1e9};
    }
    pair<bool, int> l = validAVL(node->left), r = validAVL(node->right);
    return {l.first && r.first && abs(l.second - r.second) <= 1, max(l.second, r.second) + 1};
}

void printGraph(Node* node) {
    if(!node) return;
    cerr << "Node, Height " << node->data << " " << getHeight(node) << "\n";
    if(node->left) {
        cerr << "edge " << node->data << " " << node->left->data << "\n";
        printGraph(node->left);
    }
    if(node->right) {
        cerr << "edge " << node->data << " " << node->right->data << "\n";
        printGraph(node->right);
    }
}

void solve() {
    int x;
    Node* avl = nullptr;
    while(cin >> x) {
        if(!x) break;
        insertAVL(avl, x);
        assert(validAVL(avl).first);
    }
    printGraph(avl);
    delAVL(avl);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    for(int i = 1; i <= tt; i++) {
        // cout << "Case " << i << "#: ";
        solve();
    }

    return 0;
}
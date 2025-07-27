#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Pre-order: Root → Left → Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Utility to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

int main() {
    // Sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Pre-order traversal: ";
    preorder(root);  // Output: 1 2 4 5 3
}
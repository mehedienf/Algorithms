#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// In-order: Left → Root → Right
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "In-order traversal: ";
    inorder(root);  // Output: 4 2 5 1 3
}
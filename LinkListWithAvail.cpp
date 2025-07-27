#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* avail = nullptr;
Node* getNode(int value) {
    Node* newNode;
    if (avail != nullptr) {
        newNode = avail;
        avail = avail->next;
        cout << "(Reusing node from avail)\n";
    } else {
        newNode = new Node;
        cout << "(Allocating new node)\n";
    }
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
void freeNode(Node* node) {
    node->next = avail;
    avail = node;
}
void insertFront(Node*& head, int value) {
    Node* node = getNode(value);
    node->next = head;
    head = node;
}
void deleteFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    freeNode(temp);
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    Node* head = nullptr;

    insertFront(head, 10);
    insertFront(head, 20);
    insertFront(head, 30);

    cout << "List: ";
    printList(head);

    deleteFront(head);
    insertFront(head, 40);

    cout << "Updated List: ";
    printList(head);
}
//
//  main.cpp
//  CSDP project 4
//
//  Created by Christopher Turnbull on 5/6/24.
//

#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}


void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    // Requirement 1: Generate at least 40 random natural numbers (less than 100)
    int numbers[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85,
                     5, 15, 23, 33, 42, 53, 63, 73, 82, 90, 3, 13, 27, 37, 47,
                     57, 67, 77, 87, 97, 1, 17, 29, 39, 49};
    const int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Requirement 2: Create a linked list such that each node is a node of the binary search tree, and the first node is the root.
    Node* root = nullptr;
    // Requirement 3: Read each natural number, wrap it with a node, and insert it into the linked list.
    for (int i = 0; i < size; ++i) {
        root = insert(root, numbers[i]);
    }
    // Requirement 4: display traversal results
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

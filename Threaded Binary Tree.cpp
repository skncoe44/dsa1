// Implement Threaded Binary Tree and traverse it in In-order Post- order and Pre-order.

#include <iostream>
using namespace std;

// Node structure for the threaded binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;  // Flag to indicate if the right pointer is a thread

    Node(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

// Function to create a new threaded binary tree node
Node* createThreadedNode(int value) {
    return new Node(value);
}

// Function to perform in-order traversal of the threaded binary tree
void inOrderTraversal(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            // Process current node
            cout << current->data << " ";

            // Move to the in-order successor
            current = current->right;
        } else {
            // Find the in-order predecessor
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // Make the current node as the right child of its in-order predecessor
            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                // Restore the tree structure
                predecessor->right = nullptr;

                // Process current node
                cout << current->data << " ";

                // Move to the in-order successor
                current = current->right;
            }
        }
    }
}

// Function to perform pre-order traversal of the threaded binary tree
void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform post-order traversal of the threaded binary tree
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    // Input from user to build a threaded binary tree
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Node* root = nullptr;

    if (numNodes > 0) {
        cout << "Enter the values of nodes separated by spaces: ";
        root = createThreadedNode(0);  // Dummy root to simplify the traversal code

        for (int i = 0; i < numNodes; ++i) {
            int value;
            cin >> value;

            Node* newNode = createThreadedNode(value);
            if (i == 0) {
                root->left = newNode;
            } else {
                Node* current = root->left;
                while (current->right != nullptr) {
                    current = current->right;
                }
                current->right = newNode;
            }
        }
    }

    // Make threaded connections (if needed)
    // For simplicity, you can manually specify the threaded connections in this example

    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return new Node(data);
    } else if (data < root->val) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *deleteDuplicates(Node *root) {
    if (root == NULL) 
        return NULL;

    root->left = deleteDuplicates(root->left);
    root->right = deleteDuplicates(root->right);

    if (root->left != NULL && root->left->val == root->val) {
        Node *temp = root->left;
        while (temp != NULL && temp->val == root->val) {
            Node *nextTemp = temp;
            temp = temp->right;
            delete nextTemp;
        }
        return root->right; // Return the right child if duplicates found
    }

    if (root->right != NULL && root->right->val == root->val) {
        Node *temp = root->right;
        while (temp != NULL && temp->val == root->val) {
            Node *nextTemp = temp;
            temp = temp->right;
            delete nextTemp;
        }
        return root->left; // Return the left child if duplicates found
    }

    return root;
}

void display(Node *root) {
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main() {
    Node *root = NULL;
    int data;

    cout << "Enter numbers to insert into BST (-1 to stop): ";
    cin >> data;

    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }

    cout << "Inorder traversal of the BST: ";
    display(root);
    cout << endl;

    root = deleteDuplicates(root);
    cout << "Inorder traversal after deleting all duplicates: ";
    display(root);
    cout << endl;

    return 0;
}

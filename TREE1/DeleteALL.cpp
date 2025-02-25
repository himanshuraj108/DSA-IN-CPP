#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    else if (data < root->val)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *deleteAllOccurrences(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    root->left = deleteAllOccurrences(root->left, key);
    root->right = deleteAllOccurrences(root->right, key);

    if (root->val == key)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    return root;
}

void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main()
{
    Node *root = NULL;
    int data;

    cout << "Enter numbers to insert into BST (-1 to stop): ";
    cin >> data;

    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }

    cout << "Inorder traversal of the BST: ";
    display(root);
    cout << endl;

    int n;
    cout << "Enter a number to delete all occurrences: ";
    cin >> n;

    root = deleteAllOccurrences(root, n);
    cout << "Inorder traversal after deleting all occurrences of " << n << ": ";
    display(root);
    cout << endl;

    return 0;
}

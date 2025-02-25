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

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }

    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }

    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void displayInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    displayInOrder(root->left);
    cout << root->val << " ";
    displayInOrder(root->right);
}

int main()
{

    int n;
    cin >> n;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        root = insert(root, ele);
    }

    displayInOrder(root);
}
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

    else if (value < root->val)
    {
        root->left = insert(root->left, value);
    }

    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void display(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;

    return root->val + sum(root->left) + sum(root->right);
}

int size(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int main()
{

    Node *root = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        root = insert(root, ele);
    }

    display(root);
    cout << endl;

    cout << sum(root);
    cout << endl;

    cout << size(root);
    cout << endl;
}
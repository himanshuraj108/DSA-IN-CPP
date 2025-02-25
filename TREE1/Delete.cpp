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

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *suc = root->right;
        while (suc->left != NULL)
        {
            suc = suc->left;
        }

        root->val = suc->val;
        root->right = deleteNode(root->right, suc->val);
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
    cin >> data;

    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }

    display(root);
    cout << endl;

    int n;
    cin >> n;

    deleteNode(root, n);
    display(root);
}
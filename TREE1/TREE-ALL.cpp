#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);
    if (data < root->val)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
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

int Max(Node *root)
{
    if (root == NULL)
        return 0;
    return max(root->val, max(Max(root->left), Max(root->right)));
}

int level(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}

void nthLevel(Node *root, int curr_level, int level)
{
    if (root == NULL)
        return;
    if (curr_level == level)
        cout << root->val << " ";
    nthLevel(root->left, curr_level + 1, level);
    nthLevel(root->right, curr_level + 1, level);
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

    int key;
    cin >> key;
    root = deleteNode(root, key);
    display(root);
    cout << endl;

    cout << sum(root) << endl;
    cout << size(root) << endl;
    cout << Max(root) << endl;
    cout << level(root) << endl;

    int curr_level;
    cin >> curr_level;
    int level;
    cin >> level;
    nthLevel(root, curr_level, level);

    return 0;
}

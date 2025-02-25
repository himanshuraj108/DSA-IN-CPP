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

// PRE-ORDER :- Root Left Right
void displayTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " "; // Root

    displayTree(root->left);  // Left
    displayTree(root->right); // Right
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    e->left = f;
    e->right = g;

    displayTree(a);
}
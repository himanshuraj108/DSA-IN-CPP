#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Function to recursively insert a new node at the end of the linked list
Node *insertAtEnd(Node *head, int value)
{
    if (head == NULL)
    {
        return new Node(value); // Base case: if the list is empty, create a new node
    }
    head->next = insertAtEnd(head->next, value); // Recursive case: traverse to the next node
    return head;
}

// Function to recursively display the linked list
void display(Node *head)
{
    if (head == NULL)
    {
        return; // Base case: when the list ends
    }
    cout << head->val << " "; // Print the current node's value
    display(head->next);      // Recursive call to display the next node
}

int main()
{
    int n;
    cin >> n; // Number of elements in the linked list

    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        head = insertAtEnd(head, value); // Recursively insert each value into the linked list
    }

    display(head); // Recursively display the linked list
    cout << endl;

    return 0;
}

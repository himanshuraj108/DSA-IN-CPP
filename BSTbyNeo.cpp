#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
   
    Node*newNode=new Node;
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
    
}

Node* insertNode(Node* root, int value) {

    if(root==NULL){
        return createNode(value);
    }
    
    else if(value<root->data){
        root->left=insertNode(root->left,value);
    }
    
    else{
        root->right=insertNode(root->right,value);
    }
    
    return root;
    
}

bool searchKey(Node* root, int key) {
    
    //Type your code here
    if(root==NULL) return false;
    
    if(root->data==key){
        return true;
    }
    
    if(key<root->data){
        return searchKey(root->left,key);
    }
    
    if(key>root->data){
        return searchKey(root->right,key);
    }
}

int main() {
    Node* root = NULL;
    int numNodes, value, key;

    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cin >> key;

    bool found = searchKey(root, key);
    if (found) {
        cout << "The key " << key << " is found in the binary search tree";
    } else {
        cout << "The key " << key << " is not found in the binary search tree";
    }

    return 0;
}

#include<iostream>      
using namespace std;

struct Node{
    int data;
    Node *LC = nullptr;
    Node *RC = nullptr;
    int height;
};

void preOrder(Node *root) 
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->LC);
    preOrder(root->RC);

}


int getHeight(Node *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return root->height;
}

Node* createNode(int key)
{
    Node *temp = new Node;
    temp->data=key;
    temp->LC=nullptr;
    temp->RC=nullptr;
    temp->height=1;
    return temp;
}

int max(int a,int b)
{
    return a>b?a:b;
}

// Utility Function
int getBalanceFactor(Node *n)
{
    if(n==nullptr)
    {
        return 0;
    }
    return getHeight(n->LC)-getHeight(n->RC);   
}

Node* rightRotate(Node* y)
{
    Node *x = y->LC;
    Node *T2 = x->RC;

    x->RC=y;
    y->LC=T2;

    y->height = max(getHeight(y->RC),getHeight(y->LC))+1;
    x->height = max(getHeight(x->RC),getHeight(x->LC))+1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node *y = x->RC;
    Node *T2 = y->LC;

    y->LC=x;
    x->RC=T2;

    y->height = max(getHeight(y->RC),getHeight(y->LC))+1;
    x->height = max(getHeight(x->RC),getHeight(x->LC))+1;

    return y; 
}


Node* insert(int data,Node *&root)
{
    if(root==nullptr)
    {
        return(createNode(data));
    }

    if(data<root->data)
    {
        root->LC=insert(data,root->LC);  // Insert in left sub tree.
    }
    else if (data>root->data)
    {
        root->RC=insert(data,root->RC);  // Insert in right sub tree.
    }

    root->height = 1 + max(getHeight(root->LC),getHeight(root->RC));
    int bf = getBalanceFactor(root);

    // left left case
    if (bf>1 && data < root->LC->data)
    {
        return rightRotate(root);
    }
    // right right case
    if (bf<-1 && data > root->RC->data)
    {
        return leftRotate(root);
    }
    // left right case
    if (bf>1 && data > root->LC->data)
    {
        root->LC = leftRotate(root->LC);
        return rightRotate(root);
    }
    // right left case
    if(bf<-1 && data < root->RC->data)
    {
        root->RC = rightRotate(root->RC);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(1,root);
    root = insert(2,root);
    root = insert(4,root);
    root = insert(5,root);
    root = insert(6,root);
    root = insert(3,root);
    
    cout << "Preorder Traversal of the AVL Binary Tree: ";
    preOrder(root);
    cout << endl;
    
    return 0;
}
#include<iostream>      
using namespace std;

struct Node{
    int data;
    Node *LC = nullptr;
    Node *RC = nullptr;
};

void inOrder(Node *root) 
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->LC);
    cout << root->data << " ";
    inOrder(root->RC);
}

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

void postOrder(Node *root) 
{
   if (root == nullptr)
    {
        return;
    }
    postOrder(root->LC);
    postOrder(root->RC);
    cout << root->data << " ";
}

void insert(int data,Node *&root)
{
    if(root==nullptr)
    {
        Node *temp = new Node;
        temp->data = data;
        root = temp;
        return;
    }

    if(data<root->data)
    {
        insert(data,root->LC);  // Insert in left sub tree.
    }
    else if (data>root->data)
    {
        insert(data,root->RC);  // Insert in right sub tree.
    }
    else
    {
        //Duplicate value do nothing
        cout << "Duplicate Value " << data << "not interested.\n";
        return;
    }

}


Node *findMax(Node *&root)
{   //check if the tree is empty
    if(root==nullptr)
    {
        return nullptr;
    }

    //The right most node is the maximum
    if (root->RC == nullptr)
    {
        return root;
    }
    return findMax(root->RC);
}

Node *findMin(Node *&root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if (root->LC == nullptr)
    {
        return root;
    }
    return findMin(root->LC);
}

//searching in a binarysearchtree
bool binarySearch(int key,Node *&root){
    if (root == nullptr)
    {
        cout << "Key not found " << endl;
        return false;
    }

    if (root->data == key){
        cout << "Key found" << endl;
        return true;
    }
    else if (key < root->data)
    {
        return binarySearch(key,root->LC);
    }
    else 
    {
        return binarySearch(key,root->RC);
    }
}

void deleteKey(int key,Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    
    if(root->data == key)
    {
        // Case 1: Is it's a leaf node delete it directly.
        if(root->RC == nullptr && root->LC == nullptr)
        {
            delete root;
            root = nullptr;
            return;
        }
        // Case 2: If the root  has only one child
        // 1.Left child
        else if (root->RC == nullptr)
        {
            Node *temp = root->LC;
            delete root;
            root = temp;
            return;
        } 
        // 2.Right child
        else if (root->LC == nullptr)
        {
            Node *temp = root->RC;
            delete root;
            root = temp;
            return;
        }

        // Case 3: Having both right and left child
        else{
            // Finding min node from root's right
            Node *min = findMin(root->RC);

            // replacing data
            root->data = min->data;

            // deleting min data as there can't be duplicates in BST.
            deleteKey(root->data,root->RC);
        }
    }
    // Finding Node
    else if(key < root->data)
    {
        return deleteKey(key,root->LC);
    }
    else
    {
        return deleteKey(key,root->RC);
    }
}


int main(){
    Node *root = nullptr;
    insert(10,root);
    insert(15,root);
    insert(5,root);
    insert(20,root);
    insert(1,root);
    insert(4,root);
    insert(9,root);
    insert(6,root);
    insert(12,root);
    insert(14,root);
    insert(13,root);
    insert(7,root);

    deleteKey(10,root);

    cout << "Inorder Traversal of the Binary Tree: ";
    inOrder(root);
    cout << endl;
    // cout << "Preorder Traversal of the Binary Tree: ";
    // preOrder(root);
    // cout << endl;
    // cout << "Postorder Traversal of the Binary Tree: ";
    // postOrder(root);
    // cout << endl;

    return 0;
}
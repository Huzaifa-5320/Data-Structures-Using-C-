#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }

};

void insert(int data, Node *&head)
{
    Node *newNode = new Node(data);
    newNode->next = head;  // Works correctly whether head is nullptr or not
    head = newNode;         // Update head to point to the new node
}


void append(int data,Node *&head)
{
    if(head == nullptr)
    {
        insert(data,head);
        return;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void search(int data,Node *head)
{
    Node *temp = head;
    int key = data;
    int count=1;
    while(temp!=nullptr)
    {
        if(key==temp->data)
        {
            cout << "Value exists at Position:" << count << endl;
            
        }
        count++;
        temp=temp->next;
    }
}

void deleteNode(int pos,Node *&head)
{
    if (head == nullptr) 
    {
        cout << "Error: The list is empty!" << endl;
        return;
    }

    int count=1;
    Node* temp = head;
    

    if(pos==1)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
 
    // Traverse to the node just before the target position
    while(temp!=nullptr && count < pos-1)
    {
        count++;
        temp = temp->next;
    }
   
    // Check if the position is valid (node exists)
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Error: Position " << pos << " does not exist in the list!" << endl;
        return;
    }


    if(temp!=nullptr && temp->next!=nullptr){
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}


void viewList(Node *ptr)
{
    if(ptr == NULL)
    {
        cout << "The list is empty !" << endl;
    }
    while(ptr != NULL)
    {
        cout << ptr->data<<"->";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}


int main(){
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
 
    // viewList(head);

    // insert(5,head);
    // viewList(head);

    append(5,head);
    append(6,head);
    // viewList(head);

    // search(4,head);


    deleteNode(1,head); // works as expected
    viewList(head);   
    deleteNode(5,head); // works as expected
    viewList(head);

    // Test Case
    // Node *testNode = NULL;
    // append(1,testNode);
    // append(2,testNode);
    // append(3,testNode);
    // viewList(testNode);

    
    return 0;
}
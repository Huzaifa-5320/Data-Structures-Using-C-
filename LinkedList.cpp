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

void insertAtHead(int data,Node *&head)
{
    Node *newNode = new Node(data);
    if(head==nullptr)
    {
        head = newNode;
    }
    newNode->data = data;
    if(head!=nullptr)
    {
        newNode->next=head;
    }
    head = newNode;
}

void insertAtTail(int data,Node *&head)
{
    if(head == nullptr)
    {
        insertAtHead(data,head);
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
 
    viewList(head);

    insertAtHead(5,head);
    viewList(head);

    insertAtTail(6,head);
    viewList(head);

    // Test Case
    // Node *testNode = NULL;
    // insertAtTail(1,testNode);
    // insertAtTail(2,testNode);
    // insertAtTail(3,testNode);
    // viewList(testNode);

    
    return 0;
}
#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(Node *&head,int val){
    Node *n = new Node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;  
}


void insertAtTail(Node *&head,int val){
      if (head == nullptr) {
        insertAtHead(head, val); // Insert at head if the list is empty
        return;
    }
    
    Node* newNode = new Node(val);
    Node* temp = head;

    // Traverse to the end of the list
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;

}

void display(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtHead(Node *&head){
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deletion(Node *&head,int pos){
    Node *temp = head;
    int count=1;

    if(pos==1){
        deleteAtHead(head);
        return;
    }
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if (temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    
    delete temp;
}


int main(){
    Node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);

    deletion(head,1);
    display(head);

};
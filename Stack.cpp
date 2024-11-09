#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Node{
    int data;
    Node *next;
};


void push(int data,Node *&top){
    Node *temp = new Node;
    temp->data=data;
    temp->next=top;
    top=temp;
}    

int pop(Node *&top){
    if(top==nullptr){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    Node *temp = top;
    int result = temp->data;
    top = top->next;
    return result;
}

void peek(Node *top){
    if(top==nullptr){
        cout <<"Stack is empty" << endl;
        return;
    }
    cout << top->data << endl;
}

bool isEmpty(Node *top){
    Node* temp = top;
    if(temp==nullptr){
        return true;
    }
    return false;
}

int main(){
    Node *top = nullptr;
    push(1,top);
    push(2,top);
    push(3,top);
    push(4,top);
    push(5,top);
    push(6,top);
    peek(top);
    
    pop(top);
    pop(top);
    pop(top);
    pop(top);
    pop(top);
    pop(top);
    pop(top); // will cause stack underflow as there are no more values to be poped.

    peek(top);
    cout << isEmpty(top) << endl; // will return 1 (true) as stack is empty!

    push(1,top);
    cout << isEmpty(top) << endl; // will return 0 (false) as stack is not empty!

    return 0;
}

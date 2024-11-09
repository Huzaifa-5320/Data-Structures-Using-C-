#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node *front;
    Node *rear;

    public:
    Queue(){
        front=NULL;
        rear=NULL;
    }

    void enQueue(int x){
        Node *temp=new Node(x);
        if(front==NULL){
            front=temp;
            rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }

    int deQueue(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        Node *temp = front;
        front=temp->next;
        return temp->data;
    }

    int peek(){
         if(front==NULL){
            cout<<"No element in Queue"<<endl;
            return 1;
        }
        return front->data;
    }

    bool isEmpty(){
        if (front==NULL){
            return true;
        }
        return false;
    }
};


int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    cout<< q.deQueue() << endl;
    cout<< q.deQueue() << endl;
    cout<< q.deQueue() << endl;
    cout<< q.deQueue() << endl;
    cout<< q.deQueue() << endl;
    // cout<< q.deQueue() << endl; //  will cause Queue underflow

    return 0;
};
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

    void EnQueue(int x){
        Node *temp=new Node(x);
        if(front==NULL){
            front=temp;
            rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }

    int DeQueue(){
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

    bool empty(){
        if (front==NULL){
            return true;
        }
        return false;
    }
};


int main(){
    Queue q;
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    cout<< q.DeQueue() << endl;
    cout<< q.DeQueue() << endl;
    cout<< q.DeQueue() << endl;
    cout<< q.DeQueue() << endl;
    cout<< q.DeQueue() << endl;
    cout<< q.DeQueue() << endl;

    return 0;
};
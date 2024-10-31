#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Node{
    int data;
    Node *next;
};


void push(char data,Node *&top){
    Node *temp = new Node;
    temp->data=data;
    temp->next=top;
    top=temp;

}    

char pop(Node *&top){
    if(top==nullptr){
        cout<<"Stack Underflow"<<endl;
        return '\0';
    }
    Node *temp = top;
    char result = temp->data;
    top = top->next;
    return result;
}

int main(){
    Node *top = nullptr;
    push(1,top);
    push(2,top);
    push(3,top);
    push(4,top);
    push(5,top);
    push(6,top);
    cout<<top->data<<endl;
    char c1 = pop(top);
    cout<<c1<<endl;

    return 0;
}

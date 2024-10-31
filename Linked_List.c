 #include<stdio.h>
#include<stdlib.h>

typedef struct Node{ 
    int data;
    struct Node *next;
}Node;

void viewList(Node *ptr){
    while (ptr != NULL){
        printf(" %d --> ",ptr->data);
        ptr = ptr->next;
    }
    printf("null");
};

Node* insertFirst(Node *ptr){
    int val;
    printf("Enter the value:\n");
    scanf("%d",&val);
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->data=val;
    newNode->next=ptr;
    
    return newNode;

};

Node* insertAt(int pos,int data,Node *ptr){
    int n=1;
    while (n<pos-1){
        ptr=ptr->next;
        n++;
    }
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=ptr->next;
    ptr->next=newNode;
    return ptr;
};

Node* reverseList(Node *ptr){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *previous = (Node*)malloc(sizeof(Node));
    Node *next = (Node*)malloc(sizeof(Node));
    head = ptr;
    previous = NULL;
    next = NULL;
    while (head!=NULL){
        next = head->next;
        head->next=previous;
        previous=head;
        head=next;
    }
    return previous;
}




int main(){
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    //Allocate memory for nodes in the Linked List in Heap
    head = (Node*) malloc (sizeof(Node)); 
    second = (Node*) malloc (sizeof(Node)); 
    third = (Node*) malloc (sizeof(Node));
    fourth = (Node*) malloc (sizeof(Node));       
    
    //Link first and second Node
    head->data=1;
    head->next=second;
    
    //Link second and third Node
    second->data=2;
    second->next=third;

    //Link third and fourth Node
    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    viewList(head);
    printf("\n");
    // insertAt(3,22,head);
    // printf("\n");
    // viewList(head);
    Node *a = reverseList(head);
    viewList(a);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* addListstart(Node *head){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = 23;
    newNode->next = head;
    return newNode;
}

Node* addListEnd(int value){
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(){

    Node *head = NULL;
    Node *temp = NULL;
    Node *newNode = NULL;

    for(int i = 0 ; i<5 ; i++){
        newNode = malloc(sizeof(Node));
        newNode->data = i+10;
        newNode->next = NULL;

        if(head==NULL){
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;

        }

        
    }
    head = addListstart(head);

    Node *lasttemp = head ;
    while(lasttemp->next!=NULL){
        lasttemp = lasttemp->next;
    }
    lasttemp->next=addListEnd(65);

    Node *t =head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;

    
}
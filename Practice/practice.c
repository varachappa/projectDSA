#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* insertBegin(Node *head,int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
void insertEnd(Node **head ,int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}
Node* createList(int size){
    Node *head = NULL ;
    Node *temp = NULL ;
    Node *newNode = NULL;
    for(int i = 0 ; i<size ; i++){
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
    return head;
}
void printList(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    Node *head = createList(5);
    head = insertBegin(head , 21);
    insertEnd(&head , 65);
    printList(head);

    return 0;
}
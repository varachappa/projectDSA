#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data ; 
    struct Node *next;
}Node;
int listLen(Node *head){
    int count =0;
    while(head!=NULL){
        count ++;
        head = head->next;
    }
    return count;
}
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
void addPosNode(Node **head ,int n , int data){
    int len = listLen(*head);
    Node *temp = *head;
    if(n<1 || n>len+1){
        printf("Not a valid position to operate\n");
        return ;
    }
    else if(n==1){
        *head = insertBegin(*head , 100);
    }
    else if(n==len+1){
        insertEnd(head,900);
    }
    else {
        for(int i = 1 ; i< n-1;i++){
            temp = temp->next;
        }
        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        Node *remNode = temp->next;
        temp->next = newNode;
        newNode->next = remNode->next;
        free(remNode);
        remNode=NULL;
    }
}
Node* createList(int size){
    Node *head = NULL;
    Node *temp = NULL;
    Node *newNode = NULL;

    for(int i = 0 ;i < size ;i ++){
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
void freeList(Node *head){
    Node *temp ; 
    while(head!=NULL){
        temp = head ;
        head = head->next;
        free(temp);
    }
}
int main(){
    Node *head = createList(5);
    printList(head);
    printf("\n");
   
    addPosNode(&head,1,99);
    printList(head);
    freeList(head);
    return 0;

}
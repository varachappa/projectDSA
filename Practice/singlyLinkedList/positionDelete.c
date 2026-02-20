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
void deleteFirst(Node **head){
    if(*head ==NULL)
        return ;
    Node *temp = *head;
    *head = temp->next;
    free(temp);
    
}
void deleteLast(Node **head){
    if(*head == NULL)
        return ;
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return ;
    }
    Node *temp = *head;
   while(temp->next->next!=NULL){
    temp = temp->next;
   }
   free(temp->next);
   temp->next = NULL;
}
void deletePosNode(Node *head , int n){
        int len = listLen(head);
    Node *temp = head;
    if(n<1 && n>len+1){
        printf("Not a valid position to operate\n");
        return ;
    }
    else if(n==1){
        deleteFirst(&head);
    }
    else if(n==len+1){
        deleteLast(&head);
    }
    else {
        for(int i = 1 ; i< n-1;i++){
            temp = temp->next;
        }
        Node *remNode = temp->next;
        temp->next = temp->next->next;
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
int main(){
    Node *head = createList(5);
    printList(head);
    printf("\n");
    deleteFirst(&head);
    printList(head);

}
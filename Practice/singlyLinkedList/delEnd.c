#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data ; 
    struct Node *next;
}Node;
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
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    Node *head = createList(5);
    printList(head);
    printf("\n");
    deleteLast(&head);
    printf("\n");
    printList(head);

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    int data ;
    struct Node  *next;
}Node ;

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

void reverseList(struct Node **head) {

    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // save next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    *head = prev;
}

void freeList(Node *head){
    Node *temp;
    while(head!=NULL){
        temp = head ;
        head = head->next;
        free(temp);
    }
}

int main(){
    Node *head = createList(5);
    printList(head);
    reverseList(&head);
    printf("\n");
    printList(head);
    freeList(head);
    return 0;
}
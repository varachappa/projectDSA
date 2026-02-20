#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node* addListstart(Node *head){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = 20;
    newNode->next = head;
    return newNode;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
    int id;
    int age;
    char name[30];
}student;

int main(){
    student s;
    student *p=&s;
    p->id = 8;
    p->age = 20 ;
    strcpy(p->name , "vara");
    printf("%d %d : %s\n",p->id , p->age , p->name); 
}
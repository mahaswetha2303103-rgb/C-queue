#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node*next;
};
struct node *front=NULL;
void enqueue(int data,int priority){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->priority=priority;
    newNode->next=NULL;
    if(front==NULL||priority<front->priority){
        newNode->next=front;
        front=newNode;
    }else{
        struct node *temp=front;
        while(temp->next!=NULL&&temp->next->priority<=priority){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void display(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    struct node *temp=front;
    printf("Priority Queue: ");
    while(temp!=NULL){
        printf("(%d,p=%d)",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int n,data,priority;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&data);
        printf("Enter priority: ");
        scanf("%d",&priority);
        enqueue(data,priority);
    }
    display();
}

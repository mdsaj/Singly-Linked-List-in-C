/*Singly Linked List implementation
  with list operations*/
   
#include <stdio.h>
struct node{
    int data;
    struct node *next;
}*start=NULL;

void insert(int n){
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(start==NULL)
    start=temp;
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=temp;
    }
}

void addAtBeginning(int d){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=start;
    start=temp;
}

void addAtSpecific(int pos,int d){
    struct node *q=start,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    for(int i=1;i<pos-1;i++){
        q=q->next;
    }
    temp->data=d;
    temp->next=q->next;
    q->next=temp;
}

void delete(int d){
    int delc=0;
    while(start->data==d)
    {
        //printf("%d deleted from the list.\n",start->data);
        delc++;
        struct node *temp;
        temp=start;
        start=start->next;
        free(temp);
        if(start==NULL){
            printf("%d is deleted from %d places in the list\n",d,delc);
            return;
        }
    }
    struct node *q;
    q=start;
    while(q->next->next!=NULL){
        if(q->next->data==d)
        {
            //printf("%d deleted from the list.\n",q->next->data);
            delc++;
            struct node *temp=q->next;
            q->next=q->next->next;
            free(temp);
        }
        else
        q=q->next;
    }
    if(q->next->data==d){
    struct node *temp=q->next;
    //printf("%d deleted from the list.\n",q->next->data);
    delc++;
    q->next=NULL;
    free(temp);}
    if(delc==0)
    printf("%d is not in the list\n",d);
    else
    printf("%d is deleted from %d places in the list\n",d,delc);
}

void deleteAtPos(int pos){
    if(pos==1){
        printf("%d deleted from the list.\n",start->data);
        struct node *temp=start;
        start=start->next;
        free(temp);
        return;
    }
    struct node *q=start;
        for(int i=1;i<pos-1;i++){
            q=q->next;
        }
        printf("%d deleted from the list.\n",q->next->data);
        struct node *temp=q->next;
        q->next=q->next->next;
        free(temp);
}
void printlist(struct node *start){
    struct node *q=start;
    if(start==NULL)
    printf("List is empty.\n");
    else{
    while(q->next!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("%d\n",q->data);}
}
void countNodes(struct node *start){
    struct node *q=start;
    if(start==NULL)
    printf("List is empty,No nodes.\n");
    else{
        int count=0;
    while(q->next!=NULL){
        count++;
        q=q->next;
    }
    printf("No of nodes=%d\n",count+1);}
}

void search(int d){
    struct node *q=start;int pos=1,flag=0;
    while(q!=NULL){
        if(q->data==d)
        {
            printf("%d is found at %d position\n",d,pos);
            if(flag==0)
            flag++;
        }
        q=q->next;
        pos++;
    }
    if(flag==0)
    printf("%d is not present in the list",d);
}

void reverseList(){
    if(start->next==NULL)
    return;
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
}
//Recursive implementation of reverseList
void recrev(struct node *p){
    if(p->next==NULL){
        start=p;
        return;
    }
    recrev(p->next);
    struct node *q=p->next;
    q->next=p;
    p->next=NULL;
}

int main()
{   
    //Checking each function
    insert(10);
    insert(20);
    insert(30);
    addAtBeginning(5);
    addAtSpecific(2,50);
    printlist(start);
    delete(5);
    printlist(start);
    delete(10);
    printlist(start);
    delete(30);
    //Checking Github desktop
    printlist(start);
    addAtBeginning(5);
    printlist(start);
    insert(10);
    insert(20);
    insert(30);
    printlist(start);
    deleteAtPos(3);
    printlist(start);
    deleteAtPos(5);
    printlist(start);
    countNodes(start);
    insert(10);
    insert(20);
    printlist(start);
    delete(10);
    printlist(start);
    delete(20);
    printlist(start);
    addAtBeginning(50);
    insert(50);
    insert(50);
    printlist(start);
    countNodes(start);
    delete(50);
    printlist(start);
    insert(5);
    printlist(start);
    insert(5);
    printlist(start);
    reverseList();
    printlist(start);
    recrev(start);
    printlist(start);
    
    return 0;
}

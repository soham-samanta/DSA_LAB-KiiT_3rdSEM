#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
};

struct node* createDll(){
    struct node*head=NULL,*prev=NULL,*n;
    int val;
    printf("Enter all the nodes of Double linkedList \nPress -1 to terminate:\n");
    while((scanf("%d",&val))&&val!=-1){
        n=(struct node*)malloc(sizeof(struct node));
        n->data=val;
        n->next=NULL;
        n->prev=prev;

        if(head==NULL)
        head=n;
        if(prev!=NULL)
        prev->next=n;
        
        prev=n;
    }
    return head;
}

void disp(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}


int main(){
    struct node*head;

    head=createDll();
    printf("Creating the the linkedList\n");
    disp(head);

    return 0;
}
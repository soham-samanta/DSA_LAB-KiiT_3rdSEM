#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next,*prev;
} node;


node * head=NULL, * temp=NULL;
void CreateLinkedList(){
    int t;
    while( (scanf("%d",&t)) && t != -1){
        node * n = (node * ) malloc(sizeof(node));
        n->data = t;
        n->next = NULL;
        if(head == NULL){
            head = n;
            temp=head;
        }
        else{
            temp->next = n;
            temp = n;
        }                 
    }
}

void disp(){
    node * temp = head;
    while(temp != NULL){
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int power(int x, int y){
    if( y == 0) 
    return 1;
    
    return x*power(x,y-1);
}

bool Palindrom(){
    node * temp = head;
    int n1 = 0 , n2 = 0, l = 0;
    while(temp != NULL){
        int n = temp->data, f=0;                
        while(n != 0) {
            n2 = (n%10)*power(10,l) + n2;
            n = n/10;
            f++;
            l++;
        }
        n1 = n1*power(10,f) + temp->data;                
        n = n/10;                
        temp = temp->next;
    }
    if(n2 == n1){        
        return true;
    }else{
        return false;
    }
}

int main(){
    printf("Enter all the nodes of linkedList \nPress -1 to terminate:\n");
    CreateLinkedList();
    printf("Displaying the elements of LinkedList\n");
    disp();

    bool pal = Palindrom();
    if(pal)
        printf("is Palindrome !");
    else
        printf("is Not Palindrome !\n");
    
    return 0;
}



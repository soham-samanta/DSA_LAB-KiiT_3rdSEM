#include <stdio.h>  
#include<stdlib.h>
  
struct node{  
    int data;  
    struct node *prev;  
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
 
void atHead(int data) {   
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL) {  
        head = tail = newNode;  
        head->prev = NULL;  
        tail->next = NULL;  
    }else{  

        tail->next = newNode;  
        newNode->prev = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
}  
void removeDuplicateNode() {  
    struct node *current, *index, *temp;  
    if(head == NULL) {  
        return;  
    } else{  

        for(current = head; current != NULL; current = current->next) {  
            for(index = current->next; index != NULL; index = index->next) {  
                if(current->data == index->data) {  
                    temp = index;  
                    index->prev->next = index->next;  
                    if(index->next != NULL)  
                        index->next->prev = index->prev;  
                    temp = NULL;  
                }  
            }  
        }  
    }  
}  
   
void disp() {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
   
int main()  {  

    atHead(1);  
    atHead(2);  
    atHead(3);  
    atHead(2);  
    atHead(2);  
    atHead(4);  
    atHead(5);  
    atHead(3);  
      
    printf("Originals list: \n");  
    disp();  
      
    removeDuplicateNode();  
      
    printf("List after removing duplicates: \n");  
    disp();  
   
    return 0;  
}  
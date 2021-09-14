#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
} Node;

Node * head = NULL, * end = NULL;

void TraverseForward(){
    Node * curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void TraverseBackward(){
    Node * curr = end;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void InsertAtPos(int pos, int data){
    int k = 1;
    Node * curr = head, *ele, *prev = NULL;
    ele = (Node *) malloc(sizeof(Node));
    ele->data = data;
    ele->next = NULL;
    ele->prev = NULL;
    while(k < pos){
        prev = curr;
        curr = curr->next;
        k++;
    }
    
    if(pos == 1){
        head = ele;
    }
    else if(end == NULL){
            prev->next = ele;
            ele->prev = head;
            end = ele;
    }
    else if(prev == end){
            prev->next = ele;
            ele->prev = prev;
            end = ele;
        }
    else{
        ele->next = prev->next;
        if(prev->next != NULL)
        prev->next->prev = ele; 
        
        prev->next = ele;
        ele->prev = prev;
        if(prev == end){
            end = ele;
        }
    }

}

void DeleteAtPos(int pos){
    int k = 1;
    Node * curr = head;
    while(k < pos){
        curr = curr->next;
        k++;
    }
    if(curr->next == end){
        end = curr->next->next;
    }
    curr->next = curr->next->next;
}


void DelKey(int key){
    Node * curr = head;
    while(curr != NULL){
        if(curr->data == key){
            if(curr->prev != NULL){
                printf(":HI\n");
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            else{
                if(curr == head){
                    head = curr->next;
                    curr->next->prev = NULL;
                }
                if(curr == end){
                    curr->prev->next =  NULL;
                    end = curr->prev;
                }
            }
            break;
        }
        curr=curr->next;
    }
}

int NoNodes(){
    int N=0;
    Node * curr = head;
    while(curr != NULL){
        N++;
        curr = curr->next;
    }
    return N;
}

int SearchKey(int key){
    Node * curr = head;
    int k = 0;
    while(curr != NULL){
        ++k;
        if(curr->data == key){
            return k;
        }
        curr=curr->next;
    }
    return -1;
}


int main(){
    int choice=0,pos,data,key,N;
    do{
        printf("1: Traverse List Forward\n2: Traverse List Backward\n3: Is List Empty?\n4: Insert at position\n5: Delte at position\n6: Delete  Key\n7: Count Total Nodes\n8: Search an Element\n-1:Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                TraverseForward();
                break;
            case 2:
                TraverseBackward();
                break;
            case 3:
                if(isEmpty()){
                    printf("List is Empty\n");
                }
                else{
                    printf("List is not Empty\n");
                }
                break;
            case 4:
                printf("Enter position and data : ");
                scanf("%d%d",&pos,&data);
                InsertAtPos(pos,data);
                break;
            case 5:
                printf("Enter position to delete : ");
                scanf("%d",&pos);
                DeleteAtPos(pos);
                break;
            case 6:
                printf("Enter Key to delete : ");
                scanf("%d",&key);
                DelKey(key);
                break;
            case 7:
                N = NoNodes();
                printf("No. of Nodes : %d\n",N);
                break;
            case 8:            
                int key;
                printf("Search for key :");
                scanf("%d",&key);
                key = SearchKey(key);                
                printf("Key is at index : %d\n" , key);
                break;
        }
    }while(choice != -1);

    return 0;
}
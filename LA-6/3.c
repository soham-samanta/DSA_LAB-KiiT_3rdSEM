#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a,b)  a>b?a:b

typedef struct Node{
    int row,col,value;    
    struct Node * next;
} Node;

void create(Node *  head, Node *  end){
    Node * n, * prev = NULL;    
    int t1 = 0, t2=0, t3 = -1, rows = INT_MIN , cols = INT_MIN, entries=0;
    while(1){
        scanf("%d%d%d",&t1,&t2,&t3);
        if(t3 == 0) break;
        n = (Node *) malloc(sizeof(Node));
        n->row = t1;
        n->col = t2;
        n->value = t3;
        n->next = NULL;

        if(head == NULL){
            head = n;
        }

        if(prev != NULL){
            prev->next = n;
        }
        rows = max(rows,t1);
        cols = max(cols,t1);
        entries++;
        prev = n; 
    }

    end = n;
    
    n = (Node *) malloc(sizeof(Node));
    n->row = max(rows,cols);
    n->col = max(rows,cols);
    n->value = entries;
    n->next = head;
    head = n;
}

void disp(Node * head){
    Node * curr = head;
    while(curr != NULL){        
        printf("%d %d %d\n",curr->row, curr->col, curr->value); 
        curr = curr->next;
    }
    printf("\n") ;
}

Node * AddLL(Node * head1, Node * head2){
    
    Node * head = NULL, *curr, *curr1 = head1->next , *curr2 = head2->next, *prev = NULL; 
    int entries = 0;
    while(curr1 != NULL && curr2 != NULL){
        
        curr = (Node *) malloc(sizeof(Node));
        if(curr1->row < curr2->row){            
            curr->value = curr1->value;
            curr->row = curr1->row;
            curr->col = curr1->col;
            curr->next = NULL;      
            curr1 = curr1->next;            
        }
        else if(curr2->row < curr1->row){            
            curr->value = curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;      
            curr2 = curr2->next;
        }
        else if(curr1->row == curr2->row){

            if(curr1->col < curr2->col){
                curr->value = curr1->value;
            curr->row = curr1->row;
            curr->col = curr1->col;
            curr->next = NULL;      
            curr1 = curr1->next;
            }
            else if(curr2->col < curr1->col){
                curr->value = curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;      
            curr2 = curr2->next;
            }
            else if(curr2->col == curr1->col){
                curr->value = curr1->value + curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;  
            curr1 = curr1->next;
            curr2 = curr2->next;   
            }
        }   

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;
        entries++;

    }

    while(curr1 != NULL){
        curr = (Node *) malloc(sizeof(Node));
        curr->value = curr1->value;
        curr->row = curr1->row;
        curr->col = curr1->col;
        curr->next = NULL;

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;

        curr1 = curr1->next;
        entries++;
        
    }
    
    
    while(curr2 != NULL){
        curr = (Node *) malloc(sizeof(Node));
        curr->value = curr2->value;
        curr->row = curr2->row;
        curr->col = curr2->col;
        curr->next = NULL;

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;
        
        curr2 = curr2->next; 
        entries++;       
    }

    curr = (Node *) malloc(sizeof(Node));
    curr->row = head1->row;
    curr->row = head2->row;
    curr->value = entries;
    curr->next = head;
    head = curr;

    return head;
}

Node * MulLL(Node *ptr1,Node *ptr2){
    Node * prod, *t1, *t2, *temp;
    if(ptr1->col!=ptr2->row){
        printf("Product Not possible\n");
        return NULL;
    }
    prod=(Node *)malloc(sizeof(Node));
    prod->row=ptr1->row; prod->col=ptr2->col;
    prod->value=0; prod->next=NULL;
    t1=ptr1->next; temp=prod;
    while(t1!=NULL){
        t2=ptr2->next;
        while(t2!=NULL){
            if(t1->col==t2->row){
                Node * tx, *it;
                tx =(Node *)malloc(sizeof(Node));
                tx->value = (t1->value)*(t2->value);
                tx->row = t1->row;
                tx->col = t2->col;
                tx->next = NULL;
                it = prod;
                if(prod != NULL) it = it->next;
                
                int add=1;
                while(it != NULL){
                    if(it->row == tx->row && it->col == tx->col){
                        it->value += tx->value;
                        add = 0;
                        break;
                    }
                    it = it->next;
                }
                if(add){
                    temp->next = tx;
                    temp = tx;
                }
                prod->value++;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }

    printf("\nProduct :\n");
    disp(prod);
    return prod; 
}

int main(){
    Node * head1 =NULL, *head2 = NULL, * head3 = NULL, *x, *y , * end1, * end2, *end3, *ans;    
    create(head1,end1);
    printf("First Polynomial : ");
    disp(head1);
    create(head2,end2);
    printf("Second Polynomial : ");
    disp(head2);    
    create(head3,end3);
    printf("Third Polynomial : ");
    disp(head3);    
    
    printf("Multiplication of Twp Polys : ");
    x = MulLL(head1,head2);
    y = MulLL(x, head3);
    disp(y);
}
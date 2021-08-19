#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node * next;
} node;


node * head=NULL, * end=NULL;
void CreateLinkedList(){
    int t;
    while( (scanf("%d",&t)) && t != -1){
        node * n = (node * ) malloc(sizeof(node));
        n->data = t;
        n->next = NULL;
        if(head == NULL){
            head = n;
            end=head;
        }
        else{
            end->next = n;
            end = n;
        }                 
    }
}

void DisplayLL(){
    node * temp = head;
    while(temp != NULL){
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool IsEmpty(){
    if(head == NULL) 
    return true;
    else 
    return false;
}

void atHead(){
    int x;
    printf("Enter the element to be added at begining : ");
    scanf("%d",&x);
    node * n = (node * ) malloc(sizeof(node));
    n->data = x;
    n->next = head;
    head = n;    
}

void deleteAtHead(){
    if(head != NULL) 
    head = head->next;
}

void deleteAtTail(){
    node * temp = head;
    if(temp == NULL) return;

    if(temp->next == NULL){
        head = NULL;
    }
    while(temp->next != end){
        temp = temp->next;
    }
    temp->next = NULL;
    end = temp;
}

void atTail(){
    int x;
    printf("Inserting Element to End  : ");
    scanf("%d",&x);
    node * n = (node * ) malloc(sizeof(node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){
        head = n;
        end = n;
    }
    else{
        end->next = n;
        end = n;
    }
}

int NoNodes(){
    node * temp = head;
    int ct=0;
    while(temp != NULL){
        ct++;
        temp = temp->next;
    }
    return ct;
}

struct Pair{
    int f, s;
};

struct Pair OddEven(){
    node * temp = head;
    struct Pair ans = {
        .f = 0,
        .s = 0
    };
    
    while(temp != NULL){
        if(temp->data %2 == 0) ans.f++;
        else ans.s++;
        temp = temp->next;
    }

    return ans;
}

int Primes(){
    node * temp = head;
    int ans = 0;
    while(temp != NULL){        
        int x = 0;
        for(int i = 2 ; i < temp->data ; i++)
            if(temp->data%i == 0){
                x++;
                break;
            }
        
        if(x == 0) ans++;
        temp = temp->next;        
    }
    return ans;
}

int power(int x, int y){
    if( y == 0) return 1;
    
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
    // printf("Forward : %d, Reverse : %d\n",n1,n2);
    if(n2 == n1){        
        return true;
    }
    else{
        return false;
    }
}

int main(){
    printf("Enter all the nodes of linkedList \nPress -1 to terminate:\n");
    CreateLinkedList();
    printf("Displaying the elements of LinkedList\n");
    DisplayLL();
    atHead();
    printf("Displaying the elements of LinkedList after adding a new node at begining\n");
    DisplayLL();
    printf("Deleting Element at begining node  \n");
    deleteAtHead();    
    DisplayLL();
    printf("Deleting Element from End  \n");
    deleteAtTail();
    DisplayLL();
    atTail();
    DisplayLL();    
    printf("No. of nodes in LinkedList : %d\n",NoNodes());
    struct Pair ans = OddEven();
    printf("Even : %d ,  Odd : %d\n",ans.f,ans.s);
    printf("Number of Primes in the LinkedList : %d\n",Primes());
    bool pal = Palindrom();
    if(pal)
        printf("is Palindrome !");
    else
        printf("is Not Palindrome !\n");
    
    return 0;
}



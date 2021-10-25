#include <stdio.h>

#define MAX_PRIORITIES 5
#define MAX_ROW_SIZE  5

int table[MAX_PRIORITIES][MAX_ROW_SIZE];
int circular_queue[MAX_PRIORITIES][2];
int * frontx(int);
int * rearx(int);
// o -> front
// 1 -> rear

void insert(int, int);
void init();
void print_raw_table();
int delete();

int main(){
    init();
    int ch;  
    int data, priority;  
    do{
        printf("Enter choice : \n1: Insert into priority queue\n2: Delete from priority queue\n3: Print Raw Priority Table(Debug)\nEnter choice : ");
        scanf("%d",&ch);
        printf("%d\n",ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data and the priority to be inserted : ");
            scanf("%d%d",&data,&priority);
            insert(data,priority);
            break;
        case 2:
            data = delete();  
            printf("Deleted : %d\n",data);
            break;
        case 3:
            print_raw_table();
            break;
        default:
            break;
        }
    }while(ch != -1);

    return 0;
}

void init(){
    for(int i = 0 ; i < MAX_PRIORITIES; i++){
        circular_queue[i][0] = circular_queue[i][1] = -1;
        for(int j = 0 ; j < MAX_ROW_SIZE; j++){
            table[i][j] = 0;
        }
    }
}

int * frontx(int x){
    return &circular_queue[x][0];
}

int * rearx(int x){
    return &circular_queue[x][1];
}

void insert(int data, int priority){
    priority--;
    int * front = frontx(priority);
    int * rear = rearx(priority);
    if((*front == 0 && *rear == MAX_ROW_SIZE-1) || (*front == *rear+1)){
        printf("Priority limit reached for %d\n",priority);
        return;
    }

    if(*front ==-1 && *rear == -1){
        (*front)++;
        (*rear)++;        
    }
    else if(*rear < MAX_ROW_SIZE-1) {
        (*rear)++;
    }
    else if(*rear == MAX_ROW_SIZE-1){        
        *rear = 0;
    }
    else{
        (*rear)++;
    }
    table[priority][*rear] = data;
}

int delete(){    
    for(int priority = MAX_ROW_SIZE-1; priority>=0 ; priority--){

        int * front = frontx(priority);
        int * rear = rearx(priority);
       
        int ind = 0;
        if(*front == *rear && *front == -1){            
            continue;
        }
        ind = *front;
        int data = table[priority][ind];
        if(*front == *rear){
            *front = -1;
            *rear = -1;            
        }
        else{
            if(*front == MAX_ROW_SIZE-1){        
               *front = 0;
            }
            else{
                (*front)++;
            }
        }

        table[priority][ind] = 0;
        return data;
    }

    printf("Priority Queue Empty !\n");
    return -1;
}

void print_raw_table(){
    printf("Priority | ");
    for(int j = 0 ; j < MAX_ROW_SIZE; j++) printf("%d  ",j+1);
    printf("\n--------------------------------------\n");
    for(int i = 0 ; i < MAX_PRIORITIES; i++){  
        printf("       %d | ",i+1);
        for(int j = 0 ; j < MAX_ROW_SIZE; j++){                        
            printf("%d  ",table[i][j]);
        }
        printf("\n");
    }
}
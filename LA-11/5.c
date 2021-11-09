#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define max(a,b) (a>b?a:b)
int st[MAX];
int top = -1;
int pop();
void push(int c);

int main(){
    int N;
    scanf("%d",&N);
    int * arr = (int *) malloc(sizeof(int) * (N+1));
    int * next_right = (int *) malloc(sizeof(int) * N);
    int *maxlen = (int *) malloc(sizeof(int) * N);
    int * next_left = (int *) malloc(sizeof(int) * N);

    for(int i = 1 ; i<= N ; i++) {
        scanf("%d",&arr[i]);

    }
    for(int i=N;i>=1;i--){
    	next_right[i] = -1;
    	while(!(top == -1) && arr[st[top]] < arr[i])
    		pop();
    	if(!(top == -1))
    		next_right[i] = st[top];
    	
        push(i);
    }

    while(!(top == -1))
    	pop();

    for(int i=1;i<=N;i++){
    	next_left[i] = 0;
    	while(!(top == -1) && arr[st[top]] < arr[i])
    		pop();
    	if(!(top == -1))
    		next_left[i] = st[top];

    	push(i);
    }

    for(int i=1;i<=N;i++){
    	if(next_right[i] != -1)
    		maxlen[next_right[i]-i] = max(maxlen[next_right[i]-i], i - next_left[i]);
    }

    long long ans = 0;
    for(int i=1;i<=N;i++){
    	ans += maxlen[i];
        printf("%d\n",maxlen[i]);
    }
    
    printf("%lld\n",ans);

    return  0;
}

void push(int val)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");
    else
    {
        top++;
        st[top] = val;
    }
}
int pop()
{
    int val;
    if (top == -1)
        printf("\nStack underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}
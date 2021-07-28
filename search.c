// SOHAM SAMANTA CODES
#include<stdio.h>

int main(){
  	int key,f;
	printf("Enetr the number of elements in array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
  	
	printf("Enter the Searching Element: ");
  	scanf("%d",&key);      
  	f = 0;
  	for(int i = 0; i < n; i++){
   		if(a[i] == key){
       		f = 1;
       		break;
	 	}   
   	}
  	if(f == 1){
  		printf("Element found\n");
	}else{
		printf("Element not found\n");
	}	
  	return 0;
}
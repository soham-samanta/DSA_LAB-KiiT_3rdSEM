#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 100000

// TC : O(2*N) = O(N)

int main(){
    char * pattern = (char *) malloc(sizeof(char) * MAX_LENGTH);
    char *inverted = (char *) malloc(sizeof(char) * MAX_LENGTH);
    char * sub_segment = (char *) malloc(sizeof(char) * MAX_LENGTH);    
    char * left_segment = (char *) malloc(sizeof(char) * MAX_LENGTH);
    char * right_segment = (char *) malloc(sizeof(char) * MAX_LENGTH);
    
    scanf("%s",pattern);
    
    int i = 0 , length=0;
    int invert = 1;
    int l_ptr=0, r_ptr = 0;
    while(pattern[i++] != '\0') length++;

    i = length;     
    while(i>0){
        char ch = pattern[i--];
        printf("%d\n",i);
        if(ch == '"'){
            int j = 0;            
            while(pattern[i] != '"'){
                sub_segment[j] = pattern[i];
                i--;
                j++;
            }            
            sub_segment[j++] = '\0';
            if(invert){                                
                strcat(left_segment,sub_segment);
            }
            else{
                for(int k = 0 ; k < j-1 ; k++){
                    inverted[j-k-2] = sub_segment[k];                                        
                }
                inverted[j-1] = '\0';                         
                strcat(inverted,right_segment);
                strcpy(right_segment,inverted);          
            } 
            invert = 1-invert;       
        }        
    }
    printf("%s%s",left_segment,right_segment);
    return 0;
}
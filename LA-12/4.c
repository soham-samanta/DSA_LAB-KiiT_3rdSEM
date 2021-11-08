#include <stdio.h>  
#include <stdbool.h>  
#include <stdlib.h>  

struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  

struct node *root = NULL;  
struct node* createNode(int data){  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));   
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
int largestElement(struct node *temp){   
    if(root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else{  
        int leftMax, rightMax;  
        int max = temp->data;  
        if(temp->left != NULL){  
            leftMax = largestElement(temp->left);  
            max = (max > leftMax) ? max : leftMax;  
        }  
        if(temp->right != NULL){  
          rightMax = largestElement(temp->right);   
          max = (max > rightMax) ? max : rightMax;  
        }  
    return max;  
    }  
}  
   
int main(){  
    root = createNode(15);  
    root->left = createNode(20);  
    root->right = createNode(35);  
    root->left->left = createNode(74);  
    root->right->left = createNode(55);  
    root->right->right = createNode(6);  

    printf("Largest element: %d", largestElement(root));  
    return 0;  
}  
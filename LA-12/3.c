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
int smallestElement(struct node *temp){  
    if(root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }else{  
        int leftMin, rightMin;  
        int min = temp->data;  
        if(temp->left != NULL){  
            leftMin = smallestElement(temp->left);  
            min = (min > leftMin) ? leftMin : min;  
        }  
        if(temp->right != NULL){  
            rightMin = smallestElement(temp->right);  
            min = (min > rightMin) ? rightMin : min;  
        }  
    return min;  
    }  
}  
        
int main()  {  
    root = createNode(15);  
    root->left = createNode(20);  
    root->right = createNode(35);  
    root->left->left = createNode(74);  
    root->right->left = createNode(55);  
    root->right->right = createNode(6);  
          
    printf("Smallest element: %d", smallestElement(root));  
    return 0;  
}  
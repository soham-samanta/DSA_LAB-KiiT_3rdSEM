#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define min(a,b) ((a < b) ? a : b)
#define max(a,b) ((a > b) ? a : b)

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
} Node;

Node * root = NULL, *curr = NULL;

Node * insert_node(Node * tree_root, int data);
void preorder(Node * root);
void postorder(Node * root);
void inorder_traversal(Node * root);
int smallest(Node * root);
int largest(Node * root);
int NoNodes(Node * root);
int leafNodes(Node * root);
int nonLeafNodes(Node * root);
int sumNodes(Node * root);
int DepthOftTree(Node * root);
void printMaxLevel(Node * root);
void printCA(Node * root, int a, int b);
int isValid(Node * root);

int main(){
    while(1){
        int data;
        printf("Enter next data : ");
        scanf("%d",&data);
        if(data == -1) break;

        root = insert_node(root,data);
    }    
    printf("Postoder Traversal : ");
    postorder(root);
    printf("\n");        
    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal : ");
    inorder_traversal(root);
    printf("\n");
    printf("Smallest Node : %d\n",smallest(root));     
    printf("Largest Node : %d\n",largest(root));        
    printf("Number Nodes : %d\n",NoNodes(root));     
    printf("Leaf Nodes : %d \n",leafNodes(root));
    printf("Non Leaf Nodes : %d\n",nonLeafNodes(root));
    printf("Sum of Nodes : %d\n",sumNodes(root));
    printf("Depth of Tree : %d\n",DepthOftTree(root));
    printf("Nodes at max level : ");printMaxLevel(root);    
    printf("\n");
    printf("Common ancestors : ");
    printCA(root,121,200); 
    printf("\n");
    printf("Boolean Value (Is BST Valid ?) : %d \n",isValid(root));
    return 0;
}

//int abort_enterring = 0;

/*
while(1){
        if(tree_root)
        printf("Enter for parent node %d \n",tree_root->data);
        scanf("%d",&data);
        if(data == -1){
            //abort_enterring = 1;
            break;        
        }
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data=data;
        ptr->left = NULL;
        ptr->right = NULL;
        if(tree_root != NULL){          
            if(data < tree_root->data) {
                
            }
            if(tree_root->left == NULL){
                tree_root->left = ptr;
            }
            else if(tree_root->right == NULL){
                tree_root->right = ptr;
                tree_root->left = insert(tree_root->left);
                //if(abort_enterring) break;
                tree_root->right = insert(tree_root->right);
                break;
            }        
        }
        else{
            tree_root = ptr;
        }
    } 
*/

Node * insert_node(Node * tree_root, int data){
    Node * ptr, *curr = NULL;
    
    ptr = (Node *) malloc(sizeof(Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree_root == NULL){
        tree_root = ptr;
        return tree_root;
    }

    if(data < tree_root->data){
        if(tree_root->left)
        tree_root->left = insert_node(tree_root->left,data);
        else 
        tree_root->left = ptr;
    }
    if(data > tree_root->data){
        if(tree_root->right)
        tree_root->right = insert_node(tree_root->right,data);
        else 
        tree_root->right = ptr;
    }

    return tree_root;
}


void preorder(Node * root){
    if(root == NULL) return;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);    
}

void postorder(Node * root){
    if(root == NULL) return;    
    postorder(root->left);
    postorder(root->right);  
    printf("%d  ",root->data);  
}
void inorder_traversal(Node * root){
    if(root == NULL) return;    
    inorder_traversal(root->left);
    printf("%d  ",root->data);
    inorder_traversal(root->right);    
}

int smallest(Node * root){
    if(root == NULL) return INT_MAX;
    return min(root->data,smallest(root->left));
}

int largest(Node * root){
    if(root == NULL) return INT_MIN;
    return max(root->data,largest(root->right));
}

int NoNodes(Node * root){
    if(root == NULL) return 0;
    return 1 + NoNodes(root->left) + NoNodes(root->right);
}


int leafNodes(Node * root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else return leafNodes(root->left) + leafNodes(root->right);
}

int nonLeafNodes(Node * root){    
    if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    else return 1 + nonLeafNodes(root->left) + nonLeafNodes(root->right);
}

int sumNodes(Node * root){
    if(root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int DepthOftTree(Node * root){
    if(root == NULL) return 0;
    return  1 + max(DepthOftTree(root->left),DepthOftTree(root->right));
}


void printAtDepth(Node * root, int level){
    if(root == NULL){
        return ;
    }
    if(level == 1) {
        printf("%d ",root->data);
        return;
    }
    else{
        printAtDepth(root->left,level-1);
        printAtDepth(root->right,level-1);
    }
}


void printMaxLevel(Node * root){
    int k = DepthOftTree(root);
    printAtDepth(root,3);
}

void printCA(Node * root, int a, int b){
    if((a < root->data && b > root->data) || (a > root->data && b < root->data) ){        
        printf("%d ",root->data);
        return ;
    }
    else{        
        if(a > root->data && b > root->data){
            printCA(root->right,a,b);
            printf("%d ",root->data);
        }
        else{
            printCA(root->left,a,b);
            printf("%d ",root->data);
        }
    }
}

int isValidComp(Node * root, int cmin, int cmax){
    if(root == NULL) return 1;
    else{  
        if(root->left == NULL && root->right == NULL) return 1;
        else if((root->left && root->left->data > cmin) || (root->right && root->right->data > cmax) ){
            return 1;
        }
        else{
            
            int a1,a2;
            if(root->left){
                a1 = isValidComp(root->left,min(cmin,root->left->data),max(cmin,root->left->data));
            }
            else{
                a2 = isValidComp(root->right,min(cmin,root->right->data),max(cmin,root->right->data));
            }

            return a1&&a2;
        }
    }
}

int isValid(Node * root){
    return isValidComp(root,root->data,root->data);
}
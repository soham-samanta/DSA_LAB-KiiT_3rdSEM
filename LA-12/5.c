#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *left, *right;
};

struct node *createnode(int key){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
static int count = 0;

int countnodes(struct node *root){
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int main(){
    struct node *newnode = createnode(51);
    newnode->left = createnode(27);
    newnode->right = createnode(32);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
    /* 
     *               51
     *             /    \
     *            27     32
     *           / \     / \
     *         17  91   13  55
     */

    printf("Number of nodes in tree = %d ",countnodes(newnode));
    printf("\n");
    count = 0;
    return 0;
}
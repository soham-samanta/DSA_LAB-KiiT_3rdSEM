#include <stdio.h>

struct tree
{
    int val;
    struct tree *right;
    struct tree *left;
    int thread;
};
struct tree *root = NULL;
struct tree *insert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{
    if (root == NULL)
    {
        root = ptr;
        if (rt != NULL)
        {
            root-> right = rt;
            root-> thread = 1;
        }
    }
    else if (ptr-> val< root-> val)
        root-> left = insert_node(root-> left, ptr, root);
    else if (root-> thread == 1)
    {
        root-> right = insert_node(NULL, ptr, rt);
        root-> thread = 0;
    }
    else
        root-> right = insert_node(root-> right, ptr, rt);
    return root;
}

struct tree *create_threaded_tree()
{
    struct tree *ptr;
    int num;
    printf("\n Enter the elements, press –1 to terminate ");
    scanf("%d", &num);
    while (num != -1)
    {
        ptr = (struct tree *)malloc(sizeof(struct tree));
        ptr-> val = num;
        ptr-> left = ptr-> right = NULL;
        ptr-> thread = 0;
        root = insert_node(root, ptr, NULL);
        printf(" \n Enter the next element ");
        fflush(stdin);
        scanf("%d", &num);
    }
    return root;
}
void inorder(struct tree *root)
{
    struct tree *ptr = root, *prev;
    do
    {
        while (ptr != NULL)
        {
            prev = ptr;
            ptr = ptr-> left;            
        }
        if (prev != NULL)
        {
            printf(" %d", prev-> val);
            ptr = prev-> right;            
            while (prev != NULL && prev-> thread)
            {
                printf(" %d", ptr-> val);
                prev = ptr;
                ptr = ptr-> right;
            }
        }
    } while (ptr != NULL);
}

struct tree * Succ(struct tree * ptr)
{
    if (ptr->thread == 1)
        return ptr->right;
 
    ptr = ptr->right;
    
    
    while (ptr->left != NULL)
        ptr = ptr->left;
    
    return ptr;
}
 

struct tree * Pred(struct tree * ptr)
{    
    ptr = ptr->left;
    while (ptr && ptr->thread == 0)
        ptr = ptr->right;
    return ptr;
}


struct tree * DeleteNode(struct tree * tree_root,int data){
    struct tree * ptr  = tree_root, *parent=NULL;
    int in_tree=0;
    while(ptr != NULL){
        if(ptr->val == data){
            in_tree = 1;
            break;
        }
        else if(data < ptr->val){
            parent = ptr;
            ptr = ptr->left;
        }
        else{
            if(!ptr->thread){
                parent = ptr;
                ptr = ptr->right;
            }
            else 
                break;
        }
    }
    
    if(in_tree){
        if(ptr->left && !ptr->thread){
            // two children
            struct tree * parent_of_left_succ = ptr;
            struct tree * left_of_succ = ptr->right;

            while(left_of_succ->left != NULL){
                parent_of_left_succ = left_of_succ;
                left_of_succ = left_of_succ->left;
            }

            ptr->val = left_of_succ->val;
            if(left_of_succ->left == NULL && left_of_succ->thread){
                // process as leaf node
                parent = parent_of_left_succ;
                ptr = left_of_succ;
                if(parent == NULL) root = NULL;
                else{
                    if(ptr == parent->left){
                        parent->left = ptr->left;
                    }
                    else{
                        parent->right = ptr->right;
                    }
                }
            }
            else{
                // process as single node deletion 
                  
                parent = parent_of_left_succ;
                ptr = left_of_succ;
                struct tree * child;
                if(ptr->left)
                    child = ptr->left;
                else
                    child = ptr->right;
                        
                if (parent == NULL)
                    root = child;
                        
                else if (ptr == parent->left)
                    parent->left = child;
                else{                    
                    parent->right = child;
                }
                
                // Find successor and predecessor            
                struct tree * s = Succ(ptr);
                struct tree * p = Pred(ptr);                     
                if(ptr->left != NULL){                                        
                    p->right = s;
                }   
                else{                                                   
                    s->left = p;
                }
            }
        }
        else if((ptr->left && ptr->thread ) || (ptr->left == NULL && !ptr->thread)){
            // one child            
            
            struct tree * child;
            if(ptr->left)
                child = ptr->left;
            else
                child = ptr->right;
                    
            if (parent == NULL)
                root = child;
                    
            else if (ptr == parent->left)
                parent->left = child;
            else
                parent->right = child;
            
            // Find successor and predecessor            
            struct tree * s = Succ(ptr);
            struct tree * p = Pred(ptr);     
            if(ptr->left != NULL){
                
                p->right = s;
            }   
            else{
                
                s->left = p;
            }                          
        }
        else{
            // leaf node
            if(parent == NULL) root = NULL;
            else{
                if(ptr == parent->left){
                    parent->left = ptr->left;
                }
                else{
                    parent->thread = 1;
                    parent->right = ptr->right;
                }
            }
        }
    }
    return root;
}



void main()
{
    // struct tree *root=NULL;
    
    create_threaded_tree();
    printf(" \n The in–order traversal of the tree can be given as : ");
    inorder(root);
    root = DeleteNode(root,121); // sing;e chhild
    root = DeleteNode(root,150);// double child
    root = DeleteNode(root,60); // leaf node
    printf("\n");
    inorder(root);
    
}
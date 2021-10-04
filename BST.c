#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1,* LOC,*PAR;
 
void insert();
void search_to_insert(struct btnode *t);
void delete1(struct btnode *t, int data);
void delete2(struct btnode *t);
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
int smallest(struct btnode *t);
int largest(struct btnode *t);
void search(struct btnode* t, int key);
int flag = 1;

// Function to insert a new node
void insert()
{
    int data;
 
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1*sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
    
    if (root == NULL) 
        root = temp;
    else    
        search_to_insert(root);    
}
 
// Function to search for the appropriate position to insert the new node 
void search_to_insert(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))      // if value more than root node value insert to the right 
        search_to_insert(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))    // if value less than root node value insert to the left 
        search_to_insert(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}
 
//Function To check for the deleted node 
void delete1(struct btnode *t, int data)
{
    if ((data>t->value))
    {
        t1 = t;
        delete1(t->r, data);
    }
    else if (data < t->value)
    {
        t1 = t;
        delete1(t->l, data);
    }
    else if (data==t->value)
    {
        delete2(t);
    }
    
    
}
 
//Function To delete a node
void delete2(struct btnode *t)
{
    int k;
 
    /* To delete leaf node */
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having one left hand child */
    else if (t->r == NULL)
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
 
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having right hand child */
    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having two child */
    else if ((t->l != NULL) && (t->r != NULL))  
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k =largest(t->l);
            flag = 2;
        }
        delete1(root, k);
        t->value = k;
    }
 
}
 
// Function to perform inorder traversal of tree 
void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)    
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)    
        inorder(t->r);
}
 
//Function To find the preorder traversal 
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}
 
//Function To find the postorder traversal 
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d -> ", t->value);
}

// To find the smallest element in the right side of tree
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }
    else    
        return (t->value);
}
 
// To find the largest element in the left side of tree
int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return(largest(t->r));
    }
    else    
        return(t->value);
}

void search(struct btnode *t, int item)
{
    struct btnode *save,*ptr;
    if (t == NULL)
    {
        LOC = NULL;
        PAR=NULL;
    }
    if (item == t -> value)
    {
    LOC = t;
    PAR = NULL;
    return;
    }
    if (item < t->value)
    {
        save = t;
        ptr = t->l;
    }
    else
    {
        save = t;
        ptr = t -> r;
    }
    while( ptr != NULL)
    {
        if (ptr -> value == item)
        {
            LOC = ptr;
            PAR = save;
            return;
        }
        if(item < ptr->value)
        {
            save = ptr;
            ptr = ptr->l;
        }
        else
        {
            save = ptr;
            ptr = ptr->r;
        }
    }
    LOC = NULL;
    PAR = save;
    return;
}

int main()
{
    int ch,data;
 
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Preorder Traversal\n");
    printf("5 - Postorder Traversal\n");
    printf("6 - Search\n");
    printf("7 - Exit\n");
    while(ch!=7)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            insert();
            break;
        case 2: 
         
         if (root == NULL)
         {
           printf("No elements in a tree to delete");
           break;
         }
         printf("Enter the data to be deleted : ");
         scanf("%d", &data);  
         t1 = root;
         t2 = root; 
            delete1(root,data);
            break;
        case 3:    
            inorder(root);
            break;
        case 4:    
            preorder(root);
            break;
        case 5:    
            postorder(root);
            break;
        case 6:
             if (root == NULL)
             {
                printf("No elements in a tree to search");
                break;
             }
              printf("Enter the data to be Searched : ");
              scanf("%d", &data);  
              search(root,data);
              if(LOC != NULL)
                    printf("\n%d Found in Binary Search Tree !!\n",data);
                else
                    printf("\nIt is not present in Binary Search Tree\n");
                    break;
        case 7:    
             printf("Exiting");
             break;
        default :     
            printf("Wrong choice, Please enter correct choice  ");
            break;    
        }
    }
    return 0;
}
 
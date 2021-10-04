#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
//Detecting loop
int detectLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    while (slow_p)
    {
        slow_p = slow_p->next;
        while(fast_p && fast_p->next)
        {
            fast_p = fast_p->next->next;
            if (slow_p == fast_p->next) 
         {
             printf("loop exists from %d to %d",fast_p->data,slow_p->data);
             return 1;
         }
         
        }
        
    } 
    printf("no loop");
 return 0;
}

//Create New Node
struct Node* newNode(int key)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
int main()
{
    struct Node* head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(20);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(40);
    //Creating loop of 2nd and last element
    head->next->next->next->next->next = head->next;
 
    detectLoop(head);
 
    return 0;
}
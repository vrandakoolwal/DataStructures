//-----Include required headers here-----
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----


//-----New functions end here-----

//-----A Doubly Linked List Node-----
// DO NOT MODIFY IT
struct DLLNode {
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
 
/* Representation of the stack data structure that supports findMiddle(),
   deleteMiddle() in O(1) time.  The Stack is implemented using Doubly 
   Linked List. It maintains pointer to head node, pointer to middle 
   node and count of nodes */
// DO NOT MODIFY IT
struct myStack {
    struct DLLNode *head;
    struct DLLNode *mid;
    int count;
};
 
//-----Function to create the stack data structure-----
// DO NOT uncomment the below function. It is for your reference purpose only.
// We will use this function to create the stack.
/*struct myStack *createMyStack() {
    struct myStack *ms = (struct myStack*) malloc(sizeof(struct myStack));
    ms->count = 0;
    ms->head = NULL;
    ms->mid = NULL;
    return ms;
}; */
 

//-----Function to push an element to the stack-----
void push(struct myStack *ms, int new_data) {
    /* allocate DLLNode and put in data */
    struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    new_DLLNode->data  = new_data;
    new_DLLNode->prev = NULL;
    new_DLLNode->next = ms->head;
    if (ms->head != NULL)
        ms->head->prev = new_DLLNode;
    
    ms->count +=1;
    
    if (ms->count == 1)
        ms->mid = new_DLLNode;
    else
    {
        if (ms->count % 2 == 1)
            ms->mid = ms->mid->prev;
    }
    ms->head = new_DLLNode;
    //-----code ends here-----
}
 
//-----Function to pop an element from stack. Return the popped element-----
//-----Will not be called for empty stack-----
int pop(struct myStack *ms) {
    struct DLLNode *head = ms->head;
    int item = head->data;
    
    //-----Appropriately update ms to get the required functionality-----
    ms->head = head->next;
    if (ms->head != NULL)
        ms->head->prev = NULL;
    if (ms->count == 1)
    {
        ms->mid = NULL;
    }
    else
    {
        if (ms->count % 2 == 1 )
            ms->mid = ms->mid->next;
    }
        
    ms->count -= 1;
    //head->next = NULL;
    //-----code ends here-----
    
    free(head);
 
    return item;
}
 
//-----Function for finding middle of the stack-----
//-----Will not be called for empty stack-----
int findMiddle(struct myStack *ms) {
    //-----code begins here-----
    return ms->mid->data;
    //-----code ends here-----
}

//-----Function for deleting middle of the stack-----
//-----Return the value deleted, will not be called for empty stack-----
int deleteMiddle(struct myStack *ms) {
    //-----code begins here-----
    
    
    int item = ms->mid->data;
    struct DLLNode *tempDeleteMiddle = ms->mid;
    if (ms->count == 1)
    {
        return pop(ms);
    }
    else if (ms->count == 2)
    {
        //cout<<"check 1\n";
        ms->mid = tempDeleteMiddle->prev;
        //cout<<"check 2\n";
        ms->mid->next = NULL;
        //cout<<"check 3\n";
    }
    else 
    {
        
        //cout<<"check 4\n";
        tempDeleteMiddle->prev->next = tempDeleteMiddle->next;
        //cout<<"check 5\n";
        tempDeleteMiddle->next->prev = tempDeleteMiddle->prev;
        //cout<<"check 6\n";
        if (ms->count % 2 == 1)
        {    //ms->mid = tempDeleteMiddle->next;
            ms->mid = tempDeleteMiddle->next;
        }    
        else
            // ms->mid = tempMid->prev;
            ms->mid = tempDeleteMiddle->prev;
    }
    ms->count -= 1;
    free(tempDeleteMiddle);
    return item;    
    
    //-----code ends here-----
}

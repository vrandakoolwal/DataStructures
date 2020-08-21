#include "header.h"
/* DON"T REMOVE OR CHANGE THE ABOVE HEADER
class twoStacks
{
	int *arr;// array has only non negative elements.
	int size;
	int top1;
    //top1 is index of the topmost element of stack1 and is -1 if stack1 is empty  
    int top2;
    // top2 is index of the topmost element of stack2 and is equal to size if stack2 is empty 
public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1; // note this initialization
		top2 = size;// note this initialization
	}
	bool push1(int i);//push i onto stack 1
	bool push2(int i);
	int pop1();// pop top element from stack 1
	int pop2();
    void double_resize();// resize the arr to double its current size
};
*/

/*
Function double_size() must double the size of the array by reallocating the array using the C++ operator new, and copy both the stacks into this newly created array.
It must also deallocate the dynamic memory previously allocated to the arr by using the keyword delete in C++
*/
void twoStacks::double_resize() {
	// WRITE YOUR CODE HERE
	int doubleSize=size*2;
	
    int* array2 = new int[doubleSize];
    //Copy stack1 in the front and copy stack2 at the end
    for (int i=0; i<=top1; i++)
        array2[i] = arr[i];
    
    int newTop2 = doubleSize - size + top2;
    int i,j;
    for ( i= size-1, j=doubleSize-1; i >= top2, j>=newTop2; i--, j--)
    {
        array2[j] = arr[i];
    }
     size = doubleSize;
    top2 = newTop2;
    //Delete old array
    delete arr;
    arr = array2;
    
}


/*
	If stack1 is not full then the function push1(int i) should add element i into stack1 and return true. 
	Else it should return false
*/
bool twoStacks::push1(int i) {
	//WRITE YOUR CODE HERE
	if (top1 + 1 == top2)
	    return false;
	else
	{
	    arr[++top1] = i;
	    return true;
	}
	
	
	// RETURN A BOOLEAN VALUE HERE
}

/*
	If stack2 is not full then the function push2(int i) should add element i into stack2 and return true. 
	Else it should return false
*/

bool twoStacks::push2(int i) {
	//WRITE YOUR CODE HERE
    if (top1 + 1 == top2)
        return false;
    else
    {
        arr[--top2] = i;
        return true;
    }

	// RETURN A BOOLEAN VALUE HERE
}

/*
If stack1 is not empty then the function pop1() should pop the top most element from the stack and return its value.
If stack1 is empty then the function pop1() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop1() {
	// FUNCTION MUST RETURN AN INTEGER VALUE
	//WRITE YOUR CODE HERE
	if (top1 == -1)
	    return -1;
	else
	{
	    top1--;
	    return arr[top1+1];
	}
    
}



/*
If stack2 is not empty then the function pop2() should pop the top most element from the stack and return its value.
If stack2 is empty then the function pop2() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop2() {
	// FUNCTION MUST RETURN AN INTEGER VALUE
	//WRITE YOUR CODE HERE
    if (top2 == size)
        return -1;
    else
    {
        top2++;
        return arr[top2-1];
    }

}
# DataStructures
<br>
<h3> This repository is the codes that I made (Practice as well as Assignments) while i studied the online course on Data Structures and Algorithms by IIT Bombay.</h3>

<h4> Following are the questions of the assignments</h4>

<ol>
<li>BinaryAndGrayInterconversion.cpp</li>
<p>
Your task is to complete the following functions in student.cpp
<b>/* Question : Function to convert a given binary string to gray code string
 as explained in the problem description. */</b>
string binarytoGray(string binary) { 
 // Write your code below this line. 
}  

<b>/* Question : Function to convert a gray code string to binary string
 as explained in the problem description. */ </b>
string graytoBinary(string gray) { 
 // Write your code below this line. 
}
</p>

<li>TwoStackUsingOneArray.cpp</li>
<p>
It is possible to implement a stack data structure using an array.

In this exercise we efficiently implement two stacks in a single array.

Our implementation should use only one array, i.e., both stacks should use the same array for storing elements. Following functions must also be supported.

push1(int x) –> pushes x to first stack
push2(int x) –> pushes x to second stack

pop1() –> pops an element from first stack and return the popped element
pop2() –> pops an element from second stack and return the popped element

See below for a more detailed description of the above functions

Our Implementation of the two stacks  should be space efficient.

The idea is to start two stacks from two extreme corners of the array. stack1 starts from the leftmost element, the first element in stack1 is pushed at index 0. The stack2 starts from the rightmost corner, the first element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) in opposite direction.

To check for overflow, all we need to check is for space between top elements of both stacks.

You will be implementing few functions related to this data structure twoStacks.

twoStacks is a class in our code. Its declaration is hidden from you in codeboard. However, it is commented.

<ul>  
<li>top1 represents the index of the topmost element of stack1 and is -1 if stack1 is empty and top2 is index of the topmost element of stack2 and is equal to size if stack2 is empty .
Note that stack1 or stack2 is full whenever there is no more space in arr to allocate a new element for either one of them.
That is, when number of elements in stack1 + number of elements in stack2 = size. </li>
<li>If stack1 is not full then the function push1(int i) should add element i into stack1 and return true.
Else it should return false; </li>
<li>Similarly push2 must also be defined. </li>
<li>If stack1 is not empty then the function pop1() should pop the top most element from the stack and return its value.
If stack1 is empty then the function pop1() must return -1 </li>
<li>Note that you may assume that all the elements of arr are non-negative.</li>
<li>Function double_resize() must double the size of the array by reallocating the array using the C++ operator new, and copy both the stacks into this newly created array.</li>
<li>It must also deallocate the dynamic memory previously allocated to the arr by using the keyword delete in C++</li>
</p>
</ul>
<li>linesIntersect.cpp</li>
<p>You are expected to write the code of a function which takes two line segments as input and return true if the line segments are intersecting and false if not.

You are required to Write A function :
Function Name : SegIntersect

This function has two parameters:

LineSeg l1 :  First line segment with its end-points given.
LineSeg l2 :  Second line segment with its end-points given.
The function should do the following

It should take two line segments as its parameters and find out whether the line segments are intersecting.
If they are intersecting , the function must return true else it must return false.</p>

<li>StackWithOperationsOnMiddleElement.cpp</li>
<p>We want to implement a stack which will support following operations. We need all the operations in O(1) time complexity.

1) push( ) which adds an element to the top of stack.
2) pop( ) which removes an element from top of stack.
3) findMiddle( ) which will return middle element of the stack.
4) deleteMiddle( ) which will deletes the middle element of the stack.

A stack implementation with a different design serves this purpose. Part of the implementation is done to guide you, fill in the appropriate snippets to get a working data structure.  For even size stacks, the first of the two middle elements is expected as return value of findMiddle( ).

So which data structure to use for implementing this special stack?

If we use a singly linked list, we may need to move the middle pointer up when we push an element and move down when we pop(). In singly linked list, moving middle pointer in both directions is not possible.

So, the idea is to use Doubly Linked List (DLL). We can find middle element in O(1) time by maintaining mid pointer. We can move mid pointer in both directions using previous and next pointers.</p>

#include <iostream>
using namespace std;
#define MAXSIZE 3
//Stack Definiton--->
struct Stack
{
	char arr[MAXSIZE];
	int size;
}; typedef Stack Stack;

//Functions--->
void initialiseStack(Stack *S)
{
	S->size=0;
}

bool isEmpty(Stack *S)
{
	return (S->size==0);
}
bool isFull(Stack *S)
{
	return (S->size == MAXSIZE);
}
bool Top(Stack *S, char &element)
{
	if (isEmpty(S))
		return false;
	element=S->arr[S->size-1];
	return true;
}
bool Push(Stack *S, char element)
{
	if (isFull(S))
		return false;
	S->arr[S->size++] = element;
	return true;
}
bool Pop(Stack *S, char &element)
{
	if (isEmpty(S))
		return false;
	S->size--;
	element = S->arr[S->size];
	return true;
}

int main()
{
	Stack S1;
	char element;

	initialiseStack(&S1);

	if (isEmpty(&S1))
		cout<<"Empty Stack\n";
	else
		cout<<"Error: Stack is not Empty\n";

	for (int i=1; i<=5; i++)
	{
		cin>>element;
		if (Push(&S1, element))
			cout<<"Element "<< element <<" succesfully pushed\n";
		else
		{
			cout<<"Error: Stack is full\n";
			break;
		}

	}

	if (Top(&S1, element))
		cout<<"Topmost element: "<<element<<endl;
	else
		cout<<"Error: Empty Stack"<<endl;

	for (int i=0; i<=5; i++)
	{
		if (Pop(&S1, element))
			cout<<"Element "<< element <<" succesfully popped\n";
		else
		{
			cout<<"Error: Stack is empty\n";
			break;
		}
	}


}
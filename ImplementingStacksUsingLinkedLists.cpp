#include <iostream>
using namespace std;
struct Node
{
	char info;
	Node *next; 
};
struct Stack
{
	Node *top;

}; typedef Stack Stack;

void Initialise(Stack *S)
{
	S->top = NULL;
}
bool IsEmpty(Stack *S)
{
	return (S->top == NULL);
}
bool Top(Stack *S, char &element)
{
	if (IsEmpty(S))
		return false;
	element = S->top->info;
	return true;
}

bool Push(Stack *S, char value)
{
	Node *temp;
	temp = (Node *) malloc(sizeof(Node));
	temp->info = value;

	if (S->top != NULL)
	{
		temp->next = S->top;
		S->top = temp;
	}
	else
	{
		S->top = temp;
		S->top->next = NULL;
	}
	return true;
}
bool Pop(Stack *S, char &value)
{
	Node *temp;
	if (IsEmpty(S))
		return false;
	else
	{
		temp = S->top;
		S->top = S->top->next;
		value = temp->info;
		free(temp);
		return true;
	}
}
int main()
{
	Stack S;
	char element;
	Initialise (&S);

	if (IsEmpty(&S) == true)
		cout<<"Empty Stack\n";

	element = 'F';
	if (Push( &S, element) == true)
		cout<<"element pushed.\n";
	element = 'R';
	if (Push( &S, element) == true)
		cout<<"element pushed.\n";
	element = 'T';
	if (Push( &S, element) == true)
		cout<<"element pushed.\n";
	if (Pop(&S, element) == true)
		cout<<"element popped. \n";
	Top(&S, element);
	cout<<element<<endl;

}
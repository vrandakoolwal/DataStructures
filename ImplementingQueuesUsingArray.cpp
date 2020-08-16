#include <iostream>
using namespace std;
#define MAX_SIZE 3
struct Queue
{
	char arr[MAX_SIZE];
	int size;
}; typedef Queue Queue;
void initialiseQueue(Queue *Q)
{
	Q->size = 0;
}
bool isEmpty(Queue *Q)
{
	return (Q->size == 0);
}
bool isFull(Queue *Q)
{	
	return (Q->size == MAX_SIZE);
}
bool inspectFront(Queue *Q, char &element)
{
	if (isEmpty(Q))
		return false;

	else
	{
		element = Q->arr[Q->size-1];
		return true;
	}
}
bool Insert(Queue *Q, char element)
{
	if (isFull(Q))
		return false;

	else 
	{
		for (int i = Q->size; i>0; i--)
		{
			Q->arr[i] = Q->arr[i-1];
		}
		Q->arr[0] = element;
		Q->size++;
		return true;
	}

}
bool removeFront(Queue *Q, char &element)
{
	if (isEmpty(Q))
	{
		return false;
	}

	else
	{
		element = Q->arr[Q->size-1];
		Q->size--;
		return true;
	}
}
int main()
{
	Queue Q1;
	char element;
	initialiseQueue(&Q1);
	if (isEmpty(&Q1) == true)
		cout<<"Empty Queue\n";
	element ='F';
	//Insert element
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";

	element = 'R';
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";

	element = 'U';
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";

	element = 'P';
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	//Front element
	if (inspectFront(&Q1, element) == true)
		cout<<"Topmost element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	//Popping element
	if (removeFront(&Q1, element) == true)
		cout<<"Element: "<<element<<" popped\n";
	else
		cout<<"Element can't be popped\n";




}
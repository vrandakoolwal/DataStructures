#include <iostream>
using namespace std;
struct Node
{
	char info;
	Node *next; 
};
struct Queue
{
	Node *front;
}; typedef Queue Queue;
void initialiseQueue(Queue *Q)
{	
	Q->front = NULL;
}
bool isEmpty(Queue *Q)
{
	return (Q->front == NULL);
}
bool inspectFront(Queue *Q, char &element)
{
	if (isEmpty(Q))
		return false;
	else
	{
		element = Q->front->info;
		return true;
	}
}
bool Insert(Queue *Q, char value)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->info = value;

	if (Q->front == NULL)
	{
		temp->next = NULL;
		Q->front = temp;
	}
	else
	{
		struct Node *temp1;
		temp1 = Q->front;
		
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;

	}
	return true;
}
bool removeFront(Queue *Q, char &element)
{
	if (isEmpty(Q))
		return false;
	else
	{
		struct Node *temp;
		temp = Q->front;
		Q->front = Q->front->next;
		element = temp->info;
		free(temp);
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

	cin>>element;
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	element = 'P';
	if (Insert(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	// Front element
	if (inspectFront(&Q1, element) == true)
		cout<<"Topmost element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	//Popping element
	if (removeFront(&Q1, element) == true)
		cout<<"Element: "<<element<<" popped\n";
	else
		cout<<"Element can't be popped\n";

	

	if (removeFront(&Q1, element) == true)
		cout<<"Element: "<<element<<" popped\n";
	else
		cout<<"Element can't be popped\n";

	if (removeFront(&Q1, element) == true)
		cout<<"Element: "<<element<<" popped\n";
	else
		cout<<"Element can't be popped\n";

}
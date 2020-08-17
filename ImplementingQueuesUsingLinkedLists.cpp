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
bool enqueue(Queue *Q, char value)
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
bool dequeue(Queue *Q, char &element)
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
	//enqueue
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" enqueued\n";
	else
		cout<<"Element can't be enqueued\n";

	element = 'R';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" enqueued\n";
	else
		cout<<"Element can't be enqueued\n";

	element = 'Y';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" enqueued\n";
	else
		cout<<"Element can't be enqueued\n";

	element = 'P';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" enqueued\n";
	else
		cout<<"Element can't be enqueued\n";
	// Front element
	if (inspectFront(&Q1, element) == true)
		cout<<"Topmost element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	//dequeue
	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";

	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";

	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";

}
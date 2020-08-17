#include <iostream>
using namespace std;
struct CircularQueueNode
{
	char info;
	CircularQueueNode *next;
};
struct CircularQueue
{
	CircularQueueNode *head;
	CircularQueueNode *tail;
};
void initialiseCircularQueue(CircularQueue *Q)
{	
	Q->head = NULL;
	Q->tail = NULL;
}
bool isEmpty(CircularQueue *Q)
{
	if (Q->head == NULL && Q->tail == NULL)
		return true;
	else 
		return false;
}
bool enqueue(CircularQueue *Q, char element)
{
	struct CircularQueueNode *temp;
	temp = (struct CircularQueueNode *)malloc(sizeof(CircularQueueNode));
	temp->info = element;
	if (Q->head == NULL && Q->tail == NULL)
	{
		temp->next = temp;
		Q->head = temp; 
		Q->tail = temp;
	}

	else
	{
		struct CircularQueueNode *temp1;
		temp1 = Q->head;
		while (temp1->next != Q->tail->next)
		{
			temp1 = temp1->next;
		} 
		temp1->next = temp;
		Q->tail = temp;
		temp->next = Q->head;
	}
	return true;
}

bool inspectFront(CircularQueue *Q, char &element)
{
	if (isEmpty(Q))
		return false;
	else
	{
		element = Q->head->info;
		return true;
	}
}

bool dequeue(CircularQueue *Q, char &element)
{
	if (isEmpty(Q))
		return false;
	else
	{
		struct CircularQueueNode *temp;
		temp = Q->head;
		element = temp->info;
		Q->head = temp->next;
		free(temp);
		return true;
	}
}

int main()
{
	CircularQueue Q1;
	char element;
	initialiseCircularQueue(&Q1);
	if (isEmpty(&Q1) == true)
		cout<<"Empty Queue\n";
	if (inspectFront(&Q1, element) == true)
		cout<<"Head element = " << element<<endl;
	else
		cout<<"No head element\n";
	//ENQUEUE;
	element ='F';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	element ='R';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	element ='Y';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	
	element ='P';
	if (enqueue(&Q1, element) == true)
		cout<<"Element "<<element <<" pushed\n";
	else
		cout<<"Element can't be pushed\n";
	//HEAD ELEMENT;
	if (inspectFront(&Q1, element) == true)
		cout<<"Head element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	//DEQUEUE;
	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";
	if (inspectFront(&Q1, element) == true)
		cout<<"Head element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";
	if (inspectFront(&Q1, element) == true)
		cout<<"Head element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
	if (dequeue(&Q1, element) == true)
		cout<<"Element: "<<element<<" removed\n";
	else
		cout<<"Element can't be removed\n";
	if (inspectFront(&Q1, element) == true)
		cout<<"Head element = " << element<<endl;
	else
		cout<<"Empty Queue\n";
}
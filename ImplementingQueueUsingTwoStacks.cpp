#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 5
struct Queue
{
	stack <int> inStack, outStack;
	void enqueue(int x)
	{
		inStack.push(x);
	}
	void move()
	{
		while (!inStack.empty())
		{
            outStack.push(inStack.top());
            inStack.pop();
		}
	}
	int dequeue()
	{
		int item;
		if (outStack.empty() == true)
			move();
		item = outStack.top();
		outStack.pop();
		return item;
	}
	int front()
	{
	    int item;
	    if (outStack.empty() == true)
			move();
	    return outStack.top();
	}
};
int main()
{
	Queue Q1;
	Q1.enqueue(3);
	Q1.enqueue(4);
	Q1.enqueue(5);
	cout<<"front "<<Q1.front()<<endl;
	cout<<Q1.dequeue()<<endl;
	cout<<Q1.dequeue()<<endl;
	cout<<Q1.dequeue()<<endl;
}
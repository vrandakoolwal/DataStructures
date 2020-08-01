#include <iostream>
#include <math.h>
using namespace std;

struct point 
	{
		int x, y;
	};
	struct triangleCoordinates
	{
		point p[3];
	};
	void getCoordinates(point &p)
	{
		cin>>p.x>>p.y;
	}
	void getVertex (triangleCoordinates &t)
	{
		for (int i=0; i<3; i++)
		{	
			
			getCoordinates(t.p[i]);
		}
	}
	float calculateArea(triangleCoordinates t)
	{
		float area = 0.5*abs(t.p[0].x*(t.p[1].y - t.p[2].y) + t.p[1].x*(t.p[2].y - t.p[0].y) + t.p[2].x*(t.p[0].y - t.p[1].y));
		return area;
	}

int main()
{
	triangleCoordinates t;
	
		
		getVertex(t);
		cout<<"Area: "<<calculateArea(t)<<endl;	
	
}
/*
struct side
{
	int length;
};
struct triangleSide
{
	side s[3];	
};
void getLength(side &s)
{
	cin>>s.length;
}
void getSides (triangleSide &t)
{
	for (int i=0; i<3; i++)
		getLength(t.s[i]);
}
float calculateArea(triangleSide t)
{
	float semiPerimeter = 0.5 *(t.s[0].length + t.s[1].length + t.s[2].length);
	float area = sqrt(semiPerimeter*(semiPerimeter-t.s[0].length)*(semiPerimeter-t.s[1].length)*(semiPerimeter-t.s[2].length));
	return area;
}
int main()
{
	triangleSide s;
	getSides(s);
	cout<<"Area: "<<calculateArea(s)<<endl;
}
*/
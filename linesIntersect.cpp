#include <iostream>
using namespace std;
class Point {
public:
 int x,y; 
};
class LineSeg {
public:
    Point p1,p2;
};
bool onSegment(Point p ,Point q, Point r, Point s)
{
	if (((min(r.y, s.y) > min (p.y, q.y) && min(r.y, s.y) < max(p.y, q.y))) ||
		 (min(p.y, q.y) > min (r.y, s.y) && min(p.y, q.y) < max(r.y, s.y))  ||
		 (min(r.x, s.x) > min (p.x, q.x) && min(r.x, s.x) < max(p.x, q.x))  ||
		 (min(p.x, q.x) > min (r.x, s.x) && min(p.x, q.x) < max(r.x, s.x)))
		return true;
	else
		return false;
}
bool SegIntersect(class LineSeg l1,class LineSeg l2)
{
	if ((l1.p1.x == l2.p1.x && l1.p1.y == l2.p1.y) || (l1.p1.x == l2.p2.x && l1.p1.y == l2.p2.y) || 
		(l1.p2.x == l2.p1.x && l1.p2.y == l2.p1.y) || (l1.p2.x == l2.p2.x && l1.p2.y == l2.p2.y))
		return true;
	else 
	{
		float slopel1, slopel2;
		if (l1.p2.x - l1.p1.x == 0 && l2.p2.x-l2.p1.x == 0)
		{
			if (onSegment(l1.p1, l1.p2, l2.p1, l2.p2)  && l1.p1.x == l2.p1.x)
				return true;
			else 
				return false;
		}
		if (l1.p2.x - l1.p1.x == 0)
		{
			slopel2 = ((float)l2.p2.y-l2.p1.y)/(l2.p2.x-l2.p1.x);
			if (//(slopel2*(l1.p1.x - l2.p1.x) + l2.p1.y - l1.p1.y ==0 || slopel2*(l1.p1.x - l2.p2.x) + l2.p2.y - l1.p1.y ==0))
				onSegment(l1.p1, l1.p2, l2.p1, l2.p2))
				return true;
			else
				return false;

		}
		
		else if (l2.p2.x-l2.p1.x == 0)
		{
			slopel1 = ((float)l1.p2.y-l1.p1.y)/(l1.p2.x-l1.p1.x);
			if ((slopel1*(l2.p1.x - l1.p1.x) + l1.p1.y - l2.p1.y ==0) &&
				onSegment(l1.p1, l1.p2, l2.p1, l2.p2))

				return true;
			else
				return false;
		}
		
		else

		{
			slopel1 = ((float)l1.p2.y-l1.p1.y)/(l1.p2.x-l1.p1.x);
			slopel2 = ((float)l2.p2.y-l2.p1.y)/(l2.p2.x-l2.p1.x);

			if (slopel1 == slopel2)
			{
				//checking if collinear points lie on the line segment
				
				if (((slopel1*(l2.p1.x - l1.p1.x) + l1.p1.y - l2.p1.y)>=0 && (slopel1*(l2.p1.x - l1.p1.x) + l1.p1.y - l2.p1.y) < 0.1) && 
					onSegment(l1.p1, l1.p2, l2.p1, l2.p2))
					return true;
				else
					return false;
				
			}
			else
			{	
				if(((slopel1*(l2.p1.x - l1.p1.x) + l1.p1.y - l2.p1.y)*(slopel1*(l2.p2.x - l1.p1.x) + l1.p1.y - l2.p2.y) <= 0) &&
					(slopel2*(l1.p1.x - l2.p1.x) + l2.p1.y - l1.p1.y)*(slopel2*(l1.p2.x - l2.p1.x) + l2.p1.y - l1.p2.y) <= 0)
					return true;
				else 
					return false;
			}
		}
	}
	
}

int main()
{
	LineSeg l1;
	l1.p1.x=17;
	l1.p1.y=3;
	l1.p2.x=17;
	l1.p2.y=19;

	LineSeg l2;
	l2.p1.x=18;
	l2.p1.y=11;
	l2.p2.x=17;
	l2.p2.y=17;

	cout<<SegIntersect(l1, l2)<<endl;
	//-0.111111
}
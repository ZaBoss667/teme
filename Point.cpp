#include <iostream>
#include <math.h>

using namespace std;
class Point
{
    private:
    	int coord_x;
		int coord_y;//the coordinates of a point

	public:
	Point() {};
	Point (int x, int y)
	{
		this->coord_x = x;
		this->coord_y = y;
	}

	int getX()
	{
		return this->coord_x;
	}

	int getY()
	{
		return this->coord_y;
	}

    void reset() //places the point into the origin
    {
        coord_x = coord_y = 0;
    }
    void moveX(int x)
	{
	    coord_x=coord_x+x;
 	} //moves the point horizontally with x positions

    void moveY(int y)
	{
	    coord_y=coord_y+y;
     } // moves the point vertically with y positions

    void moveXY(int x , int y)
	{
	    coord_x=coord_x+x;
		coord_y=coord_y+y;
	}// moves the point horizontally and vertically
};

int main(void) {
	Point p(7,10);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	p.moveX(-3);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	p.moveY(5);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	p.moveXY(2,4);
	cout<<p.getX()<<" "<<p.getY()<<endl;

    return 0;
  }

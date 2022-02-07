#include "ccc_win.h"
#include <iostream>

using namespace std;

class Chutist
{
	public:
		Chutist();
		Chutist(Point loc);
		void display(int i) const;
		void move(int dx, int dy);
	private:
		Point location;
};

Chutist::Chutist()
{
	location=Point(0,0);
}

Chutist::Chutist(Point loc)
{
	location=loc;
}

void Chutist::display(int i) const
{
	Line Body=Line(location,Point(location.get_x(),location.get_y()-8));
	Point Arm1=Point(location.get_x()-3,location.get_y()-3);
	Point Arm2=Point(location.get_x()+3,location.get_y()-3);
	Line Arms=Line(Arm1,Arm2);
	
	cwin<<Body<<Arms;

	if(i<0)
	{
		Point Point1=Point(location.get_x()-4,location.get_y()+4);
		Point Point2=Point(location.get_x()+4,location.get_y()+4);
		Line Chute1=Line(location,Point1);
		Line Chute2=Line(location,Point2);
		Line Chute3=Line(Point1,Point2);

		cwin<<Chute1<<Chute2<<Chute3;
	}

}

void Chutist::move(int dx,int dy)
{
	location.move(dx,dy);
}

int ccc_win_main()
{
	cwin.coord(0,1000,1000,0);
	int velocity=32;
	int downwardvelocity=17;
	int terminalvelocity=174;
	int secondsToOpen=cwin.get_int("Enter the  seconds the chute will open:");
	
	int clock;

	int x=500;
	int alt=999;
	Chutist Bob=Point(x,alt);

	while(alt>=0)
	{
		Bob.display(secondsToOpen);

		//cwin<<Bob;

		if(secondsToOpen<=clock)
		{
			velocity-=100;
			if(velocity<0)
			{
				velocity=downwardvelocity;
			}
		}
		else
		{
			velocity+=32;
			if(velocity>=terminalvelocity)
			{
				velocity=terminalvelocity;
			}

		}
			
		alt-=velocity;
			
		Bob.move(0,velocity);

		secondsToOpen--;		
	}

	Message(Point(250,250),"You made it :)");

	return 0;
}


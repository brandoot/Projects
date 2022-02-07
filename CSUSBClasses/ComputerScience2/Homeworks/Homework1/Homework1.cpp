//Brandon Deo
//Homework1

#include "ccc_win.h"
#include <iostream>

using namespace std;

class Chutist
{
	public:
		Chutist();
		Chutist(Point loc);
		void display(int i) const;
		void move(int dx,int dy);
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
	Line Body=Line(location,Point(location.get_x(),location.get_y()-40));
	Point Arm1=Point(location.get_x()-15,location.get_y()-15);
	Point Arm2=Point(location.get_x()+15,location.get_y()-15);
	Line Arms=Line(Arm1,Arm2);

	cwin<<Body<<Arms;

	if(i<0)
	{
		Point Point1=Point(location.get_x()-20,location.get_y()+20);
		Point Point2=Point(location.get_x()+20,location.get_y()+20);
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

	int alt=cwin.get_int("What is the height of the plane:");
	int speedofplane=cwin.get_int("How fast is the plane moving:");
	int secondsToOpen=cwin.get_int("Enter seconds to open chute:");

	int velocity=32;
	int downwardvelocity=17;
	int terminalvelocity=174;
	int drag=20;

	int clock;

	int x=0;

	Chutist Bob=Point(x,alt);

	while(alt>=0)
	{
	 	Bob.display(secondsToOpen);

		Bob.move(x+speedofplane,0);

		if(secondsToOpen<=clock)
		{
			velocity-=100;
			if(velocity<0)
			{
				velocity=downwardvelocity;
			}
			
			speedofplane-=drag;

			if(speedofplane<0)
			{
				speedofplane=0;
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

		Bob.move(0,-velocity);

		secondsToOpen--;
	}

	Message(Point(500,500),"You made it :)");
	Message(Point(400,400),velocity);

	return 0;

}

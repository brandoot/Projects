/* Brandon Deo
 * Lab 2 Fall
 * This program drops an objects and descends faster
 */

#include "ccc_win.h"

int ccc_win_main()
{
	int secondstoopen=cwin.get_int("Please enter in the seconds to open the parachute:");
	
	cwin.coord(0,1100,1100,0);

	int clock=0;
	int alt=999;
	int px=500;

	int velocity=32;
	int terminalvelocity=174;
	int downwardvelocity=17;	

	Point x(px,alt);
	
	while(alt>=0)
	{
		cwin<<x;

		if(clock>=secondstoopen)
		{	
			velocity-=100;
			if(velocity<downwardvelocity)
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

		x.move(0,-velocity);

		clock++;

	}

	cwin<<Message(Point(200,200),"You made it");

	return 0;

}

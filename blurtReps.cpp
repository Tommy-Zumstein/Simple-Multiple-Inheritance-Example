//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtReps.cs
//DATE: 2/22/17
/*REVISION HISTORY:
1/21/16:
-changed MAXPINGS to 10
-added isActive function
-updated documentation
2/22/17:
-translated into C++
-changed state to int
*/
//PLATFORM:
//REFERENCES:

#include "blurtReps.h"

using namespace std;

const string blurtReps::UNSUCCESSFULPING = "Ping Unssuccessful, Inactive blurtRep";

//Blank Constructor
blurtReps::blurtReps()
{
	blurtString = "";
	state = PLAINSTATE;
	repCount = 0;
	pingCount = 0;
	active = false;
	srand(time(0));
}

//Constructor
/*Preconditions:
inBlurtString must be of < 5 characters
inState must be 1, 2, or 3
inRepCount must be >= 0 */
blurtReps::blurtReps(string inBlurtString, int inState, int inRepCount)
{
	blurtString = inBlurtString;
	state = inState;
	repCount = inRepCount;
	pingCount = 0;
	active = true;
	srand(time(0));
}

//Deconstructor
blurtReps::~blurtReps()
{
	//No heap memory used
}

//Ping
/*Description: Generates and returns a string based on state, increments pingCount,
and sets objects to inactive if pingCount exceeds MAXPINGS.
At the end of a successful ping the object is randomly assigned a new state.
Active objects have 3 possible output states:
Plain - returns blurtstring
Repeat - returns blurtString repeated repCount times
Terse - returns blurtString truncated by repCount characters
Example:
blurtString = "Cast" and repCount = 2
state = plain => Cast
state = repeat => CastCast
state = terse => Ca
Inactive objects return:
"Ping Unssuccessful, Inactive blurtRep"
*/
//Postcondition: state may be changed
string blurtReps::ping()
{
	string pingOutput = "";
	int truncLength = 0;
	if (active)
	{
		//Active outputs
		if (state == PLAINSTATE)
		{
			pingOutput = blurtString;
		}
		else if (state == REPEATSTATE)
		{
			for (int i = 0; i < repCount; i++)
			{
				pingOutput += blurtString;
			}
		}
		else
		{
			truncLength = blurtString.length() - repCount;
			if (truncLength < 0)//If truncated length is negative just returns an empty string
			{
				truncLength = 0;
			}

			if (blurtString.length() > truncLength)
			{
				pingOutput = blurtString.substr(0, truncLength);
			}
		}

		//State change
		chngState();

		//Ping increment and check
		pingCount++;
		if (pingCount >= MAXPINGS)
		{
			active = false;
		}

	}
	//Inactive output
	else
	{
		pingOutput = UNSUCCESSFULPING;
	}

	return pingOutput;
}

//getPingCount
int blurtReps::getPingCount()
{
	return pingCount;
}

//isActive
bool blurtReps::isActive()
{
	return active;
}

//reset 
//Decription: resets a blurtRep object's pingCounter and activates it for output
void blurtReps::reset()
{
	pingCount = 0;
	active = true;
}

//chngState
//Decription: helper function to ramdomly change state
void blurtReps::chngState()
{
	state = rand() % 3 + 1;
}
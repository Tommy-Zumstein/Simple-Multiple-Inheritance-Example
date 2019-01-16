//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtReps.h
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

/*DESCRIPTION:
blurtReps is a example of a data sink, that yeilds specific output upon query or "ping"
but can age and become inactive over a certain number of queries or "pings".
Each blurtReps contains a:
-string of data < 5 characters long (blurtString)
-int that holds state (state)
-legal states:
-1 = "plain"
-2 = "repeat"
-3 = "terse"
-repeat count for output (repCount)
-number of times this object has been pinged (pingCount)
-output controller (active)
-legal active states:
-true
-false
*/

/*Assumptions:
Class Invarients:
Input data must be validated before construction.
blurtReps become inactive after MAXPINGS pings.
blurtReps objects are randomly assigned a new state after being pinged.

Interface Invarients: 
Copy not supported
Outputs UNSUCCESSFULPING if object is pinged whe inactive
Default Values:
blurtString = ""
state = PLAINSTATE
repCount = 0
pingCount = 0 
active = false
*/

#ifndef BLURTREPS_H_
#define BLURTREPS_H_

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class blurtReps
{
protected:
	static const int MAXPINGS = 10;
	static const int PLAINSTATE = 1;
	static const int REPEATSTATE = 2;
	static const int TERSESTATE = 3;
	static const string UNSUCCESSFULPING;
	string blurtString;
	int state;
	int repCount;
	int pingCount;
	bool active;

public:
	//Constructor
	blurtReps();
	/*Preconditions:
	inBlurtString must be of < 5 characters
	inState must be 1, 2, or 3
	inRepCount must be >= 0 */
	blurtReps(string, int, int);
	//Destructor
	~blurtReps();
	//BlurtReps functionality
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
	virtual string ping();
	virtual int getPingCount();
	virtual bool isActive();
	//Decription: resets a blurtRep object's pingCounter and activates it for output
	virtual void reset();

private:
	//Helper Functions
	//Decription: ramdomly changes state
	void chngState();
};
#endif
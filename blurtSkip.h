//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtSkip.h
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtGen object and a skipGen object using multiple inheritance.
it generates the output of both blurtReps and skipGen through combinedOuput.
if both either the skipGen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both skipGen and blurtReps.
refer to skipGen and blurtReps documentation for more info.
*/

/*Assumption:
Class Invarients:
Valid types must be passed into constructor
The constructor of this class constructs the inherited skipGen and blurtReps data members
if both either the skipGen or blurtReps functionality become inactive this object becomes inactive.

Default Values:
active = false
blurtString = ""
state = PLAINSTATE (1, inherited from blurtReps)
repCount = 0
pingCount = 0
blurtReps::active = false
skipGen::active = false;
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = SKIP_INDX_INIT_VAL (1, inherited from skipGen)
skipVal = 0

Interface Invarients:
combinedOutput should be the only output function used for this object
inherited functions skipGen::getNext and blurtReps::ping should not be used by the client
*/

#ifndef BLURTSKIP_H_
#define BLURTSKIP_H_

#include "skipGen.h"
#include "blurtGens.h"

class blurtSkip : public skipGen, public virtual blurtGens
{
private:
	bool active;
public:
	//Constructor
	blurtSkip(string, int, int, int, int, unsigned int, unsigned int);
	//Deconstructor
	~blurtSkip();

	string combinedOutput();
	void reset();
};
#endif
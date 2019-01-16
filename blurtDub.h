//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtDub.h
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtGen object and a dubGen object using multiple inheritance.
it generates the output of both blurtReps and dubGen through combinedOuput.
if both either the dubGen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both dubGen and blurtReps
refer to gen and blurtReps documentation for more info.
*/

/*Assumption:
Class Invarients:
Valid types must be passed into constructor
The constructor of this class constructs the inherited dubGen and blurtReps data members
if both either the dubGen or blurtReps functionality become inactive this object becomes inactive.

Default Values:
active = false
blurtString = ""
state = PLAINSTATE (1, inherited from blurtReps)
repCount = 0
pingCount = 0
blurtReps::active = false
dubGen::active = false;
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = GEN_INDX_INIT_VAL (1, inherited from gen)
seqDoubler = 0

Interface Invarients:
combinedOutput should be the only output function used for this object
inherited functions dubGen::getNext and blurtReps::ping should not be used by the client
*/

#ifndef BLURTDUB_H_
#define BLURTDUB_H_

#include "dubGen.h"
#include "blurtGens.h"

class blurtDub : public dubGen, public virtual blurtGens
{
private:
	bool active;
public:
	//Constructor
	blurtDub(string, int, int, int, int, unsigned int, unsigned int);
	//Deconstructor
	~blurtDub();

	string combinedOutput();
	void reset();
};
#endif
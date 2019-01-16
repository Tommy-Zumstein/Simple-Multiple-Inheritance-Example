//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtGens.h
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtRep object and a gen object using multiple inheritance.
it generates the output of both blurtReps and gen through combinedOuput.
if both either the gen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both gen and blurtReps.
refer to gen and blurtReps documentation for more info.
*/

/*Assumption: 
Class Invarients:
Valid types must be passed into constructor
The constructor of this class constructs the inherited gen and blurtRep data members
if both either the gen or blurtReps functionality become inactive this object becomes inactive.

Default Values:
active = false
blurtString = ""
state = PLAINSTATE (1, inherited from blurtReps)
repCount = 0
pingCount = 0
blurtReps::active = false
gen::active = false;
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = GEN_INDX_INIT_VAL (1, inherited from gen)

Interface Invarients:
combinedOutput should be the only output function used for this object
inherited functions gen::getNext and blurtReps::ping should not be used by the client
*/

#ifndef BLURTGENS_H_
#define BLURTGENS_H_

#include <sstream>
#include <string>
#include "gen.h"
#include "blurtReps.h"

class blurtGens : public gen, public blurtReps
{
private:
	bool active;
public:
	//Constructor
	blurtGens();
	/*Preconditions:
	inBlurtString must be of < 5 characters
	inState must be 1, 2, or 3
	inRepCount must be >= 0 */
	blurtGens(string, int, int, int, int, unsigned int);
	//Deconstructor
	~blurtGens();

	//Description: Returns both outputs from gen and blurtReps as a single string
	//Post-condition: blurtGens object may be inactive
	virtual string combinedOutput();
	virtual bool isActive();
	//Description: calls reset functions for both blurtReps and gen
	virtual void reset();
};
#endif
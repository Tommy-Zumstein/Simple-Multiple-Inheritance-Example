//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: gen.h
//DATE: 2/22/17
/*REVISION HISTORY:
2/22/17:
-translated into C++
*/
//PLATFORM:
//REFERENCES:

/*
DESCRIPTION:
The gen class is a class designed to calculate the values of an arithmatic sequence in order.
The sequenve held in a gen object follows this sequence:
a_k = a_k-1 + d = a_k-2 + 2d = a_1 + d(k-1) OR a_k-i = a_k - d(i)
A gen object will output in this order a_k, a_k-1, a_k-2, ..., a_k-(k-1)
After outputting a_k-(k-1) the gen object will be set to inactive and only output BAD_REQ_RETURN_VAL
a_k = seqBase
k = seqLen
i = seqIndx
d = seqConst
a gen object can be activated and deactivated as many times as needed
Upon reset of the object's index is set to 0
Legal States:
Active/inactive
*/

/*
Assumptions:
Class Invarients:
Sequence values do not change after construction
Valid data types are sent into the constructor
Sequence should not contain BAD_REQ_RETURN_VAL

Default values:
active =false
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = 0

Interface invarients:
Copying not supported
The client will send in a uint for seqLength
When inactive getNext will return BAD_REQ_RETURN_VAL
*/
#ifndef GEN_H_
#define GEN_H_

using namespace std;

class gen
{
protected:
	static const int BAD_REQ_RETURN_VAL = -9999;
	static const unsigned int GEN_INDX_INIT_VAL = 0;
	bool active;
	int seqBase;
	int seqConst;
	unsigned int seqLen;
	unsigned int seqIndx;

public:
	//Constructors
	gen();
	gen(int, int, unsigned int);
	//Destructor
	~gen();
	//gen functionality
	//Description: returns the next value in the sequence, if the object is inactive returns BAD_REQ_RETURN_VAL
	//Postcondition: gen object maybe inactive
	virtual int getNext();
	//Description: resets the object to the initial index value
	virtual void reset();

private:
	//Helper Functions
	//Description: If the index has exceeded the sequence length this sets the gen to inactive
	//Postcondition: gen object maybe deactivated
	void checkDeactivate();

};
#endif
#ifndef __COUNTER_H
#define __COUNTER_H

#include <list>
#include "atomic.h"     // class Atomic

class Counter : public Atomic
{
public:
	Counter( const string &name = "Counter" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &cam1;
	const Port &cam2;
	const Port &cam3;
	const Port &cam4;
	const Port &countOut;

	Time preparationTime;
	int counter;

};	// class Counter

// ** inline ** //
inline
string Counter::className() const
{
	return "Counter" ;
}

#endif   //__COUNTER_H

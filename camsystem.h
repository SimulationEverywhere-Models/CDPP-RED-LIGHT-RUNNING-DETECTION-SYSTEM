#ifndef __CAMSYSTEM_H
#define __CAMSYSTEM_H

#include <list>
#include "atomic.h"     // class Atomic

class CamSystem : public Atomic
{
public:
	CamSystem( const string &name = "CamSystem" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &red;
	const Port &emd;
	const Port &counter;
	const Port &data;
	Time preparationTime;
	int isRed;

};	// class CamSystem

// ** inline ** //
inline
string CamSystem::className() const
{
	return "CamSystem" ;
}

#endif   //__CAMSYSTEM_H

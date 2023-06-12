#ifndef __DETECTOR_H
#define __DETECTOR_H

#include <list>
#include "atomic.h"     // class Atomic

class Detector : public Atomic
{
public:
	Detector( const string &name = "Detector" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &sv;
	const Port &emd;
	Time preparationTime;

};	// class Detector

// ** inline ** //
inline
string Detector::className() const
{
	return "Detector" ;
}

#endif   //__DETECTOR_H

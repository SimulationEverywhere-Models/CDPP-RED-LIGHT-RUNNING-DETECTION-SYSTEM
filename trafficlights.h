#ifndef __TRAFFICLIGHTS_H
#define __TRAFFICLIGHTS_H

#include <list>
#include "atomic.h"     // class Atomic

class TrafficLights : public Atomic
{
public:
	TrafficLights( const string &name = "TrafficLights" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &redEW;
	const Port &redNS;

	static const int EW_GREEN_NS_RED_STATE = 0;
	static const int EW_YELLOW_NS_RED_STATE = 1;
	static const int EW_RED_NS_GREEN_STATE = 2;
	static const int EW_RED_NS_YELLOW_STATE = 3;

	int curLightState;

	Time greenTime;
	Time yellowTime;
	// redTime is greenTime + yellowTime
};	// class TrafficLights

// ** inline ** //
inline
string TrafficLights::className() const
{
	return "TrafficLights" ;
}

#endif   //__TRAFFICLIGHTS_H

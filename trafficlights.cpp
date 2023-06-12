/** include files **/
#include "trafficlights.h"      // class Detector
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Detector
* Description:
********************************************************************/
TrafficLights::TrafficLights( const string &name )
: Atomic( name )
, redEW( addOutputPort( "redEW" ) )
, redNS( addOutputPort( "redNS" ) )
, curLightState (EW_GREEN_NS_RED_STATE)
, greenTime (0, 0, 7, 0)
, yellowTime (0, 0, 3, 0)
{
	string greenTime(MainSimulator::Instance().getParameter( description(), "greenTime" ));
	if( greenTime != "" )
	{
		this->greenTime = greenTime;
	}
	string yellowTime(MainSimulator::Instance().getParameter( description(), "yellowTime" ));
	if( yellowTime != "" )
	{
		this->yellowTime = yellowTime;
	}

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "TrafficLight constructor" << "\n";
	MainSimulator::Instance().outputStream() << "Green Time=" << this->greenTime << "\n";
	MainSimulator::Instance().outputStream() << "Yellow Time=" << this->yellowTime << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &TrafficLights::initFunction()
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "TrafficLight initFunction" << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	this->holdIn(active, Time(0,0,0,0));

	return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &TrafficLights::externalFunction( const ExternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "TrafficLight externalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &TrafficLights::internalFunction( const InternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "TrafficLights internalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";

	switch(curLightState)
	{
	case EW_GREEN_NS_RED_STATE:
		this->holdIn(active, greenTime); // change state in greenTime
		break;
	case EW_YELLOW_NS_RED_STATE:
		this->holdIn(active, yellowTime);
		break;
	case EW_RED_NS_GREEN_STATE:
		this->holdIn(active, greenTime);
		break;
	case EW_RED_NS_YELLOW_STATE:
		this->holdIn(active, yellowTime);
		break;
	default:
		MainSimulator::Instance().outputStream() << "!!!ERROR!!!" << "\n";
		break;
	}

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &TrafficLights::outputFunction( const InternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "TrafficLights outputFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";

	if (curLightState == EW_RED_NS_YELLOW_STATE)
	{
		curLightState = EW_GREEN_NS_RED_STATE;
	}
	else
	{
		curLightState++;
	}

	MainSimulator::Instance().outputStream() << "curLightState: " << curLightState << "\n";

	switch(curLightState)
	{
		case EW_GREEN_NS_RED_STATE:
			sendOutput( msg.time(), redEW, 0 );
			sendOutput( msg.time(), redNS, 1 );
			MainSimulator::Instance().outputStream() << "EW_GREEN_NS_RED_STATE, redEW: 0, redNS 1" << "\n";
			break;
		case EW_YELLOW_NS_RED_STATE:
			sendOutput( msg.time(), redEW, 0 );
			sendOutput( msg.time(), redNS, 1 );
			MainSimulator::Instance().outputStream() << "EW_YELLOW_NS_RED_STATE, redEW: 0, redNS 1" << "\n";
			break;
		case EW_RED_NS_GREEN_STATE:
			sendOutput( msg.time(), redEW, 1 );
			sendOutput( msg.time(), redNS, 0 );
			MainSimulator::Instance().outputStream() << "EW_RED_NS_GREEN_STATE, redEW: 1, redNS 0" << "\n";
			break;
		case EW_RED_NS_YELLOW_STATE:
			sendOutput( msg.time(), redEW, 1 );
			sendOutput( msg.time(), redNS, 0 );
			MainSimulator::Instance().outputStream() << "EW_RED_NS_YELLOW_STATE, redEW: 1, redNS 0" << "\n";
			break;
		default:
			MainSimulator::Instance().outputStream() << "!!!ERROR!!!" << "\n";
			break;
	}

	MainSimulator::Instance().outputStream() << "." << "\n";

	return *this ;
}

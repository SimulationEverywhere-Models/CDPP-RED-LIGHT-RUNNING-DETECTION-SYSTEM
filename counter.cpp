/** include files **/
#include "counter.h"      // class Counter
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Counter
* Description:
********************************************************************/
Counter::Counter( const string &name )
: Atomic( name )
, cam1( addInputPort( "cam1" ) )
, cam2( addInputPort( "cam2" ) )
, cam3( addInputPort( "cam3" ) )
, cam4( addInputPort( "cam4" ) )
, countOut( addOutputPort( "countOut" ) )
, preparationTime( 0, 0, 0, 10 )
, counter(0)
{
	string time(MainSimulator::Instance().getParameter( description(), "preparation" ));

	if( time != "" )
	{
		preparationTime = time ;
	}

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Counter constructor" << "\n";
	MainSimulator::Instance().outputStream() << "Preparation Time=" << preparationTime << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Counter::initFunction()
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Counter initFunction" << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	this->holdIn(active, Time(0,10,0,0));

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Counter::externalFunction( const ExternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Counter externalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";

	if( msg.port() == cam1 || msg.port() == cam2 || msg.port() == cam3 || msg.port() == cam4 )
	{
		MainSimulator::Instance().outputStream() << "Port: cam1, cam2, cam3, or cam4" << "\n";
		counter++;
	}
	else
	{
		MainSimulator::Instance().outputStream() << "!!!ERROR!!!" << "\n";
	}

	MainSimulator::Instance().outputStream() << "." << "\n";

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Counter::internalFunction( const InternalMessage &msg )
{

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Counter internalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	counter=0;
	this->holdIn(active, Time(0,10,0,0));

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Counter::outputFunction( const InternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Counter outputFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	sendOutput( msg.time(), countOut, counter ) ;

	return *this ;
}

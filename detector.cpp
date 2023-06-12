/** include files **/
#include "detector.h"      // class Detector
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Detector
* Description:
********************************************************************/
Detector::Detector( const string &name )
: Atomic( name )
, sv( addInputPort( "sv" ) )
, emd( addOutputPort( "emd" ) )
, preparationTime( 0, 0, 0, 10 )

{
	string time(MainSimulator::Instance().getParameter( description(), "preparation" ));

	if( time != "" )
	{
		preparationTime = time ;
	}

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Detector constructor" << "\n";
	MainSimulator::Instance().outputStream() << "Preparation Time=" << preparationTime << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Detector::initFunction()
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Detector initFunction" << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Detector::externalFunction( const ExternalMessage &msg )
{

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Detector externalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";

	if( msg.port() == sv )
	{
		MainSimulator::Instance().outputStream() << "Port: sv" << "\n";

		holdIn( active, preparationTime );
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
Model &Detector::internalFunction( const InternalMessage &msg )
{

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Detector internalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Detector::outputFunction( const InternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "Detector outputFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	sendOutput( msg.time(), emd, 1 ) ;
	return *this ;
}

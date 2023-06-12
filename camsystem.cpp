/** include files **/
#include "camsystem.h"      // class CamSystem
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: CamSystem
* Description:
********************************************************************/
CamSystem::CamSystem( const string &name )
: Atomic( name )
, red( addInputPort( "red" ) )
, emd( addInputPort( "emd" ) )
, counter( addOutputPort( "counter" ) )
, data( addOutputPort( "data" ) )
, preparationTime( 0, 0, 0, 10 )

{
	string time(MainSimulator::Instance().getParameter( description(), "preparation" ));

	if( time != "" )
	{
		preparationTime = time ;
	}

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "CamSystem constructor" << "\n";
	MainSimulator::Instance().outputStream() << "Preparation Time=" << preparationTime << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &CamSystem::initFunction()
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "CamSystem initFunction" << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &CamSystem::externalFunction( const ExternalMessage &msg )
{

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "CamSystem externalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";

	if( msg.port() == red )
	{
		MainSimulator::Instance().outputStream() << "Port: red" << "\n";
		isRed = msg.value();
		passivate();
	}
	else if (msg.port() == emd)
	{
		MainSimulator::Instance().outputStream() << "Port: emd" << "\n";
		if (isRed == 1)
		{
			MainSimulator::Instance().outputStream() << "isRed: 1" << "\n";
			holdIn(active, preparationTime);
		}
		else
		{
			MainSimulator::Instance().outputStream() << "isRed: 0" << "\n";
			passivate();
		}
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
Model &CamSystem::internalFunction( const InternalMessage &msg )
{

	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "CamSystem internalFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &CamSystem::outputFunction( const InternalMessage &msg )
{
	MainSimulator::Instance().outputStream() << "." << "\n";
	MainSimulator::Instance().outputStream() << "CamSystem outputFunction" << "\n";
	MainSimulator::Instance().outputStream() << "Timestamp: " << msg.time() << "\n";
	MainSimulator::Instance().outputStream() << "." << "\n";

	sendOutput( msg.time(), counter, 1 ) ;
	sendOutput( msg.time(), data, 1 ) ;
	return *this ;
}

/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "detector.h"      // class Detector
#include "trafficlights.h"      // class TrafficLights
#include "camsystem.h"      // class CamSystem
#include "counter.h"      // class Counter
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Detector>() , "Detector" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TrafficLights>() , "TrafficLights" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CamSystem>() , "CamSystem" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Counter>() , "Counter" ) ;
}

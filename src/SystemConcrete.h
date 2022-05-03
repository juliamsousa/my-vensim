#ifndef SYSTEMCONCRETE_H
#define SYSTEMCONCRETE_H

#include <string>

#include "System.h"

using namespace std;

/// Class SystemConcrete that publicly inherits from the System interface.

class SystemConcrete : public System
{
	protected: 
	
		double energy;
		bool connection;
		std::string label;
	
	public:
	
		SystemConcrete ();
		
		SystemConcrete (SystemConcrete& cSystem);
		
		virtual ~SystemConcrete () {};

		void setEnergy (float e); 

		float getEnergy (); 

		void setConnection (bool c); 
	
		bool isConnected (); 
		
		void setLabel (string label); 
		
		string getLabel ();		
		
		SystemConcrete& operator= (SystemConcrete rSystem);
		
};

#endif

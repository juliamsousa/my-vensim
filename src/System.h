#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;
/// Class System interface.

class System
{
	public:
	
		/// Method that receives a float as parameter and sets it as System's energy.
		virtual void setEnergy (float e) = 0; 

		/// Method that returns System's energy.	
		virtual float getEnergy () = 0; 
		
		/// Method that receives a boolean as parameter and sets it as System's connection.
		virtual void setConnection (bool c) = 0; 
		
		/// Method that returns a boolean verifying if the System is connected to a Flow.
		virtual bool isConnected () = 0; 
		
		/// Method that receives a string as parameter and sets it as System's label.
		virtual void setLabel (string label) = 0; 
		
		/// Method that returns System's label.
		virtual string getLabel () = 0;		
		
};

#endif

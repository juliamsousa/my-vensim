#ifndef FLOW_H
#define FLOW_H

#include "System.h"

#include <string>

using namespace std;
/// Class Flow's interface

class Flow
{
	public: 
		
		/// Virtual method equation implemented by heir classes.
		virtual float equation () = 0;
		
		/// Method that receives System pointers and sets them as Destiny and Source for Flow.	
		virtual void connectFlow (System* s, System* d) = 0; 
		
		/// Method that returns a boolean verifying if Flow is connected to Systems.	
		virtual bool isConnected () = 0;
		
		/// Method that returns a boolean verifying if Flow was executed.	
		virtual bool wasExecuted () = 0;
		
		/// Method that returns Flow's label.	
		virtual std::string getLabel () = 0; 
		
		/// Method that receives a string as parameter and sets it as Flow's label.	
		virtual void setLabel (string label) = 0;
		
		/// Method that receives a boolean as parameter and sets it as Flow's connection.	
		virtual void setConnection (bool c) = 0; 
		
		///  Method that receives a boolean as parameter and sets it as Flow's execution.	
		virtual void setExecution (bool c) = 0; 
		
		/// Method that receives a System pointer and sets it as Flow's source.	
		virtual void setSource (System* source) = 0; 
		
		/// Method that receives a System pointer and sets it as FlowConcrete's destiny.	
		virtual void setDestiny (System* destiny) = 0;
		
		/// Method that returns a System pointer for Flow's source.	
		virtual System* getSource () = 0; 
		
		/// Method that returns a System pointer for Flow's destiny.	
		virtual System* getDestiny () = 0;
	
};

#endif

#ifndef FLOWCONCRETE_H
#define FLOWCONCRETE_H

#include "System.h"
#include "Flow.h"

#include <string>

using namespace std;

/// Class FlowConcrete that publicly inherits from the Flow interface .

class FlowConcrete : public Flow
{
	protected: 
	
		System* source;
		System* destiny;
		bool connection;
		bool execution;
		string label;
	
	public:
		
		FlowConcrete ();
		
		FlowConcrete (FlowConcrete& cFlow);
		
		virtual ~FlowConcrete () {};
		
		virtual float equation ();
		
		void connectFlow (System* s, System* d); 
		
		bool isConnected ();
		
		bool wasExecuted ();
		
		string getLabel (); 
		
		void setLabel (string label);
		
		void setConnection (bool c); 
		
		void setExecution (bool c); 
		
		void setSource (System* source); 
		
		void setDestiny (System* destiny);
		
		System* getSource (); 
		
		System* getDestiny ();
		
		FlowConcrete& operator= (FlowConcrete rFlow);
		
};

#endif

#include "FlowConcrete.h"
//#include "System.h"

#include <string>

using namespace std;

/// Class FlowConcrete implementation.

// Class FlowConcrete conctructor. 
FlowConcrete::FlowConcrete() 
{	
	this->connection = false; 
	this->execution = false;
	this->source = NULL;
	this->destiny = NULL;
}

//Class FlowConcrete copy constructor.
FlowConcrete::FlowConcrete (FlowConcrete& cFlow)
{
	this->source = cFlow.source;
	this->destiny = cFlow.destiny;
	this->connection = cFlow.connection;
	this->execution = cFlow.execution;
	this->label = cFlow.label;
}

// Virtual method equation implemented by heir classes.
float FlowConcrete::equation() {}

// Method that receives System pointers and sets them as Destiny and Source for FlowConcrete.
void FlowConcrete::connectFlow (System* s, System* d)
{	
	this->source = s;
	this->destiny = d;
}

// Method that returns a boolean verifying if FlowConcrete is connected to Systems.
bool FlowConcrete::isConnected ()
{
	return this->connection;
}

// Method that returns a boolean verifying if FlowConcrete was executed.
bool FlowConcrete::wasExecuted ()
{
	return this->execution;
}

// Method that returns FlowConcrete's label.
string FlowConcrete::getLabel()
{
	return this->label;
}

// Method that receives a string as parameter and sets it as FlowConcrete's label.
void FlowConcrete::setLabel (string label)
{
	this->label = label;
}

// Method that returns a System pointer for FlowConcrete's source.
System* FlowConcrete::getSource ()
{
	return this->source;
}	

// Method that returns a System pointer for FlowConcrete's destiny.	
System* FlowConcrete::getDestiny ()
{
	return this->destiny;	
}	

// Method that receives a boolean as parameter and sets it as FlowConcrete's connection.
void FlowConcrete::setConnection (bool c)
{	
	this->connection = c;
}

//  Method that receives a boolean as parameter and sets it as FlowConcrete's execution.
void FlowConcrete::setExecution (bool c)
{
	this->execution = c;
 } 

// Method that receives a System pointer and sets it as FlowConcrete's source.
void FlowConcrete::setSource (System* source)
{
	this->source = source;
}

// Method that receives a System pointer and sets it as FlowConcrete's destiny.
void FlowConcrete::setDestiny (System* destiny)
{
	this->destiny = destiny;
}

// Method that overloads the = operator.
FlowConcrete& FlowConcrete::operator= (FlowConcrete rFlow)
{
	if (&rFlow == this)	
		return *this;
	
	this->source = rFlow.getSource();
	this->destiny = rFlow.getDestiny();
	
	return *this;
}		

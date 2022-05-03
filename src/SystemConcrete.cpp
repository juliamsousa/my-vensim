#include "SystemConcrete.h"

using namespace std;

/// Class SystemConcrete implementation.

// Class SystemConcrete constructor.
SystemConcrete::SystemConcrete () {this->connection = false;}

// Class SystemConcrete copy constructor.
SystemConcrete::SystemConcrete (SystemConcrete& cSystem)
{
	this->energy = cSystem.energy;
	this->connection = cSystem.connection;
	this->label = cSystem.label;
}

// Method that receives a float as parameter and sets it as SystemConcrete's energy.
void SystemConcrete::setEnergy (float e)
{
	this->energy = e;
}

// Method that returns SystemConcrete's energy.	
float SystemConcrete::getEnergy ()
{
	return this->energy;
}

// Method that receives a boolean as parameter and sets it as SystemConcrete's connection.
void SystemConcrete::setConnection (bool c)
{
	this->connection = c;
}

// Method that returns a boolean verifying if the SystemConcrete is connected to a Flow.
bool SystemConcrete::isConnected ()
{
	return this->connection;
}

// Method that returns SystemConcrete's label.
string SystemConcrete::getLabel()
{
	return this->label;
}

// Method that receives a string as parameter and sets it as SystemConcrete's label.
void SystemConcrete::setLabel (string label)
{
	this->label = label;
}

// Method that overflows the = operator.
SystemConcrete& SystemConcrete::operator= (SystemConcrete rSystem)
{
	if (&rSystem == this)
		return *this;
	
	this->connection = rSystem.isConnected();
	this->energy = rSystem.getEnergy();
	this->label = rSystem.getLabel();
	
	return *this;
}

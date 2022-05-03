#ifndef MYFLOWS_H
#define MYFLOWS_H

#include "FlowConcrete.h"

using namespace std;

/// Class ExponentialFlow that publicly inherits from class FlowConcrete
class ExponentialFlow : public FlowConcrete
{
	public:
	
	ExponentialFlow () {this->connection = false; this->source = NULL; this->destiny = NULL;}
	
	~ExponentialFlow() {}; 
		
	float equation ()
	{
		return this->source->getEnergy()*0.01;
	}
	
};

/// Class LogisticalFlow that publicly inherits from class FlowConcrete
class LogisticalFlow : public FlowConcrete
{
	public:
	
	LogisticalFlow() {this->connection = false; this->source = NULL; this->destiny = NULL;}
	
	~LogisticalFlow () {};
		
	float equation ()
	{
		return 0.01*this->destiny->getEnergy()*(1-this->destiny->getEnergy()/70);
	}
	
};

#endif

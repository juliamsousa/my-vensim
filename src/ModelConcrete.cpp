#include "Model.h"

#include "ModelConcrete.h"
#include "SystemConcrete.h"
#include "FlowConcrete.h"
#include "MyFlows.h"

#include <iostream>
#include <vector>
#include <assert.h>
#include <iterator>

using namespace std;

/// Class ModelConcrete's implementation.

Model* Model::instanceModel = NULL;	
// Class ModelConcrete conctructor.
ModelConcrete::ModelConcrete() {}

// Creates an unique instance for Model
Model* Model::getInstanceModel()
{	
	if (ModelConcrete::instanceModel == NULL)
	{
		Model::instanceModel = new ModelConcrete();
	}

	return ModelConcrete::instanceModel;
}

// Deletes all the objects containned in Model.
void ModelConcrete::clearModel()
{
	this->flows.clear();
	
	this->systems.clear();
	
}

// Method that receives a Flow pointer as parameter and adds it to the Model conteiner.
void ModelConcrete::add (Flow* flow)
{
	this->flows.push_back (flow);
}

// Method that receives a System pointer as parameter and adds it to the Model conteiner.
void ModelConcrete::add (System* system)
{
	this->systems.push_back (system);
}

// Method that receives a string as parameter and returns a Flow pointer according to its label.
Flow* ModelConcrete::getFlow (string label)
{
	vector<Flow*>::iterator rFlow = this->flows.begin();
	
	while(rFlow != this->flows.end())
	{
		if(label==(*rFlow)->getLabel())
			return *rFlow;
		
		rFlow++;
	} 
	
	return NULL;
}

// Method that receives a string as parameter and returns a System pointer according to its label.
System* ModelConcrete::getSystem (string label)
{
	vector<System*>::iterator rSystem = this->systems.begin();
	
	while(rSystem != this->systems.end())
	{
		if(label==(*rSystem)->getLabel())
			return *rSystem;
		
		rSystem++;
	} 
	
	return NULL;
}

// Method that receives a string as parameter and removes a Flow from the conteiner according to its label.
bool ModelConcrete::remove (Flow* flow)
{
	vector<Flow*>::iterator rFlow = this->flows.begin();
	
	while(rFlow != this->flows.end())
	{
		if(flow->getLabel()==(*rFlow)->getLabel())
		{
			delete *rFlow;
			this->flows.erase(rFlow);
			return true;
		}
		
		rFlow++;
	} 

	return false;
}

// Method that receives a string as parameter and removes a System from the conteiner according to its label.
bool ModelConcrete::remove (System* system)
{
	vector<System*>::iterator rSystem = this->systems.begin();
	
		while(rSystem != this->systems.end())
	{
		if(system->getLabel()==(*rSystem)->getLabel())
		{
			delete *rSystem;
			this->systems.erase(rSystem);
			return true;
		}
		
		rSystem++;
	} 

	return false;
}

// Method that creates a new system and returns it.
void ModelConcrete::createSystem (string label, double energy)
{
	System* systemCreated = new SystemConcrete();

	systemCreated->setLabel(label);
	systemCreated->setEnergy(energy);
	
	this->add(systemCreated);
		
}

// Method that creates a new flow and returns it.
void ModelConcrete::createFlow (int type, string label)
{
	Flow* flowCreated;
	
	if (type == 1)	
		flowCreated = new LogisticalFlow();
	else 

	if (type == 2)
		flowCreated = new ExponentialFlow();
	
	flowCreated->setLabel(label);
	
	this->add(flowCreated);
	
}

// Method that executes the Flows containned in the Model.
bool ModelConcrete::execute (int start, int end, int step)
{
	vector<Flow*>::iterator rFlow = this->flows.begin();
	float* energies = new float [this->flows.size()];
	int j=0;

	for (int i=start; i<=end; i+=step)
	{
		rFlow = this->flows.begin();
		j=0;
					 
		while (rFlow != this->flows.end())
		{
			energies[j] = (*rFlow)->equation();
					
			j++;
			rFlow++;
		}
				
		 rFlow = this->flows.begin();
		 j=0;
				 
		 while (rFlow!= this->flows.end())
		 {
		 	if (!((*rFlow)->wasExecuted()))
		 	{
		 		(*rFlow)->getSource()->setEnergy((*rFlow)->getSource()->getEnergy()-energies[j]);
				(*rFlow)->getDestiny()->setEnergy((*rFlow)->getDestiny()->getEnergy()+energies[j]);
			}
					 	
			j++;
			rFlow++;
		 }		 
	}
	
	rFlow = this->flows.begin();
				 
	while (rFlow!= this->flows.end())
	{
		(*rFlow)->setExecution (true);
		
		rFlow++;
	}
	
	return true;
}

// Method that reports the execution results.
bool ModelConcrete::report ()
{
	vector<System*>::iterator rSystem = this->systems.begin();
	
	while (rSystem != this->systems.end())
	{
		cout<<(*rSystem)->getLabel()<<": "<<(*rSystem)->getEnergy()<<endl;	
		rSystem++;
	}	
	
	return true;
}

#ifndef MODELCONCRETE_H 
#define MODELCONCRETE_H

#include <vector>
#include <string>

#include "System.h" 
#include "Flow.h"
#include "Model.h"

using namespace std;

/// Class ModelConcrete that publicly inherits from the Model interface.

class ModelConcrete : public Model
{
	protected:
		
		vector <System*> systems;
		vector <Flow*> flows;
	
	public:
		
		ModelConcrete ();
		
		virtual ~ModelConcrete () {};
	
		static Model* getInstanceModel ();
		
		Flow* getFlow (string label); 
		
		System* getSystem (string label); 
		
		void add (Flow* flow);
		
		void add (System* system);
		
		bool remove (Flow* flow);
		
		bool remove (System* system);
		
		void clearModel();
		
		void createSystem (string label, double energy);
	
		void createFlow (int type, string label);
		
		bool execute (int start, int end, int step);
		
		bool report ();
		
};


#endif

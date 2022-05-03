#ifndef MODEL_H 
#define MODEL_H

#include <vector>
#include <string>

#include "System.h" 
#include "Flow.h"

using namespace std;

/// Class Model interface.

class Model 
{		
	public:

		/// Class Model's unique instance.
		static Model* instanceModel;
		
		/// Creates an unique instance for Model
		static Model* getInstanceModel ();
		
		/// Method tha deletes all the objects containned in Model.
		virtual void clearModel () = 0;
		
		/// Method that receives a string as parameter and returns a Flow pointer according to its label.
		virtual Flow* getFlow (string label) = 0; 
		
		/// Method that receives a string as parameter and returns a System pointer according to its label.
		virtual System* getSystem (string label) = 0; 
		
		/// Method that receives a Flow pointer as parameter and adds it to the Model conteiner.
		virtual void add (Flow* flow) = 0;
		
		/// Method that receives a System pointer as parameter and adds it to the Model conteiner.
		virtual void add (System* system) = 0;
		
		/// Method that receives a string as parameter and removes a Flow from the conteiner according to its label.
		virtual bool remove (Flow* flow) = 0;
		
		/// Method that receives a string as parameter and removes a System from the conteiner according to its label.
		virtual bool remove (System* system) = 0;
		
		/// Method that reports the execution results.
		virtual bool report () = 0;
		
		/// Method that creates a new system and returns it.
		virtual void createSystem (string label, double energy) = 0;
		
		/// Method that creates a new flow and returns it.
		virtual void createFlow (int type, string label) = 0;
		
		/// Method that executes the Flows containned in the Model.
		virtual bool execute (int start, int end, int step) = 0;
		
};


	
#endif

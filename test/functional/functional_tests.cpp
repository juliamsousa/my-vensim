#include "functional_tests.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\ModelConcrete.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Model.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\System.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Flow.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\MyFlows.h"

#include <math.h>
#include <assert.h>
#include <string>
#include <cstring>

using namespace std;

/// Functional Test's implementation.

// Exponential execution functional test.
void exponentialExecutionTest (Model* model, int start, int end, int step)
{
	model->createSystem ("pop1", 100.0);
	
	model->createSystem ("pop2", 0.0);
			
	model->createFlow (2, "exponentialFLow1");

	model->getFlow ("exponentialFLow1")->connectFlow(model->getSystem("pop1"), model->getSystem("pop2"));
	
	model->execute (start, end, step);

	assert (fabs(model->getSystem("pop1")->getEnergy() - 36.6032) < 0.0001);
	assert (fabs(model->getSystem("pop2")->getEnergy() - 63.3968) < 0.0001);
}

// Logistical execution functional test.
void logisticalExecutionTestModel (Model* model, int start, int end, int step)
{	
	model->createSystem ("p1", 100.0);
	
	model->createSystem ("p2", 10.0);
			
	model->createFlow (1, "logisticalFLow1"); 
	
	model->getFlow ("logisticalFLow1")->connectFlow(model->getSystem("p1"), model->getSystem("p2"));
	
	model->execute (start, end, step);
	
	assert(fabs(model->getSystem("p1")->getEnergy() - 88.2167) < 0.0001);
	assert(fabs(model->getSystem("p2")->getEnergy() - 21.7833) < 0.0001);
}

// Complex execution functional test.
void complexExecutionTestModel (Model* model, int start, int end, int step)
{	
	model->createSystem("Q1", 100.0);
	model->createSystem("Q2", 0.0);
	model->createSystem("Q3", 100.0);	
	model->createSystem("Q4", 0.0);
	model->createSystem("Q5", 0.0);
							
	model->createFlow(2, "f");
	model->createFlow(2, "g");
	model->createFlow(2, "r");				
	model->createFlow(2, "t");		
	model->createFlow(2, "u");
	model->createFlow(2, "v");
							
	model->getFlow("f")->connectFlow(model->getSystem("Q1"), model->getSystem("Q2"));
	model->getFlow("g")->connectFlow(model->getSystem("Q1"), model->getSystem("Q3"));
	model->getFlow("r")->connectFlow(model->getSystem("Q2"), model->getSystem("Q5"));
	model->getFlow("t")->connectFlow(model->getSystem("Q2"), model->getSystem("Q3"));
	model->getFlow("u")->connectFlow(model->getSystem("Q3"), model->getSystem("Q4"));
	model->getFlow("v")->connectFlow(model->getSystem("Q4"), model->getSystem("Q1"));

	model->execute(start, end, step);
	
	assert(fabs(model->getSystem("Q1")->getEnergy() - 31.8513) < 0.0001);
	assert(fabs(model->getSystem("Q2")->getEnergy() - 18.4003) < 0.0001);
	assert(fabs(model->getSystem("Q3")->getEnergy()- 77.1143) < 0.0001);
	assert(fabs(model->getSystem("Q4")->getEnergy() - 56.1728) < 0.0001);
	assert(fabs(model->getSystem("Q5")->getEnergy() - 16.4612) < 0.0001);
}

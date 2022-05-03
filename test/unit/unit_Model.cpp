#include "unit_Model.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\MyFlows.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\FlowConcrete.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\SystemConcrete.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\ModelConcrete.h"

#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <vector>

/// Unit tests for Model implementation.

void unit_Model_constructor ()
{
	Model* m = new ModelConcrete ();
	
	System* s = new SystemConcrete ();
	s->setLabel("testModel");

	m->add(s);
	
	assert (m->getSystem("testModel")->getLabel() == s->getLabel());
}

void unit_Model_getFlow ()
{
	Model* model = new ModelConcrete ();
	
	Flow* flow = new FlowConcrete ();
	flow->setLabel("flowGetFlowTest");
	
	model->add(flow);
	
	assert (model->getFlow("flowGetFlowTest")->getLabel() == "flowGetFlowTest");
}

void unit_Model_getSystem ()
{
	Model* model = new ModelConcrete();
	
	System* system = new SystemConcrete ();
	system->setLabel("systemGetSystemTest");
	
	model->add(system);
	
	assert (model->getSystem("systemGetSystemTest")->getLabel() == "systemGetSystemTest");
}

void unit_Model_add (Flow* f)
{
	Model* model = new ModelConcrete ();
	
	Flow* flow = new FlowConcrete ();
	flow->setLabel("flowAddTest");
	
	model->add(flow);
	
	assert (model->getFlow("flowAddTest")->getLabel() == "flowAddTest");
}

void unit_Model_add (System* s)
{
	Model* model = new ModelConcrete ();
	
	System* system = new SystemConcrete ();
	system->setLabel("systemAddTest");
	
	model->add(system);
	
	assert (model->getSystem("systemAddTest")->getLabel() == "systemAddTest");
}

void unit_Model_remove (Flow* f)
{	
	Model* model = new ModelConcrete ();
	
	Flow* flow = new FlowConcrete ();
	flow->setLabel("flowRemoveTest");
	
	model->add(flow);
	
	assert (model->remove(model->getFlow(flow->getLabel())) == true);
}

void unit_Model_remove (System* s)
{
	Model* model = new ModelConcrete ();
	
	System* system = new SystemConcrete ();
	system->setLabel("systemRemoveTest");
	
	model->add(system);
	
	assert (model->remove(model->getSystem(system->getLabel())) == true);
}

void unit_Model_report()
{
	Model* model = new ModelConcrete ();

	assert(model->report() == true);
}

void run_unit_test_Model ()
{
	Flow* f = new FlowConcrete ();
	System* s = new SystemConcrete ();
	
	unit_Model_constructor ();
	
	unit_Model_getFlow (); 
		
	unit_Model_getSystem (); 
		
	unit_Model_add (f);
		
	unit_Model_add (s);

	unit_Model_remove (f);
		
	unit_Model_remove (s);
		
	unit_Model_report ();

}

#include "unit_Flow.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\FlowConcrete.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\MyFlows.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\SystemConcrete.h"

#include <cstdio>
#include <assert.h>

/// Unit tests for Flow implementation.

void unit_Flow_construtor ()
{
	FlowConcrete* f = new FlowConcrete ();
	
	assert(f->wasExecuted() == false);
}

void unit_Flow_copy_constructor_Flow ()
{
	FlowConcrete* f1 = new FlowConcrete ();
	f1->setLabel("f1");
	
	Flow* f2 = new FlowConcrete (*f1);
	
	assert (f1->getLabel() == f2->getLabel());
	
}

void unit_Flow_setLabel ()
{
	Flow* flow = new FlowConcrete();
	flow->setLabel ("testeSetLabelFlow");
	
	assert (flow->getLabel() == "testeSetLabelFlow");
}

void unit_Flow_getLabel ()
{
	Flow* flow = new FlowConcrete();
	flow->setLabel("teste");
	
	assert (flow->getLabel() == "teste");
}

void unit_Flow_setConnection ()
{
	Flow* flow = new FlowConcrete ();
	flow->setConnection(true);
	
	assert (flow->isConnected() == true);
}

void unit_Flow_connectFlow ()
{
	Flow* flow = new FlowConcrete ();
	
	System* s1 = new SystemConcrete ();
	System* s2 = new SystemConcrete ();
	
	flow->connectFlow(s1, s2);
	
	assert (flow->getDestiny() != NULL && flow->getSource() != NULL);
}

void unit_Flow_isConnected ()
{
	Flow* flow = new FlowConcrete ();
	flow->setConnection(false);
	
	assert (flow->isConnected() == false);
}

void unit_Flow_wasExecuted ()
{
	Flow* flow = new FlowConcrete ();
	flow->setExecution(false);
	
	assert (flow->wasExecuted() == false);
}

void unit_Flow_setExecution ()
{
	Flow* flow = new FlowConcrete ();
	flow->setExecution(true);
	
	assert (flow->wasExecuted() == true);
}

void unit_Flow_setSource ()
{
	Flow* flow = new FlowConcrete ();
	
	System* source = new SystemConcrete();
	source->setLabel("testSource");
	
	flow->setSource(source);
	
	assert (flow->getSource()->getLabel() == "testSource");
}

void unit_Flow_getSource ()
{
	Flow* flow = new FlowConcrete ();
	
	System* s1 = new SystemConcrete ();
	s1->setLabel("getSource");
	
	flow->setSource(s1);
	
	assert (flow->getSource()->getLabel() == "getSource");
}

void unit_Flow_setDestiny ()
{
	Flow* flow = new FlowConcrete ();
	
	System* destiny = new SystemConcrete();
	destiny->setLabel("setDestinyTest");
	
	flow->setDestiny(destiny);
	
	assert (flow->getDestiny()->getLabel() == "setDestinyTest");
}

void unit_Flow_getDestiny ()
{
	Flow* flow = new FlowConcrete ();
	System* s1 = new SystemConcrete ();
	s1->setLabel("getDestinyTest");
	
	flow->setDestiny(s1);
	
	assert (flow->getDestiny()->getLabel() == "getDestinyTest");
}

Flow& unit_Flow_operator ()
{
	Flow* f1 = new FlowConcrete ();
	
	FlowConcrete rFlow;
	rFlow.setLabel ("testeOperator");
	
	f1 = &rFlow;
	
	assert (f1->getLabel() == rFlow.getLabel());
}

void run_unit_test_Flow ()
{
	unit_Flow_construtor ();
		
	unit_Flow_copy_constructor_Flow ();

	unit_Flow_setLabel (); 
		
	unit_Flow_getLabel ();		

	unit_Flow_setConnection ();

	unit_Flow_connectFlow ; 
		
	unit_Flow_isConnected ();
		
	unit_Flow_wasExecuted ();		
		
	unit_Flow_setExecution (); 
		
	unit_Flow_setSource (); 
			
	unit_Flow_getSource ();
	
	unit_Flow_setDestiny (); 
		
	unit_Flow_getDestiny ();
		
	unit_Flow_operator ();
}

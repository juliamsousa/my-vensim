#include "unit_System.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Flow.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\MyFlows.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\System.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\FlowConcrete.h"

#include <string>
#include <cstdio>
#include <assert.h>

using namespace std;

/// Unit tests for System implementation.

void unit_System_constructor ()
{
	System* s = new SystemConcrete ();
	s->setConnection(false);
	
	assert (s->isConnected() == false);
}

void unit_System_copy_constructor ()
{
	SystemConcrete* s1 = new SystemConcrete ();
	s1->setEnergy(4);
	
	SystemConcrete* s2 = new SystemConcrete (*s1);
	
	assert (s2->getEnergy() == s1->getEnergy());
}

void unit_System_setEnergy ()
{
	System* system = new SystemConcrete ();
	system->setEnergy(9);
	
	assert (system->getEnergy() == 9);
}

void unit_System_getEnergy ()
{
	System* system = new SystemConcrete ();
	system->setEnergy(4);
	
	assert (system->getEnergy() == 4);
}

void unit_System_setConnection ()
{
	System* system = new SystemConcrete ();
	system->setConnection(true);
	
	assert (system->isConnected() == true);
}

void unit_System_isConnected ()
{
	System* system = new SystemConcrete ();
	system->setConnection(true);
	
	assert (system->isConnected() == true);
}

void unit_System_setLabel ()
{
	System* system = new SystemConcrete();
	system->setLabel("testeSetLabelSystem");
	
	assert (system->getLabel() == "testeSetLabelSystem");
}

void unit_System_getLabel ()
{
	System* system = new SystemConcrete();
	system->setLabel("testLabel");
	
	assert (system->getLabel() == "testLabel");
}

SystemConcrete& unit_System_operator ()
{
	System* s = new SystemConcrete ();

	SystemConcrete rSystem;
	rSystem.setLabel("testeOperatorSystem");
	
	s = &rSystem;
	
	assert (s->getLabel() == rSystem.getLabel());
}

void run_unit_test_System ()
{
	void unit_System_setEnergy (); 

	void unit_System_getEnergy (); 

	void unit_System_setConnection (); 
	
	void unit_System_isConnected (); 
		
	void unit_System_setLabel (); 
		
	void unit_System_getLabel ();		
		
	System& unit_System_operator ();
}

#ifndef  MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\test\unit\unit_Flow.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\test\unit\unit_System.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\test\unit\unit_Model.h"

/// Method that calls the unit tests for System, Flow and Model.

int main_unit_tests ()
{
	run_unit_test_System ();	
	
	run_unit_test_Flow ();
	
	run_unit_test_Model ();
	
	return 1;
}

#endif

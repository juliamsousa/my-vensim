#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Flow.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\System.h"

/// Unit tests for class Model.

void unit_Model_constructor ();
		
void unit_Model_getFlow (); 
		
void unit_Model_getSystem (); 
		
void unit_Model_add (Flow* f);
		
void unit_Model_add (System* s);
		
void unit_Model_remove (Flow* f);
		
void unit_Model_remove (System* s);
		
void unit_Model_report ();

void run_unit_test_Model ();

#endif

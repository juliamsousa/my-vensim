#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Flow.h"

/// Unit tests for class Flow.

void unit_Flow_construtor ();
		
void unit_Flow_copy_constructor ();

void unit_Flow_setLabel (); 
		
void unit_Flow_getLabel ();		

void unit_Flow_setConnection ();

void unit_Flow_connectFlow (); 
		
void unit_Flow_isConnected ();
		
void unit_Flow_wasExecuted ();		
		
void unit_Flow_setExecution (); 
	
void unit_Flow_setSource (); 
			
void unit_Flow_getSource ();
	
void unit_Flow_setDestiny (); 
		
void unit_Flow_getDestiny ();
		
Flow& unit_Flow_operator ();
	
void run_unit_test_Flow ();

#endif

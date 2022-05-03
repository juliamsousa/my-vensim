#ifndef  MAIN_FUNCTIONAL_TESTS
#define MAIN_FUNCTIONAL_TESTS

#include "functional_tests.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\src\Model.h"

/// Method that calls all the functional tests.

int main_functional_tests (Model* m, int start, int end, int step)
{	
    exponentialExecutionTest (m, start, end, step);

    logisticalExecutionTestModel (m, start, end, step);

    complexExecutionTestModel (m, start, end, step);

    return 1;

}

#endif

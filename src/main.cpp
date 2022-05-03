#include "Flow.h"
#include "System.h"
#include "Model.h"
#include "MyFlows.h"

#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\test\unit\main_unit_tests.h"
#include "C:\Users\Usuario\Documents\UFOP\4º semestre\Engenharia de Software I\Sprints\5\MyVensim\test\functional\main_functional_tests.h"

using namespace std;


int main(int argc, char** argv) 
{	

	// cria o modelo.
	Model* model = Model::getInstanceModel();

	// roda os testes funcionais.
	main_functional_tests (model, 1, 100, 1);
	
	// roda os testes unitarios.
	main_unit_tests ();
	
	// reporta os resultados da execucao.
//	model->report();
	
	// limpa o conteiner model.
	model->clearModel();
	
	return 0;
}

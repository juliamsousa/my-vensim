# my-vensim
Repositório contendo o projeot desenvolvido na disciplina de Engenharia I. O projeto consiste em uma versão própria do sistema Vensim, que permite a simulação e cálculo de dinâmica de sistemas.

1. Introdução
Esse trabalho consiste na construção de uma API de um simulador de modelos descritos segundo o paradigma de Dinâmica de Sistemas. Para isso, foram levantados diferentes alternativas de uso para essa API, assim como a geração de pseudocódigos para cada caso de uso. 
	A partir disso foi construído um diagrama UML para especificar a API (Application Programming Interface) de uma biblioteca C++ destinada ao desenvolvimento de modelos ambientais baseados na Teoria de Sistemas. 
2. Casos de Uso
 	
Figura 1: Nesse caso temos um único fluxo sem fonte ou destino.
 
Figura 2: Nesse caso temos um fluxo atrelado apenas a um sistema de origem.
 
Figura 3: Nesse caso temos um fluxo atrelado apenas a um sistema de destino.
 
Figura 4: Nesse caso temos um fluxo atrelado a um sistema de origem e outro de destino.

 
Figura 5: Nesse caso temos múltiplos fluxos atrelados a diferentes sistemas de origem e destino.


3. Pseudocódigos

Para o primeiro caso de uso em que temos um único fluxo sem fonte ou destino:

#include <MyVensim.h>
main ()
{
	// instancia um modelo
	Model m();
	// instancia um fluxo
	Flow f();
	
	// adiciona o fluxo ao modelo
	m.add(f);
	
	// executa o modelo e reporta os valores obtidos
	m.execute();
	m.report();
}


	Para o segundo caso de uso em que temos um fluxo atrelado apenas a um sistema de origem:

#include <MyVensim.h>
main ()
{
	// instancia um modelo
	Model m();
	// instancia um fluxo
	Flow f();
	// instancia um sistema
	System sOrigem();
	
	// adiciona o fluxo ao modelo
	m.add(f);
	// adiciona o sistema ao modelo
	m.add(sOrigem);
	
	// conecta o fluxo ao sistema de origem
	f.connect (sOrigem);
	
	// executa o modelo e reporta os valores obtidos
	m.execute();
	m.report();
}




	Para o terceiro caso de uso em que temos caso temos um fluxo atrelado apenas a um sistema de destino:

#include <MyVensim.h>
main ()
{
	// instancia um modelo
	Model m();
	// instancia um fluxo
	Flow f();
	// instancia um sistema
	System sDestino();
	
	// adiciona o fluxo ao modelo
	m.add(f);
	// adiciona o sistema ao modelo
	m.add(sDestino);
	
	// conecta o fluxo ao sistema de destino
	f.connect (sDestino);
	
	// executa o modelo e reporta os valores obtidos
	m.execute();
	m.report();
}

	Para o quarto caso de uso em que temos um fluxo atrelado a um sistema de origem e outro de destino:

#include <MyVensim.h>
main ()
{
	// instancia um modelo
	Model m();
	// instancia um fluxo
	Flow f();
	// instancia sistemas
	System sDestino();
	System sOrigem();
	
	// adiciona o fluxo ao modelo
	m.add(f);
	// adiciona os sistema de origem e destino ao modelo
	m.add(sDestino);
	m.add(sDestino);
	
	// conecta o fluxo aos sistema de origem e destino
	f.connect (sOrigem, sDestino);
	
	// executa o modelo e reporta os valores obtidos
	m.execute();
	m.report();
}
	Para o quinto caso de uso em que temos múltiplos fluxos atrelados a diferentes sistemas de origem e destino:

#include <MyVensim.h>
main ()
{
	// instancia um modelo
	Model m();
	// instancia os fluxos
	Flow f();
	Flow g();
		Flow r();
	Flow t();
	Flow u();
	Flow v();
	// instancia os sistemas
	System q1();
	System q2();
		System q3();
	System q4();
	System q5();

	// adiciona o fluxo ao modelo
	m.add(f);
	m.add(g);
	m.add(r);
	m.add(t);
	m.add(u);
	m.add(v);

	// adiciona os sistema de origem e destino ao modelo
	m.add(q1);
	m.add(q2);
		m.add(q3);
	m.add(q4);
	m.add(q5);

	// conecta o fluxo aos sistema de origem e destino
	f.connect (q1, q2);
		g.connect (q1, q3);
	r.connect (q2, q5);
	t.connect (q2, q3);
	u.connect (q3, q4);
	v.connect (q4, q1);

	// executa o modelo e reporta os valores obtidos
	m.execute();
	m.report();
}




4. Conclusão
Com os dados levantados anteriormente foi construída um diagrama UML simplificado, que foi implementado e melhorado através de sprints que decorreram-se ao longo do desenvolvimento da disciplina de Engenharia de Software I.

 
Figura 6: API inicial, idealizada a partir dos requisitos e análises de casos de uso do simulador de Sistemas Dinâmicos.


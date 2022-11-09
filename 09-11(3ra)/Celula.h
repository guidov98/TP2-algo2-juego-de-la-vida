#ifndef CELULA_H_
#define CELULA_H_

#include "Gen.h"

#ifndef NULL
#define NULL 0
#endif /* NULL */

class Celula{
private:
	Gen * gen1;
	Gen * gen2;
	Gen * gen3;
public:
	Celula();
	Celula(int gene1, int gene2, int gene3);
	
	void setGen1(int cargaGenetica);
	void setGen2(int cargaGenetica);
	void setGen3(int cargaGenetica);
	void setGens(int cargaGenetica1, int cargaGenetica2, int cargaGenetica3);
	
	int getCargaGeneticaGen1();
	int getCargaGeneticaGen2();
	int getCargaGeneticaGen3();
	
	Gen * getGen1();
	Gen * getGen2();
	Gen * getGen3();

	~Celula();
};


#endif /* CELULA_H_ */

#ifndef CELULA_H_
#define CELULA_H_

#include "Gen.h"

#ifndef NULL
#define NULL 0
#endif /* NULL */

enum estado{
	Viva,Muerta
};

class Celula{
private:
	Gen * gen1;
	Gen * gen2;
	Gen * gen3;
public:
	Celula();
	Celula(int gene1, int gene2, int gene3);
	void setGen1(Gen gene);
	void setGen2(Gen gene);
	void setGen3(Gen gene);
	void setGens(Gen gene1, Gen gene2, Gen gene3);
	Gen * getGen1();
	Gen * getGen2();
	Gen * getGen3();
};


#endif /* CELULA_H_ */

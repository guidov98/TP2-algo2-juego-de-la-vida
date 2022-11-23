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
	/*	Pre:  -
		Post: crea una celula con 3 genes, todos con carga genetica 0 y maximo de carga genetica en MAXIMO_GEN*/
	Celula();

	/*	Pre:  -
		Post: crea una celula con 3 genes, cada uno con el valor respectivo de gene1, gene2 y gene3, y maximo de carga genetica en MAXIMO_GEN*/
	Celula(int gene1, int gene2, int gene3);
	
	/*	Pre:  cargaGenetica debe ser menor que MAXIMO_GEN
		Post: setea el gen1 con cargaGenetica*/
	void setGen1(int cargaGenetica);
	
	/*	Pre:  cargaGenetica debe ser menor que MAXIMO_GEN
		Post: setea el gen2 con cargaGenetica*/
	void setGen2(int cargaGenetica);
	
	/*	Pre:  cargaGenetica debe ser menor que MAXIMO_GEN
		Post: setea el gen3 con cargaGenetica*/
	void setGen3(int cargaGenetica);
	
	/*	Pre:  cargaGenetica debe ser menor que MAXIMO_GEN
		Post: setea el gen1 con cargaGenetica, setea el gen2 con cargaGenetica, setea el gen3 con cargaGenetica*/
	void setGens(int cargaGenetica1, int cargaGenetica2, int cargaGenetica3);
	
	/*	Pre:  -
		Post: devuelve la carga genetica del gen1*/
	int getCargaGeneticaGen1();

	/*	Pre:  -
		Post: devuelve la carga genetica del gen2*/
	int getCargaGeneticaGen2();

	/*	Pre:  -
		Post: devuelve la carga genetica del gen3*/
	int getCargaGeneticaGen3();
	
	/*	Pre:  -
		Post: devuelve la el gen3*/
	Gen * getGen1();

	/*	Pre:  -
		Post: devuelve la el gen3*/
	Gen * getGen2();

	/*	Pre:  -
		Post: devuelve la el gen3*/
	Gen * getGen3();

	~Celula();
};


#endif /* CELULA_H_ */

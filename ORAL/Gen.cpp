#include "Gen.h"

Gen::Gen() {
	this->cargaGentica = 0;
	this->maximoDeCargaGentica = 0;
}
Gen::Gen(unsigned int maximoCargaGentica) {
	verificar(maximoCargaGentica, 0);
	this->cargaGentica = 0;
	this->maximoDeCargaGentica = maximoCargaGentica;
}

Gen::Gen(unsigned int maximoCargaGentica, unsigned int cargaGenticaTotal) {
	verificar( maximoCargaGentica, cargaGenticaTotal);
	this->maximoDeCargaGentica = maximoCargaGentica;
	this->cargaGentica = cargaGenticaTotal;
}

Gen::~Gen() {}

unsigned int Gen::getMaximoDeCargaGentica(){
	return this->maximoDeCargaGentica;
}

unsigned int Gen::getCargaGentica() {
	return this->cargaGentica;
}

void Gen::setCargaGentica(unsigned int cargaGenticaTotal) {
	verificar(this->maximoDeCargaGentica, cargaGenticaTotal);
	this->cargaGentica = cargaGentica;
}

void Gen::verificar(unsigned int maximoCargaGentica, unsigned int cargaGenticaTotal) {
	if (maximoCargaGentica < 0) {
		throw "El maximo de carga genetica debe ser mayor a 0.";
	}
	if (cargaGenticaTotal < 0) {
		throw "La carga genetica debe ser mayor a 0.";
	}
	if (maximoCargaGentica < cargaGenticaTotal) {
		throw "La carga genetica debe ser menor al maximo de carga genetica.";
	}
}

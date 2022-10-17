#include "intervaloNumerico.h"

/*
 * Pre:  limiteSuperior debe ser mayor a limiteInferior
 * 		 tipo tiene que ser Abierto o Cerrado
 * Post:
 */
IntervaloNumerico::IntervaloNumerico(float start, float end, tipoConjunto type){

	if (type==Abierto || type==Cerrado){
		tipo = type;
	}
	else{
		throw "Error";
	}

	if (limiteSuperior>=limiteInferior){
		limiteInferior = start;
		limiteSuperior = end;
	}
	else{
		throw "Error";
	}
}

/*
 * Pre:
 * Post: se devuelve el limite Inferior
 */
int IntervaloNumerico::getLimiteInferior(){
	return limiteInferior;
}

/*
 * Pre:
 * Post: se devuelve el limite Superior
 */
int IntervaloNumerico::getLimiteSuperior(){
	return limiteSuperior;
}

/*
 * Pre: el parametro ingresado tiene que ser menor al limite superior
 * Post: se setea el limite inferior
 */
void IntervaloNumerico::setLimiteInferior(float lim){
	if (limiteSuperior>=lim){
		limiteInferior = lim;
	}
	else{
		throw "Error";
	}
}

/*
 * Pre: el parametro ingresado tiene que ser mayor al limite inferior
 * Post: se setea el limite superior
 */
void IntervaloNumerico::setLimiteSuperior(float lim){
	if (lim>=limiteInferior){
		limiteSuperior = lim;
	}
	else{
		throw "Error";
	}
}

/*
 * Pre:
 * Post: se devuelve la longitud del intervalo
 */
int IntervaloNumerico::getLongitud(){
	return (limiteSuperior - limiteInferior);
}

/*
 * Pre:  num debe ser un numero real
 * Post: se true si el numero esta dentro del intervalo
 */
bool IntervaloNumerico::hasInside(float num){
	if (tipo==Abierto){
		return (num>limiteInferior && limiteSuperior>num);
	}
	else{
		return (num>=limiteInferior && limiteSuperior>=num);
	}
}

/*
 * Pre:
 * Post:
 */
bool IntervaloNumerico::hasIncluded(IntervaloNumerico intervalo){
	if (tipo==Abierto){
		return (intervalo.getLimiteInferior()>this->limiteInferior && this->limiteSuperior>intervalo.getLimiteSuperior());
	}
	else{
		return (intervalo.getLimiteInferior()>=this->limiteInferior && this->limiteSuperior>=intervalo.getLimiteSuperior());
	}
}

/*
 * Pre:
 * Post:
 */
bool IntervaloNumerico::isIncluded(IntervaloNumerico intervalo){
	if (intervalo.tipo==Abierto){
		return (this->limiteInferior>intervalo.getLimiteInferior() && intervalo.getLimiteSuperior()>this->limiteSuperior);
	}
	else{
		return (this->limiteInferior>=intervalo.getLimiteInferior() && intervalo.getLimiteSuperior()>=this->limiteSuperior);
	}
}
void IntervaloNumerico::mostrarIntervalo(){
	std::cout << limiteInferior << " - " << limiteSuperior;
}

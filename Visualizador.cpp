#include <sstream>
#include "Visualizador.h"
#include "tablero.h"

using namespace std;


Visualizador::Visualizador()
{
	this->capa.SetBitDepth(8);
    //Definir ancho, prof y pixeles por casillero
	this->capa.SetSize(ANCHO_TABLERO * PIXELES_POR_CASILLERO, PROFUNDIDAD_TABLERO * PIXELES_POR_CASILLERO);
}

Visualizador::~Visualizador(){

}

void Visualizador::exportarImagen(unsigned int altura)
{
	string nombreArchivo = "Tablero_Imagen_";
	stringstream alturaStr;
	alturaStr << altura;
	nombreArchivo = nombreArchivo + alturaStr.str() + ".bmp";

	this->capa.WriteToFile(nombreArchivo.c_str());
}
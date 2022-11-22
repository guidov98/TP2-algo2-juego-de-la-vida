#ifndef GEN_H_
#define GEN_H_

#include "Constantes.h"

#include "Funciones.h"

class Gen {

	private:
		unsigned int maximoDeCargaGentica;
		unsigned int cargaGentica;

	public:

		/**
		 * pre: 
		 * pos: deja el gen creado con maximoDeCargaGentica en 0, y cargaGentica en 0.
		 */
		Gen();

		/**
		 * pre: maximoDeCargaGentica es un valor 0 o positivo
		 * pos: deja el gen creado con maximoDeCargaGentica en "maximoDeCargaGentica", y cargaGentica en 0.
		 */
		Gen(unsigned int maximoDeCargaGentica);

		/**
		 * pre: maximoDeCargaGentica es un valor 0 o positivo, cargaGentica tiene un valor entre 0 y maximoDeCargaGentica inclusive
		 * pos: deja el gen creado con maximoDeCargaGentica en "maximoDeCargaGentica", y cargaGentica en cargaGentica.
		 */
		Gen(unsigned int maximoDeCargaGentica, unsigned int cargaGentica);

		/**
		 * pre: -
		 * pos: -
		 */
		virtual ~Gen();

		/**
		 * pre: -
		 * pos: devuelve la cargaGentica
		 */
		unsigned int getCargaGentica();

		/**
		 * pre: -
		 * pos: devuelve el maximoDeCargaGentica
		 */
		unsigned int getMaximoDeCargaGentica();

		/**
		 * pre: la cargaGentica debe ser un valor entre 0 y maximoDeCargaGentica inclusive
		 * pos: cambia el valor de cargaGentica
		 */
		void setCargaGentica(unsigned int cargaGentica);

		Gen operator= (Gen const &gene);
		Gen operator+ (Gen const &gene);

		int average(Gen * genes, int cantidad);

	private:
		/**
		 * pre: -
		 * pos: da error si maximoDeCargaGentica o cargaGentica no respeta los rangos
		 */
		void verificar(unsigned int maximoDeCargaGentica, unsigned int cargaGentica);
};



#endif /* GEN_H_ */

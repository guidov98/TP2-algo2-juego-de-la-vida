#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

class Funciones{
	public:
	static void bienvenida(){
		std::cout << "╔══════════════════════╗" << std::endl;
		std::cout << "║ JUEGO DE LA VIDA 2.0 ║" << std::endl;
		std::cout << "╚══════════════════════╝" << std::endl;
	}

	static int pedirInput(int minimo){
		int output = 0;
		std::cout << "Ingrese un valor mayor a" << minimo << ": ";
		std::cin >> output;
		while(output<minimo){
			std::cout << std::endl;
			std::cout << "Ingrese un valor mayor a" << minimo << ": ";
			std::cin >> output;
		}
		return output;
	}
	static int pedirInput(int minimo, int maximo){
		int output = 0;
		std::cout << "Ingrese un valor entre " << minimo << " y " << maximo << ": ";
		std::cin >> output;
		while(output<minimo || output>maximo){
			std::cout << std::endl;
			std::cout << "Ingrese un valor entre " << minimo << " y " << maximo << ": ";
			std::cin >> output;
		}
		return output;
	}
	static int elegirConfiguracion(){
		std::cout << "Quiere elegir una configuracion o prefiere elegir manualmente las celulas?" << std::endl;
		std::cout << "1- Configuracion 1" << std::endl;
		std::cout << "2- Configuracion 2" << std::endl;
		std::cout << "3- Configuracion 3" << std::endl;
		std::cout << "4- Configurar manualmente" << std::endl;
		return (pedirInput(1,4)-1);
	}

};





#endif
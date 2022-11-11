using namespace std;

int main(){

    int respuestaUsuario;

    cout << "Bienvenidos al Juego de la Vida V2.0!!!" << endl;

    //Inicializacion de Tablero:
	cout << "Se arma el campo de juego, elija que configuracion quiere jugar (Entre 1 y 3): " << endl;
    cin >> respuestaUsuario;

    switch(respuestaUsuario){
	case 1:
	  juegoDeLaVida->iniciarConfiguracionUno();
	  break;
	case 2:
	  juegoDeLaVida->iniciarConfiguracionDos();
	  break;
	case 3:
	  juegoDeLaVida->iniciarConfiguracionTres();
	  break;
	default:
	  break;
	}

}
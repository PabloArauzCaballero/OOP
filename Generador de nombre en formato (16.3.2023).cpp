#include <iostream>
#include <string>
using namespace std;
string generadorDeEspacios(int numeroEspacios) {
	string salida = "";
	for (int i = 0; i < numeroEspacios; i++) {
		salida = salida + " ";
	}
	return salida;
}
void main(){
	int numeroEspacios, longitudNombre, longitudConstanteCadena; // Declaración de variables tipo numérico
	string nombre, lineaCentral, espacios,
		asterisco = "**************************************************", 
		miNombreEsCadena="Mi nombre es "; // Declaración de variables 
	cout << "Ingrese su nombre: ";
	cin >> nombre;
	longitudNombre = nombre.length();
	longitudConstanteCadena = miNombreEsCadena.length();
	if ((longitudNombre+longitudConstanteCadena)% 2 != 0) {
		asterisco = asterisco + "*";
	}
	numeroEspacios = (asterisco.length() - longitudNombre-longitudConstanteCadena) / 2.0 - 1;
	espacios = generadorDeEspacios(numeroEspacios);
	lineaCentral = "*" + espacios + miNombreEsCadena + nombre + espacios+"*";
	cout << asterisco << endl;
	cout << lineaCentral << endl;
	cout << asterisco << endl;
}
/*
*   ENTRADA: Nombre
*   SALIDA: Texto de asteristos con nombre centrado
*			**************************************************
*			*               Mi nombre es Pablo               *   
*			**************************************************
*			(Si la longitud del texto es impar, el numero de asteriscos debe ser impar)
*			(Si el numero de asteriscos es par, el numero de asteriscos debes er par)
* 
*/

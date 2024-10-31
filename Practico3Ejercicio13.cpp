#include <iostream>
#include <math.h>
using namespace std;
void main(){
	   /*
    * Hacer un programa que imprima la tabla de sumar decimal (1 al 10), 
    * en el formato que usted elija.
    */
    int numero;
    string acumulador = "";
    cout << "Ingrese la cantidad de numeros: ";
    cin >> numero;
    for (int i = 1; i <= numero; i++ ) {
        acumulador = acumulador + " + " + to_string(i);
    }
    acumulador = acumulador.substr(3);
    cout << acumulador << endl;
}

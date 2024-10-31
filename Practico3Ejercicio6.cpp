#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  int acumulador = 0, base, numeroNDeseado;
    cout << "Ingrese el numero deseado: ";
    cin >> numeroNDeseado;
    cout << "Base Ingresada: ";
    cin >> base;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + pow(base, i);
    }
    cout << "Numero Factorial = " << acumulador << endl;
}

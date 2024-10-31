#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (Cuadrados): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + pow(i,2);
    }
    cout << "Suma Cuadrados = " << acumulador << endl;
}

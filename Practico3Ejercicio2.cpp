#include <iostream>
#include <math.h>
using namespace std;
void main(){
	   int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (Impares): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        if (i % 2 != 0) acumulador = acumulador + i;
    }
    cout << "Suma Impares = " << acumulador << endl;
}

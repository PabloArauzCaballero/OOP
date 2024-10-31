#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  int acumulador = 0, numeroNDeseado, factor = 1;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (alternado de positivos y negativos): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        cout << i * factor << endl;
        acumulador = acumulador + i*factor;
        factor = factor * (-1);
    }
    cout << "Suma Alternados = " << acumulador << endl;
}

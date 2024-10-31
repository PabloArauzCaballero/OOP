#include <iostream>
#include <math.h>
using namespace std;
void main(){
    int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva: ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + i;
    }
    cout << "Suma = " << acumulador << endl;
 }

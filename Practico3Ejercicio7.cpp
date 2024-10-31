#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  int acumulador = 1, numeroNDeseado;
    bool esCero, esNegativo;
    cout << "Ingrese el número al que desea obtener su factorial: ";
    cin >> numeroNDeseado;
    esCero = numeroNDeseado == 0;
    esNegativo = numeroNDeseado < 0;
    if (esCero) acumulador = 0;
    else if (esNegativo){
        cout << "Error" << endl;
        return;
    }
    else for (int i = 1; i <= numeroNDeseado; i++) acumulador = acumulador * i;
    cout << "Numero Factorial = " << acumulador << endl;
}

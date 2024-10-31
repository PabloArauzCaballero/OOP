#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  int acumulador = 1, numeroNDeseado;
    cout << "Ingrese el numero factorial: ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador*i;
    }
    cout << "Numero Factorial = " << acumulador << endl;
}

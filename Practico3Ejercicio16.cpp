#include <iostream>
#include <math.h>
using namespace std;
void main(){
	  /*
    * Hacer un programa para determinar si un numero N es primo.  
      Un número es primero si y solo si se tiene dos divisores 1 y N(uno y si mismo).
    */
    int divisor, numeroN;
    cout << "Ingrese el numero N= ";
    cin >> numeroN;
    if (numeroN == 1) {
        cout << "No es primo (Caso Especial 1)" << endl;
        return;
    }
    for (int i = 2; i < numeroN; i++) {
        if (numeroN % i == 0) {
            cout << "No es primo" << endl;
            return;
        }
    }
    cout << "Es primo" << endl;
}

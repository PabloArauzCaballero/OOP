#include <iostream>
#include <math.h>
using namespace std;
void main(){
    int numero1, numero2, numerosOrdenados[2] = {}, resto, divisor;
    cout << "Ingrese el numero 1: ";
    cin >> numero1;
    cout << "Ingrese el numero 2: ";
    cin >> numero2;
    if (numero1 > numero2) {
        numerosOrdenados[0] = numero1;
        numerosOrdenados[1] = numero2;
    }
    else {
        numerosOrdenados[0] = numero2;
        numerosOrdenados[1] = numero1;
    }
    resto = numerosOrdenados[0] % numerosOrdenados[1];
    divisor = numerosOrdenados[1];
    while (resto != 0) {
        divisor = resto;
        resto = divisor % resto;
    }
    cout << "M.C.D. (" << numerosOrdenados[0] << ";" << numerosOrdenados[1] <<") = " << divisor << endl;
}

#include <iostream>
#include <string>
using namespace std;

void main() {
    /*6.	Dado un número entero en base 8, comprobar si alguno de sus dígitos
            no corresponden a su base.
        Ej. El número 2762823, el dígito 8 no corresponde a la base
    */
    string numero, strComparinson;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    for (int i = 0; i < numero.size(); i++) {
        strComparinson = numero[i];
        if (strComparinson.compare("8") || strComparinson.compare("9")) {
            cout << "El numero " << numero << " NO corresponde a la base 8." << endl;
            return;
        }
    }
    cout << "El numero " << numero << " corresponde a la base 8." << endl;
}

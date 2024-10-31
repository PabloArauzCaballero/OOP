#include <iostream>
#include <string>
using namespace std;
void main() {
    /*
    1.	Dado un número entero N, hacer un programa para sumar los dígitos de
        cada uno de ellos.
    Ej. Si N= 45634,  la suma es 4+5+6+3+4=22
    */
    string numero;
    int acumulador = 0;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    for (int i = 0; i < numero.size(); i++) {
        string num;
        num = numero[i];
        acumulador = acumulador + stoi(num);
     }
    cout << "Suma de dígitos hasta que sea menor que diez = " << acumulador << endl;
}

#include <iostream>
#include <string>
using namespace std;
void main() {
    /*
    *   5.Hallar el complemento a 9 de un número entero N.
    *    Ej. 4567, su complemento es 5432.
    */
    string numero, acumulador = "";
    int variableUtilitaria;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    for (int i = 0; i < numero.size(); i++) acumulador = acumulador + "9";
    cout << "Numero complementario : " << stoi(acumulador) - stoi(numero) << endl;
}

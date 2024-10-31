#include <iostream>
#include <string>
using namespace std;
void main() {
    /*
    * 3.	Hacer un programa para contar los dígitos
    *       pares que tiene un número N.
    * Ej. Si N= 5678312,  este tiene 3 dígitos pares (6, 8, 2).
    */
    string numero;
    int contador = 0;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    for (int i = 0; i < numero.size(); i++) {
        string num;
        num = numero[i];
        if (stoi(num) % 2 == 0) { contador = contador + 1;}
    }
    cout << "La cantidad de elementos pares son : " << contador << endl;
}

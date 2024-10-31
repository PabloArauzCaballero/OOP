#include <iostream>
#include <string>
using namespace std;

void main() {
    /*
    * 4.	Dado un número entero, comprobar si el número es capicúa,
            es decir, si leídos de la izquierda a la derecha y viceversa dan
            el mismo valor o número.  Ej. 34543
    */
    string numero, numeroInvertido = "";
    int numeroN;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    cout << "Tamaño : " << numero.size() << endl;
    numeroN = numero.size();
    for (int i = numeroN; i >= 0; i--) { numeroInvertido = numeroInvertido + numero[i]; }
    cout << "Numero Invertido Z = " << numeroInvertido << endl;
    if (numero.compare(numeroInvertido)){cout << "Conclusión: Es capicua." << endl;}
    else {cout << "Conclusión: No es capicua" << endl;}
}

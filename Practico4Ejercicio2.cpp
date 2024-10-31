#include <iostream>
#include <string>
using namespace std;
void main() {
    /*
     * 2.Dado un número entero N, hacer un programa para invertir el
        número en otra variable Z.
        Ej. Si N= 456721, el número invertido es Z=127654.
    */
    string numero, numeroInvertido = "";
    int numeroN;
    cout << "Ingrese el numero: " << endl;
    cin >> numero;
    cout << "Tamaño : " << numero.size() << endl;
    numeroN = numero.size();
    for (int i = numeroN; i >= 0; i--) { numeroInvertido = numeroInvertido + numero[i]; }
    cout << "Numero Invertido Z = " << numeroInvertido << endl;
}

/*
* # Pablo Arauz Caballero
* ENTRADA: Coeficientes a,b,c de la ecuacion general cuadratica
* SALIDA: Solucion unica / ERRORES
* 
*/
#include <iostream>
using namespace std;

void main() {
    float a, b, c;
    cout << "Ingrese el coeficiente del termino cuadratico: ";
    cin >> a;
    cout << "Ingrese el coeficiente del termino lineal: ";
    cin >> b;
    cout << "Ingrese el coeficiente del termino independiente: ";
    cin >> c;
    if (a == 0) 
         cout << "Los coeficientes ingresados no corresponden a una ecuacion cuadratica." << endl;
    else 
        if ((b * b - 4 * a * c) == 0) {
            cout << "Los coeficientes ingresados corresponde a solucion unica" << endl;
            cout << "Solucion unica: " << -b / (2 * a) << endl;
        }
        else 
            cout << "Los coeficiente ingresados corresponde a solucion NO unica" << endl;
}

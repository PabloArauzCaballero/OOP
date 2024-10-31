// Ejercicio2Practico1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
void main(){
    float presupuesto;
    cout << "Ingrese el presupuesto asignado total ($): ";
    cin >> presupuesto;
    cout << "Presupuesto asignado a Traumatologia: " << presupuesto * 0.3 << endl;
    cout << "Presupuesto asignado a Ginecologia: " << presupuesto * 0.4 << endl;
    cout << "Presupuesto asignado a Pediatria: " << presupuesto * 0.3 << endl;
}

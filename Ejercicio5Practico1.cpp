/*
* 5.	Calcular el interés  simple  que ganará un capital C en un periodo de N años, conociendo que la tasa de interés es T.
*       Suponer que el interés es pagadero por cada año y no es capitalizable.
*/
#include <iostream>
using namespace std;

void main() {
    float capital, periodo, tasaDeInteres, interes;
    cout << "Ingrese el capital en $: ";
    cin >> capital;
    cout << "Ingrese el tiempo/periodo en anos: ";
    cin >> periodo;
    cout << "Ingrese la tasa de interes en periodizacion anual: ";
    cin >> tasaDeInteres;
    interes = capital * (tasaDeInteres / 100) * periodo;
    cout << "Interes ganado: " << interes << endl;
}
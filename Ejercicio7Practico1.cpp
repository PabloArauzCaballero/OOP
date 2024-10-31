/*
* 7.	Calcular el interés compuesto I que ganará un capital C en un periodo de N años, 
		conociendo que la tasa de interés es T.
*/

#include <iostream>
#include <math.h>
using namespace std;

void main(){
	float capital, periodo, tasaDeInteres,interes;
	cout << "Ingrese el captial en $:";
	cin >> capital;
	cout << "Ingrese el periodo en anos: ";
	cin >> periodo;
	cout << "Ingrese la tasa de interes anual: ";
	cin >> tasaDeInteres;
	cout << "(La capitalización considerada es mensual)" << endl;
	interes = capital * pow((1 + tasaDeInteres / 1200), periodo * 12)-capital;
	cout << "El interes compuesto es: " << interes <<" [$] " << endl;
}

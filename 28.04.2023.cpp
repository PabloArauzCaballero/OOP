#include <iostream>
#include <string>
#define MAX 100
using namespace std;
double promedio(double a[], int size);

void main(){
	int numElem=0;
	bool variableBandera = true;
	cout << "Ingrese la cantidad de elementos: ";
	while (variableBandera) {
		try {
			cin >> numElem;
			if (numElem < 0) cout << "Solo se aceptan valores positivos" << endl;
			else if (numElem > 100) cout << "El limite de ingreso maximo es de 100 valores." << endl;
			else variableBandera = false;
		}
		catch (const std::exception& e) {
			cout << "El valor ingresado no es numero" << endl;
			cout << e.what();
		}
	}
	double elements[MAX] = {};
	for (int i = 0; i < numElem; i++) {
		float value;
		cin >> value;
		elements[i] = value;
	}
	cout << "Promedio = " << promedio(elements,numElem) << endl;
}

double promedio(double a[], int size) {
	double aux = 0;
	for (int i = 0; i < size; i++) 	aux = aux + a[i];
	return aux / size;
}

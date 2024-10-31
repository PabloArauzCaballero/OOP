#include <iostream>
using namespace std;
int main()
{
	float monto, IUE;
	cout << "Ingrese las utilidades antes de impuestos: ";
	cin >> monto;
	IUE = monto * 0.25;
	cout << "El impuesto a pagar es de: " << IUE << endl;
	return 0;
}


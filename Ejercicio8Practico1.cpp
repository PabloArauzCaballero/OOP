/*
*	8.	Calcule la solución de un sistema de dos ecuaciones con 2 variables de la forma:
	Ax + By = C 
	Dx + Ey = F 
	El algoritmo debe leer como entrada los 6 coeficientes de la ecuación, y dar como salida la solución X, Y, 
	considerando todos los tipos de solución posibles para todos los valores. 
*/

#include <iostream>
using namespace std;

void main(){
	float a, b, c, d, e, f,x,y;
	cout << "Ingrese el coeficiente x de la primera ecuacion: ";
	cin >> a;
	cout << "Ingrese el coeficiente y de la primera ecuacion: ";
	cin >> b;
	cout << "Ingrese el termino independiente de la primera ecuacion: ";
	cin >> c;
	cout << "Ingrese el coeficiente x de la segunda ecuacion: ";
	cin >> d;
	cout << "Ingrese el coeficiente y de la segunda ecuacion: ";
	cin >> e;
	cout << "Ingrese el termino independiente de la segunda ecuacion: ";
	cin >> f;
	y = (c * d - a * f) / (b * d - a * c);
	x = (c - b * y) / a;
	cout << "El valor de x es de : " << x << endl;
	cout << "El valor de y es de : " << y << endl;
}
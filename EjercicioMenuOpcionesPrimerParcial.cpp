// EjercicioMenu.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
using namespace std;
int getTotalaPagar(int cantidadDeCamisas, float precioDeCamisa){
    int cantidadDeCamisas;
    float totalCompra;
    if (cantidadDeCamisas >= 3) {
        totalCompra = cantidadDeCamisas * precioDeCamisa * 0.80;
    }
    else {
        totalCompra = cantidadDeCamisas * precioDeCamisa * 0.9;
    }
    return totalCompra;
}
int getSolucionUnica(float a, float b, float c){
    float discrimante = (b * b - 4 * a * c);
    if (a == 0)
        cout << "Los coeficientes ingresados no corresponden a una ecuacion cuadratica." << endl;
    else
        if (discrimante== 0) {
            float solucion = -b / (2 * a);
            cout << "Los coeficientes ingresados corresponde a solucion unica" << endl;
            return solucion;
        }
        else
            cout << "Los coeficiente ingresados corresponde a solucion NO unica" << endl;
    return NULL;
}
void getPresupuestoAsignadoPorArea(float presupuesto) {
    cout << "Presupuesto asignado a Traumatologia: " << presupuesto * 0.3 << endl;
    cout << "Presupuesto asignado a Ginecologia: " << presupuesto * 0.4 << endl;
    cout << "Presupuesto asignado a Pediatria: " << presupuesto * 0.3 << endl;
}
void main(){
    int opcion;
    cout << "Menu: " << endl;
    cout << "1. Calcular el precio a pagar: " << endl;
    cout << "2. Calcular solucion unica: " << endl;
    cout << "3. Calcular presupuesto: " << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            int cantidadDeCamisas;
            float precioDeCamisas;
            cout << "Ingrese la cantidad de camisas: ";
            cin >> cantidadDeCamisas;
            cout << "Ingrese el precio de camisa: ";
            cin >> precioDeCamisas;
            cout << "El total de compra es: " << getTotalaPagar(cantidadDeCamisas,precioDeCamisas) << endl;
        break;
        case 2:
            float a, b, c;
            cout << "Ingrese el coeficiente del termino cuadratico: ";
            cin >> a;
            cout << "Ingrese el coeficiente del termino lineal: ";
            cin >> b;
            cout << "Ingrese el coeficiente del termino independiente: ";
            cin >> c;
            cout << "Solucion unica: " << getSolucionUnica(a,b,c) << endl;
        break;
        case 3:
            float presupuesto;
            cout << "Ingrese el presupuesto asignado total ($): ";
            cin >> presupuesto;
            getPresupuestoAsignadoPorArea(presupuesto);
        break;
        default:
            cout << "Error" << endl;
    }
}

#include <iostream>
using namespace std;
/*
* Si se tiene una compra de 3 camisas o mas se aplica un descuento del 20% sino de 10%
*/
int main(){
    int cantidadDeCamisas;
    float precioDeCamisa, totalCompra;
    cout << "Ingrese la cantidad de camisas: ";
    cin >> cantidadDeCamisas;
    cout << "Ingrese el precio de camisa: ";
    cin >> precioDeCamisa;
    if (cantidadDeCamisas>=3) {
        totalCompra = cantidadDeCamisas * precioDeCamisa * 0.80;
    }
    else {
        totalCompra = cantidadDeCamisas * precioDeCamisa * 0.9;
    }
    cout << "El total de compra: "<<totalCompra<<" Bs.";
}
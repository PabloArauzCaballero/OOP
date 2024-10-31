/*
* 4.	Deducir el salario neto de un trabajador a partir de la lectura del nombre, horas trabajadas al mes, 
        precio por hora, sabiendo que todo lo que se descuenta es un impuesto  RC-IVA de 13% sobre el salario bruto. 
        Los trabajadores que  ganan más de 8.272 bolivianos están obligados a  pagar el impuesto al Régimen Complementario al Impuesto al Valor Agregado (RC-IVA).  
*/
#include <iostream>
using namespace std;

void main() {
    float horasTrabajadas, precioPorHora, totalaPagar;
    cout << "Ingrese la cantidad de horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese el precio por hora: ";
    cin >> precioPorHora;
    totalaPagar = horasTrabajadas * precioPorHora;
    if (totalaPagar > 8272) {
        totalaPagar = totalaPagar * 0.87;
    }
    cout << "El salario neto (deducido de impuestos) es : " << totalaPagar << endl;
}
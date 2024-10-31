/*
* 6.Construir un programa que permita convertir una hora dada en formato de 24 horas (hora, minuto, segundo) 
    a su equivalente en formato de 12 horas (AM o PM). Por ejemplo si se introduce 14, 45, 10 (formato de 24 horas), 
    debe imprimirse 2, 45, 10 PM (formato 12 horas).
    ENTRADA: Hora, Minutos, Segundos (Formato 12 HORAS)
*/

#include <iostream>
#include <string>
using namespace std;

void main(){
    int horas, minutos, segundos, opcionElegida;
    const string opciones = "====Opciones Posibles====\n1. AM\n2. PM\n";
    bool validacionHoras, validacionMinutos, validacionSegundos;
    cout << "Ingrese las horas: ";
    cin >> horas;
    cout << "Ingrese los minutos: ";
    cin >> minutos;
    cout << "Ingrese los segundos: ";
    cin >> segundos;
    cout << opciones+"Ingrese la opción: ";
    cin>> opcionElegida;
    validacionHoras = horas > 12;
    validacionMinutos = minutos > 60;
    validacionSegundos = segundos > 60;
    if (validacionHoras) {
        cout << "Error de ingreso en horas" << endl;
    }else if (validacionMinutos) {
        cout << "Error de ingreso en minutos" << endl;
    }
    else if (validacionSegundos) {
        cout << "Error de ingreso en segundos" << endl;
    }
    if (opcionElegida==2) {
        cout << horas + 12 << ":" << minutos << ":" << segundos << endl;
    }
    else {
        cout << horas << ":" << minutos << ":" << segundos << endl;
    }
}

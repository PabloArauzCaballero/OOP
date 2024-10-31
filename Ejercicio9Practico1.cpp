/*
* 9.	Construir un algoritmo que lea una cantidad de SEGUNDOS y los convierta en HORAS, MINUTOS Y SEGUNDOS 
        Ejemplo:  3750 Segundos  1 Hora, 2 minutos, 30 Segundos

*/
#include <iostream>
using namespace std;
void main(){
    int cantidadSegundos, horas, minutos, segundosEsp;
    cout << "Ingrese la cantidad de segundos: " << endl;
    cin >> cantidadSegundos;
    horas = cantidadSegundos / 3600;
    minutos = (cantidadSegundos - horas * 3600) / 60;
    segundosEsp = cantidadSegundos- horas * 3600 - minutos * 60;
    cout << horas<<":"<<minutos<<":"<<segundosEsp<<endl;
}
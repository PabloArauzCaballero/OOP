#include <iostream>
#include <string>
using namespace std;
void main(){
  int horas = stoi(infoIngresante.substr(0,2));
    int minutos = stoi(infoIngresante.substr(3, 5));
    int segundos = stoi(infoIngresante.substr(6));
    bool validacionDelimitadores = infoIngresante.find(":"), 
         validacionSegundos = segundos >= 60;
    if (validacionSegundos) {
        segundos = segundos - 60;
        minutos = minutos + 1;
    }
    bool validacionMinutos = minutos >= 60;
    if (validacionMinutos) {
        minutos = minutos - 60;
        horas = horas + 1;
    }
    cout << "Horas = " << horas << endl;
    cout << "Minutos = " << minutos << endl;
    cout << "Segundos = " << segundos << endl;
}

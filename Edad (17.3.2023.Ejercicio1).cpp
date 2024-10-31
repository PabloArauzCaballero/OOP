#include <iostream>
#include <string>
using namespace std;
string condicionalEspecial(bool esMayorDeEdad) {
    if (esMayorDeEdad) {
        return "Es mayor de edad";
    }
    else {
        return "Es menor de edad";
    }
}
void main(){
    int edad; // Declaración variables de edad
    bool esMayorDeEdad;
    cout << "Ingrese la edad: ";  // Aclaración de información de entrada
    cin >> edad; // Lectura de información por teclado (consola)
    esMayorDeEdad = edad >= 18;
    if (esMayorDeEdad) { 
        cout << condicionalEspecial(edad) << " consecuentemente puede votar" << endl;
    }
    else {
        cout << condicionalEspecial (edad) << " consecuentemente no puede votar" << endl;
    }
}

// 16.3.2023.Ejercicio2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a, b, c, discriminante;  // Declaracion de variables
    double x1, x2;  // Decalaracion de variables
    cout << "Ingrese el coeficiente del x^2: "; // Aclaración de informacion de entrada
    cin >> a; // Lectura de informacion por teclado
    cout << "Ingrese el coeficeinte del x: "; // Aclaración de informacion de entrada
    cin >> b; // Lectura de informacion por teclado
    cout << "Ingrese el valor constante: "; // Aclaración de informacón de entrada
    cin >> c; // Lectura de información por teclado
    cout << "====================Raices reales====================" << endl;
    discriminante = b * b - 4 * a * c > 0;
    if (discriminante>0 && a>0) { 
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "X1 (Primera Raiz) : " << x1 << endl;
        cout << "X2 (Segunda Raiz): " << x2 << endl;
    }
    if(a==0) { // Validacion de casos contiguos
        cout<<"Discriminante: "<<discriminante<<endl;
        cout << "Error: COEFICIENTES INGRESADOS NO CORRESPONDEN A PARÁMTEROS DE UNA ECUACIÓN CUADRÁTICA";
    }
    if (discriminante < 0) { // Validacion de casos contiguos
        cout << "Error: SOLUCIONES NO REALES";
    }
    if (discriminante == 0) { // Validacion de casos contiguos
        x1 = -b / (2 * a);
        cout << "X (Única Raiz): " << x1 << endl;
    }
}

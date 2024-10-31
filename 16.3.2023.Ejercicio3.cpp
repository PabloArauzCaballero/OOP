// 16.3.2023.Ejercicio3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
using namespace std;
int main()
{
    int numero1, numero2, numero3;  // Declara las varaibles tipo numerico (enteros)
    bool validacion1, validacion2, validacion3;
    cout << "Ingrese tres numeros de entre 0 a 10: ";
    // Los numeros deben ser mayores o iguales a cero y menores que diez (validaciones de casos)
    validacion1 = numero1 >= 0 && numero1<=10;
    validacion2 = numero2 >= 0 && numero2 <= 10;
    validacion3 = numero3 >= 0 && numero3 <= 10;
    if (validacion1 && validacion2 && validacion3) {
        cout << "Promedio de los tres numeros: " << (numero1 + numero2 + numero3) / 3 << endl;
    }
    else {// Caso complementario
        cout << "Error" << endl;
    }
}

/*
  
  1 2 15   --> Error
  1 2 3 -->  Promedio
  
  */
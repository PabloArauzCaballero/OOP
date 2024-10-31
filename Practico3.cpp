#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void ejercicio1() {
    int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva: ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + i;
    }
    cout << "Suma = " << acumulador << endl;
}
void ejercicio2() {
    int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (Impares): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        if (i % 2 != 0) acumulador = acumulador + i;
    }
    cout << "Suma Impares = " << acumulador << endl;
}
void ejercicio3() {
    int acumulador = 0, numeroNDeseado;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (Cuadrados): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + pow(i,2);
    }
    cout << "Suma Cuadrados = " << acumulador << endl;
}
void ejercicio4() {
    int acumulador = 0, numeroNDeseado, factor = 1;
    cout << "Ingrese la cantidad de numeros que desea sumar de forma sucesiva (alternado de positivos y negativos): ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        cout << i * factor << endl;
        acumulador = acumulador + i*factor;
        factor = factor * (-1);
    }
    cout << "Suma Alternados = " << acumulador << endl;
}
void ejercicio5() {
    int acumulador = 1, numeroNDeseado;
    cout << "Ingrese el numero factorial: ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador*i;
    }
    cout << "Numero Factorial = " << acumulador << endl;
}
void ejercicio6() {
    int acumulador = 0, base, numeroNDeseado;
    cout << "Ingrese el numero deseado: ";
    cin >> numeroNDeseado;
    cout << "Base Ingresada: ";
    cin >> base;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador + pow(base, i);
    }
    cout << "Numero Factorial = " << acumulador << endl;
}
void ejercicio7() {
    int acumulador = 1, numeroNDeseado;
    bool esCero, esNegativo;
    cout << "Ingrese el número al que desea obtener su factorial: ";
    cin >> numeroNDeseado;
    esCero = numeroNDeseado == 0;
    esNegativo = numeroNDeseado < 0;
    if (esCero) acumulador = 0;
    else if (esNegativo){
        cout << "Error" << endl;
        return;
    }
    else for (int i = 1; i <= numeroNDeseado; i++) acumulador = acumulador * i;
    cout << "Numero Factorial = " << acumulador << endl;
}
void ejercicio8() {
    //	S= X/1! + X^2/2! + X^3/3! + ........X^n/n!
    int n, X;
    float acumulador=0, acumuladorFactorial=1;
    bool esCeroN;
    cout << "Ingrese el valor límite para calcular la sumatoria: ";
    cin >> n;
    cout << "Ingrese el valor de X: ";
    cin >> X;
    esCeroN = n == 0;
    if (!esCeroN) {
        for (int i = 1; i <= n; i++) {
            for (int ii = 1; ii <= n; ii++) {
                acumuladorFactorial = acumuladorFactorial * ii;
            }
            acumulador = acumulador + pow(X, i)/acumuladorFactorial;
            acumuladorFactorial = 1;
        }
        cout << "S = " << acumulador << endl;
        return;
    }
    cout << "Error" << endl;
}
void ejercicio9() {
    // S= X/1! - X^2/2! + X^3/3! - ........(+/-)X^n/n!
    int n, X, factor = 1;
    float acumulador = 0, acumuladorFactorial = 1;
    bool esCeroN;
    cout << "Ingrese el valor límite para calcular la sumatoria: ";
    cin >> n;
    cout << "Ingrese el valor de X: ";
    cin >> X;
    esCeroN = n == 0;
    if (!esCeroN) {
        for (int i = 1; i <= n; i++) {
            for (int ii = 1; ii <= n; ii++) {
                acumuladorFactorial = acumuladorFactorial * ii;
            }
            acumulador = acumulador + pow(X, i) / acumuladorFactorial;
            acumuladorFactorial = 1;
            factor = factor * -1;
        }
        cout << "S = " << acumulador << endl;
        return;
    }
    cout << "Error" << endl;
}
void ejercicio10() {
    //S= X/1! -  X^3/3! + X^5/5! - .......(+/-)X^n/n!;  n es impar
    int n, X, factor = 1;
    float acumulador = 0, acumuladorFactorial = 1;
    bool esCeroN;
    cout << "Ingrese el valor límite para calcular la sumatoria: ";
    cin >> n;
    cout << "Ingrese el valor de X: ";
    cin >> X;
    esCeroN = n == 0;
    if (!esCeroN) {
        for (int i = 1; i <= n; i+=2) {
            for (int ii = 1; ii <= n; ii++) {
                acumuladorFactorial = acumuladorFactorial * ii;
            }
            acumulador = acumulador + pow(X, i) / acumuladorFactorial;
            acumuladorFactorial = 1;
            factor = factor * -1;
        }
        cout << "S = " << acumulador << endl;
        return;
    }
    cout << "Error" << endl;
}

void ejercicio11() {
    /*
    * Hacer un programa para calcular el MCD (máximo común divisor) de 
    * dos números enteros, usando el algoritmo de Euclides.
    */
    int numero1, numero2, numerosOrdenados[2] = {}, resto, divisor;
    cout << "Ingrese el numero 1: ";
    cin >> numero1;
    cout << "Ingrese el numero 2: ";
    cin >> numero2;
    if (numero1 > numero2) {
        numerosOrdenados[0] = numero1;
        numerosOrdenados[1] = numero2;
    }
    else {
        numerosOrdenados[0] = numero2;
        numerosOrdenados[1] = numero1;
    }
    resto = numerosOrdenados[0] % numerosOrdenados[1];
    divisor = numerosOrdenados[1];
    while (resto != 0) {
        divisor = resto;
        resto = divisor % resto;
    }
    cout << "M.C.D. (" << numerosOrdenados[0] << ";" << numerosOrdenados[1] <<
        ") = " << divisor << endl;
}

void ejercicio12() {
    /*
    * Hacer un programa para calcular el MCM (mínimo común múltiplo) de dos 
    * números enteros, donde MCM= (AxB)/MCD
    */
    int numero1, numero2, numerosOrdenados[2] = {}, resto, divisor;
    cout << "Ingrese el numero 1: ";
    cin >> numero1;
    cout << "Ingrese el numero 2: ";
    cin >> numero2;
    if (numero1 > numero2) {
        numerosOrdenados[0] = numero1;
        numerosOrdenados[1] = numero2;
    }
    else {
        numerosOrdenados[0] = numero2;
        numerosOrdenados[1] = numero1;
    }
    resto = numerosOrdenados[0] % numerosOrdenados[1];
    divisor = numerosOrdenados[1];
    while (resto != 0) {
        divisor = resto;
        resto = divisor % resto;
    }
    cout << "MCM (" << numerosOrdenados[0] << ";" << numerosOrdenados[1] << ") = " <<
        (numero1 * numero2)/ divisor << endl;
}

void ejercicio13() {
    /*
    * Hacer un programa que imprima la tabla de sumar decimal (1 al 10), 
    * en el formato que usted elija.
    */
    int numero;
    string acumulador = "";
    cout << "Ingrese la cantidad de numeros: ";
    cin >> numero;
    for (int i = 1; i <= numero; i++ ) {
        acumulador = acumulador + " + " + to_string(i);
    }
    acumulador = acumulador.substr(3);
    cout << acumulador << endl;
}

void ejercicio14() {
    /*
    Hallar el n-esimo número de Fibonacci.  Un número de Fibonacci se obtiene de la siguiente forma:   
    F0 = 1, F1 = 1,  luego el siguiente o tercer número se obtiene sumando F2=F1 + F0= 1+1=2.     
    Cada número de Fibonacci se obtiene sumando los dos últimos, es decir, Fi = Fi-1 + Fi-2,  i=2, 3, 4,...
    */
    int acumuladorGeneral = 0, sumaDosAnteriores=0,numeroAnterior1=1, numeroAnterior2=1,
        contador = 0, n;
    cout << "Ingrese el numero n de la serie Fibbanoci: ";
    cin >> n;
    if (n == 1) acumuladorGeneral = 1;
    else for (int i = 0; i < n; i++) {
        acumuladorGeneral = acumuladorGeneral + sumaDosAnteriores;
        sumaDosAnteriores = numeroAnterior1 + numeroAnterior2;
        numeroAnterior1 = sumaDosAnteriores;
    }
    cout <<"S = " << acumuladorGeneral << endl;
}

void ejercicio15() {
    /*
    * Construir un reloj digital con el siguiente formato: HH:MM:SS.
    */
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

//  1 1 2 3 5 8  
void ejercicio16() {
    /*
    * Hacer un programa para determinar si un numero N es primo.  
      Un número es primero si y solo si se tiene dos divisores 1 y N(uno y si mismo).
    */
    int divisor, numeroN;
    cout << "Ingrese el numero N= ";
    cin >> numeroN;
    if (numeroN == 1) {
        cout << "No es primo (Caso Especial 1)" << endl;
        return;
    }
    for (int i = 2; i < numeroN; i++) {
        if (numeroN % i == 0) {
            cout << "No es primo" << endl;
            return;
        }
    }
    cout << "Es primo" << endl;
}

void main(){
    ejercicio12();
}

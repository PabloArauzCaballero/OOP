/*
* 
3.	Construir un algoritmo para calcular la nota de final de un alumno sabiendo que rindió 3 exámenes parciales 
    ponderados como 40 puntos, un examen final de 40 puntos, un proyecto final de 20 puntos.  La nota final es 
    la suma de los tres conceptos.
    ENTRADA: nota Parcial 1 , nota Parcial 2, nota Final, proyecto Final
    SALIDA: nota Ponderada

*/
#include <iostream>
using namespace std;

void main()
{
    float notaParcial1, notaParcial2, notaExamenFinal, notaProyectoFinal, notaFinal;
    cout << "Ingrese la nota del primer examen parcial: ";
    cin >> notaParcial1;
    cout << "Ingrese la nota del segundo examen parcial: ";
    cin >> notaParcial2;
    cout << "Ingrese la nota del examen final: ";
    cin >> notaExamenFinal;
    cout << "Ingrese la nota del proyecto final: ";
    cin >> notaProyectoFinal;
    notaFinal = notaParcial1 * 0.20 + notaParcial2 * 0.20 + notaExamenFinal * 0.40 + notaProyectoFinal * 0.20;
    cout << "La nota final es de : "<<notaFinal<<" puntos";
}

/*
*   OBJETIVO: Calcular el costo de producción
*   ENTRADA: Costo de materia prima, Costo de mano de obra, costos indirectos de fabricacion (En consola)
*   SALIDA: Costo de producción (En consola)
*   ALGORITMO:
*       Leer materiaPrima, manoDeObra, costosIndirectos;
*       Escribir materiaPrima + manoDeObra + costosIndirectos;
*/

#include <iostream>
using namespace std;
int main()
{
    int materiaPrima, manoDeObra, costosIndirectosFabricacion, costoDeProduccion; // Declaracion de variables locales
    cout << "Ingrese todos los Costos de Materias Primas (en Bs): "; // Aclaración de informacion solicitada por consola
    cin >> materiaPrima;  // Lectura de valores por teclado (Ingreso)
    cout << "Ingrese todos los Costos de Mano de Obra (en Bs): "; // Aclaración de información solictiada por consola
    cin >> manoDeObra; // Lectura de valores por teclado
    cout << "Ingrese todos los Costos Indirectos de Fabricación (en Bs): ";// Aclaración de información solicitada por consola
    cin >> costosIndirectosFabricacion; // Lectura de valores por teclado
    costoDeProduccion = materiaPrima + manoDeObra + costosIndirectosFabricacion; 
    // El costo de produccion se define como la suma de los costos de los factores asignables y no asignables
    cout << "El costo de producción (en Bs): " <<costoDeProduccion<< endl;// Impresión de resultados por consola
    return 0;
}

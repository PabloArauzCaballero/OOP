#include <iostream>
#define SIZE 1000
using namespace std;

void leerMatriz(int iMax, int jMax, int matriz[SIZE][SIZE]);
void imprimirMatriz(int iMax, int jMax, int matrix[SIZE][SIZE]);
void verificarSiMatrizEsMagica(int iMax, int jMax, int matrix[SIZE][SIZE]);

void main(){
    int matriz[SIZE][SIZE], filas, columnas, bandera;
    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;
    do {
        cout << "==================Menu==================" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Leer matriz" << endl;
        cout << "2. Imprimir matriz" << endl;
        cout << "3. Verificar matriz cuadrada" << endl;
        cout << "4. Verificar matriz magica" << endl;
        cout << "--> Ingrese una opcion:";
        cin >> bandera;
        switch (bandera) {
        case 0: return;
        case 1: leerMatriz(filas, columnas, matriz); break;
        case 2: imprimirMatriz(filas, columnas, matriz); break;
        case 3: verificarSiMatrizEsCuadrada(filas, columnas); break;
        case 4: verificarSiMatrizEsMagica(filas, columnas, matriz); break;
        }
    } while (bandera == 0);
}
void leerMatriz(int iMax, int jMax, int matriz[SIZE][SIZE]) {
    for (int i = 0; i < iMax; i++) {
        for (int j = 0; j < jMax; j++) {
            cout << "-> Matriz [" << i << "] [" << j << "] = ";
            cin >> matriz[i][j];
        }
    }
}
void imprimirMatriz(int iMax, int jMax, int matriz[SIZE][SIZE]) {
    for (int i = 0; i < iMax; i++) {
        for (int j = 0; j < jMax; j++) {
            cout << "-> Matriz [" << i << "] [" << j << "] = "<< matriz[i][j]<<"\t";
        }
        cout << endl;
    }
}
void verificarSiMatrizEsCuadrada(int iMax, int jMax) {
    const string falseCaseMessage = "-> Conclusion: La matriz ingresada NO es cuadrada", trueCaseMessage = "-> Conclusion: La matriz ingresada es cuadrada";
    if (verificarSiMatrizEsCuadradaEsp) cout << trueCaseMessage << endl;
    cout << falseCaseMessage << endl;
}
bool verificarSiMatrizEsCuadradaEsp(int iMax, int jMax) {
    return iMax == jMax;
}
void verificarSiMatrizEsMagica(int iMax, int jMax, int matrix[SIZE][SIZE]) {
    // Validacion de matriz cuadrada
    if (!verificarSiMatrizEsCuadradaEsp) return; 
    // suma de filas
    const string falseCaseMessage = "-> Conclusion: La matriz ingresada NO es magica", trueCaseMessage = "-> Conclusion: La matriz ingresada es magica";
    int sumAnteriorFilas = sumaDeFilasMatriz(jMax,matrix,0), sumAnteriorColumnas = sumaDeColumnas(iMax,matrix, 0);
    for (int i = 1; i < iMax; i++) {
        if (sumAnteriorFilas != sumaDeFilasMatriz(jMax, matrix, i)) {
            cout << falseCaseMessage << endl;
            return;
        }
    }
    // suma de columnas
    for (int j = 1; j < jMax; j++) {
        if (sumAnteriorColumnas != sumaDeColumnas(iMax, matrix, j)) {
            cout << falseCaseMessage << endl;
            return;
        }
    }
    // suma de diagonales
    if (sumaDiagonalDerecha(iMax,matrix) != sumaDiagonalIzquierda(iMax, matrix)) {
        cout << falseCaseMessage << endl;
        return;
    }
    // validacion
    cout << trueCaseMessage << endl;
}
int sumaDeFilasMatriz(int jMax, int matrix[SIZE][SIZE], int fila) {
    int suma = 0;
    for (int j = 0; j < jMax; j++) suma = matrix[fila][j] + suma;
    return suma;
    
}
int sumaDeColumnas(int iMax, int matrix[SIZE][SIZE], int columna) {
    int suma = 0;
    for (int i = 0; i < iMax; i++) suma = matrix[i][columna] + suma;
    return suma;
}
int sumaDiagonalDerecha(int sizeMax, int matrix[SIZE][SIZE]) {
    int suma = 0;
    for (int i = 0; i < sizeMax; i++) suma = suma + matrix[i][i];
    return suma;
}
int sumaDiagonalIzquierda(int sizeMax, int matrix[SIZE][SIZE]) {
    int suma = 0, int indexCol = sizeMax - 1;
    for (int i = 0; i < sizeMax; i++) {
        suma = suma + matrix[i][indexCol];
        indexCol--;
    }
    return suma;
}
// iMax = maximo de filas
// jMax = maximo de columnas

#include <iostream>
#include <math.h>
using namespace std;
void main(){
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

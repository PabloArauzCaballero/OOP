#include <iostream>
#include <math.h>
using namespace std;
void main(){
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

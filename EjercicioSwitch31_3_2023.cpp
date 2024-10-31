#include <iostream>
using namespace std;

void estructuraSecuencial() {
    float horasTrabajadas, precioPorHora, totalaPagar;
    cout << "Ingrese la cantidad de horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese el precio por hora: ";
    cin >> precioPorHora;
    totalaPagar = horasTrabajadas * precioPorHora;
    if (totalaPagar > 8272) { totalaPagar = totalaPagar * 0.87;}
    cout << "El salario neto (deducido de impuestos) es : " << totalaPagar << endl;
}
void estructuraCondicional(){
	int horaInicial, minutoInicial, segundoInicial, horaFinal, minutoFinal, segundoFinal, difHora, difMinuto, difSegundo;
	bool vhoraInicial, vminutoInicial, vsegundoInicial, vhoraFinal, vminutoFinal, vsegundoFinal, vdifHora, vdifMinuto, vdifSegundo;
	cout << "Ingrese la hora de la lectura inicial: ";
	cin >> horaInicial;
	cout << "Ingrese los minutos de la lectura inicial: ";
	cin >> minutoInicial;
	cout << "Ingrese los segundos de la lectura inicial: ";
	cin >> segundoInicial;
	cout << "Ingrese la hora de la lectura final: ";
	cin >> horaFinal;
	cout << "Ingrese los minutos de la lectura final: ";
	cin >> minutoFinal;
	cout << "Ingrese los segundos de la lectura final: ";
	cin >> segundoFinal;
	vhoraInicial = horaInicial > 24;
	vminutoInicial = minutoInicial > 60;
	vsegundoInicial = segundoInicial > 60;
	vhoraFinal = horaFinal > 24;
	vminutoFinal = minutoFinal > 60;
	vsegundoFinal = segundoFinal > 60;
	difHora = horaFinal - horaInicial;
	vdifHora = difHora < 0;
	difMinuto = minutoFinal - minutoInicial;
	vdifMinuto = difMinuto < 0;
	difSegundo = segundoFinal - segundoInicial;
	vdifSegundo = difSegundo < 0;
	if (vhoraInicial) cout << "Error en hora inicial" << endl;
	else if (vminutoInicial) cout << "Error en minuto inicial" << endl;
	else if (vsegundoInicial)cout << "Error en el segundo inicial" << endl;
	else if (vhoraFinal) cout << "Error en la hora final" << endl;
	else if (vminutoFinal) cout << "Error en el minuto final" << endl;
	else if (vsegundoFinal) cout << "Error en el segundo final" << endl;
	else if (vdifHora) cout << "Error: La hora inicial ingresada es posterior a la hora final." << endl;
	else {
		if (vdifSegundo) {
			difSegundo = 60 + difSegundo;
			difMinuto = difMinuto - 1;
		}
		if (vdifMinuto) {
			difMinuto = 60 + difMinuto;
			difHora = difHora - 1;
		}
		cout << "Hora Inicial: " << horaInicial << ":" << minutoInicial << ":" << segundoInicial << endl;
		cout << "Hora Final:   " << horaFinal << ":" << minutoFinal << ":" << segundoFinal << endl;
		cout << "Diferencia:   " << difHora << ":" << difMinuto << ":" << difSegundo << endl;
	}
}
void estructuraRepetitiva() {
    int acumulador = 1, numeroNDeseado;
    cout << "Ingrese el numero factorial: ";
    cin >> numeroNDeseado;
    for (int i = 1; i <= numeroNDeseado; i++) {
        acumulador = acumulador * i;
    }
    cout << "Numero Factorial = " << acumulador << endl;
}

int main(){
    int opcionIngresada;
	bool variableBandera = true;
	do {
		cout << "Menu de Opciones:" << endl;
		cout << "1.Opcion de estructura secuencial (calculo del salario neto despues de impuestos) " << endl;
		cout << "2.Opcion de estructura condicional (creacion hora): " << endl;
		cout << "3.Opcion de estructura repetitiva (calculo de numero factorial) " << endl;
		cout << "0. Salir del ejercicio." << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcionIngresada;
		switch (opcionIngresada) {
		case 1:
			estructuraSecuencial();
			break;
		case 2:
			estructuraCondicional();
			break;
		case 3:
			estructuraRepetitiva();
			break;
		case 0:
			variableBandera = false;
			break;
		default:
			cout << "Error" << endl;
		}
		system("pause");
		system("cls");
	} while (variableBandera);
}

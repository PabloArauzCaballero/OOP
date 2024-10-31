/*
* 10.	Construir un algoritmo que lea dos horas del mismo día y halle la diferencia entre ellas. 
		El ingreso de las horas debe ser en formato de 24 horas: HH, MM, SS, como así también la diferencia.
Ejemplo: 
Hora Inicial:	 10 Hr    50 Min  40 Seg
Hora Final:		 21 Hr    30 Min  10 Seg
Diferencia:		 10 Hr    39 Min  30 Seg
NOTA: Use los conceptos empleados en el ejemplo anterior

*/
#include <iostream>
using namespace std;

void main() {
	int horaInicial, minutoInicial, segundoInicial, horaFinal, minutoFinal, segundoFinal,difHora,difMinuto, difSegundo;
	bool vhoraInicial, vminutoInicial, vsegundoInicial, vhoraFinal, vminutoFinal, vsegundoFinal,vdifHora, vdifMinuto, vdifSegundo;
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
	else{
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
#include <iostream>
#include <string>
#include <sql.h>
#include <sqlext.h>
#define LISTA_PONDERACIONES {1,2,3,4,5,6,7,8,9,10}
using namespace std;
const string NOMBRE_TABLA_TRANSACCIONES = "TRANSACCIONES";
const string NOMBRE_TABLA_RESPUESTA = "RESPUESTAS";
const string NOMBRE_TABLA_PREGUNTAS = "PREGUNTAS";
const string NOMBRE_TABLA_OPCIONES = "OPCIONES";
const string NOMBRE_TABLA_USUARIOS = "USUARIOS";
const string NOMBRE_TABLA_PRESUPUESTOS = "PRESUPUESTOS";
const string NOMBRE_TABLA_TRANSACCION_FIJA = "TRANSACCION_FIJA";
const string NOMBRE_TABLA_TRANSACCION_VARIABLE = "TRANSACCION_VARIABLE";
const string NOMBRE_TABLA_TRANSACCION_PERIODICA = "TRANSACCION_PERIODICA";
const static int CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES = 10;
const static int CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS = 4;
const static int CANTIDAD_ARGUMENTOS_TABLA_PREGUNTAS = 5;
const static int CANTIDAD_ARGUMENTOS_TABLA_OPCIONES = 4;
const static int CANTIDAD_ARGUMENTOS_TABLA_USUARIOS = 13;
const static int CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS = 6;
const static int CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA = 2;
const static int CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE = 3;
const static int CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA = 3;

string NOMBRE_COLUMNAS_TRANSACCION[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES] = {
		"ID_Transaccion",
		"Fecha",
		"Tipo_Transaccion",
		"Categoria",
		"Sub_Categoria",
		"Glosa",
		"Temporalidad",
		"Moneda_Registro",
		"ID_Usuario",
		"Ponderacion" };
string NOMBRE_COLUMNAS_RESPUESTA[CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS] = {
	"ID_Respuesta",
	"ID_Opcion",
	"ID_Transaccion",
	"ID_Usuario" };
string NOMBRE_COLUMNAS_PREGUNTAS[CANTIDAD_ARGUMENTOS_TABLA_PREGUNTAS] = {
	"ID_Pregunta",
	"Nombre",
	"Aspecto",
	"Ponderacion",
	"Tipo" };
string NOMBRE_COLUMNAS_OPCIONES[CANTIDAD_ARGUMENTOS_TABLA_OPCIONES] = {
	"ID_Opcion",
	"ID_Pregunta",
	"Nombre",
	"Calificacion" };
string NOMBRE_COLUMNAS_USUARIO[CANTIDAD_ARGUMENTOS_TABLA_USUARIOS] = {
	"ID_Usuario",
	"Nombre",
	"Apellido_Paterno",
	"Apellido_Materno",
	"Contrasena",
	"Fecha_Registro",
	"Monto_Ahorrado",
	"Sexo",
	"Fecha_Nacimiento",
	"Telefono",
	"Codigo_Pais",
	"Pais",
	"Moneda_Patron"};
string NOMBRE_COLUMNAS_PRESUPUESTO[CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS] = {
	"ID_Presupuesto",
	"Categoria",
	"Sub_Categoria",
	"Tipo",
	"Monto_Lim",
	"ID_Usuario" };
string NOMBRE_COLUMNAS_TRANSACCION_FIJA[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA] = {
	"ID_Transaccion",
	"Monto" };
string NOMBRE_COLUMNAS_TRANSACCION_VARIABLE[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE] = {
	"ID_Transaccion",
	"Precio",
	"Cantidad" };
string NOMBRE_COLUMNAS_TRANSACCION_PERIODICA[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA] = {
	"ID_Transaccion",
	"Periodicidad",
	"V_Repeticion" };

template <typename T>
struct Nodo {
	T dato;
	Nodo* siguiente;
};
template <typename T>
class ListaEnlazada {
private:
	Nodo<T>* cabeza;
	int longitud;

public:
	ListaEnlazada() {
		cabeza = nullptr;
		longitud = 0;
	}
	~ListaEnlazada() {
		Nodo<T>* actual = cabeza;
		while (actual != nullptr) {
			Nodo<T>* siguiente = actual->siguiente;
			actual = siguiente;
		}
	}
	void agregar(T valor) {
		Nodo<T>* nuevoNodo = new Nodo<T>();
		nuevoNodo->dato = valor;
		nuevoNodo->siguiente = nullptr;
		if (cabeza == nullptr) { cabeza = nuevoNodo; }
		else {
			Nodo<T>* actual = cabeza;
			while (actual->siguiente != nullptr) { actual = actual->siguiente; }
			actual->siguiente = nuevoNodo;
		}
		longitud++;
	}
	void eliminar(int indice) {
		if (indice < 0 || indice >= longitud) {
			return;
		}
		Nodo<T>* actual = cabeza;
		Nodo<T>* anterior = nullptr;
		for (int i = 0; i < indice; i++) {
			anterior = actual;
			actual = actual->siguiente;
		}
		if (anterior == nullptr) { cabeza = actual->siguiente; }
		else { anterior->siguiente = actual->siguiente; }
		delete actual;
		longitud--;
	}
	void modificar(int indice, T valor) {
		if (indice < 0 || indice >= longitud) { return; }
		Nodo<T>* actual = cabeza;
		for (int i = 0; i < indice; i++) { actual = actual->siguiente; }
		actual->dato = valor;
	}
	T obtener(int indice) {
		if (indice < 0 || indice >= longitud) { return cabeza->dato; }
		Nodo<T>* actual = cabeza;
		for (int i = 0; i < indice; i++) { actual = actual->siguiente; }
		return actual->dato;
	}
	int longitudLista() { return longitud; }
};

class Fecha {
public: Fecha(int dia, int mes, int ano);
public: Fecha(string parametroFechaSQL);
private:
	int mes;
	int dia;
	int ano;
public:
	int getMes();
	int getDia();
	int getAno();
	string toString();
};
Fecha::Fecha(int dia, int mes, int ano) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}
Fecha::Fecha(string parametroFechaSQL) {
	char delimitador = '-';
	int fecha[3] = {}, contador = 0, indexParametro = 0;;
	for (int i = 0; i < parametroFechaSQL.length(); i++) {
		if (parametroFechaSQL.at(i) == delimitador) {
			fecha[contador] = stoi(parametroFechaSQL.substr(indexParametro, i));
			indexParametro = i + 1;
			contador++;
			if (contador == 2) fecha[contador] = stoi(parametroFechaSQL.substr(indexParametro));
		}
	}
	this->dia = fecha[0];
	this->mes = fecha[1];
	this->ano = fecha[2];
}
int Fecha::getMes() { return mes; }
int Fecha::getDia() { return dia; }
int Fecha::getAno() { return ano; }
string Fecha::toString() {
	string strMes = to_string(this->mes);
	string strDia = to_string(this->dia);
	if (mes < 10) strMes = "0" + strMes;
	if (dia < 10) strDia = "0" + strDia;
	cout << strMes << endl;
	cout << strDia << endl;
	return to_string(this->ano) + "-" + strMes + "-" + strDia;
}


class SubCategoria {
public: 
	SubCategoria(string nombre, float monto);
	SubCategoria();
private:
	string nombre;
	float monto;
public:
	string getNombre();
	float getMonto();
};

SubCategoria::SubCategoria(string nombre, float monto) {
	this->nombre = nombre;
	this->monto = monto;
}
SubCategoria::SubCategoria() {}
float SubCategoria::getMonto() {return this->monto;}
string SubCategoria::getNombre() { return this->nombre; }

class Categoria {
public: Categoria(string nombre, float monto);
private:
	string nombre;
	float monto;
public:
	string getNombre();
	float getMonto();
};
Categoria::Categoria(string nombre, float monto) {
	this->nombre = nombre;
	this->monto = monto;
}
float Categoria::getMonto() { return this->monto; }
string Categoria::getNombre() { return this->nombre; }

class PonderacionMonto {
public: PonderacionMonto(ListaEnlazada<float> tr, int ponderacion);
private:
	int ponderacion;
	float monto;
public:
	float getMonto();
	int getPonderacion();
	void actualizarMonto(ListaEnlazada<float> tr);
private: static float totalizarMonto(ListaEnlazada<float> tr) {
	float acumulador = 0;
	for (int i = 0; i < tr.longitudLista(); i++) {
		acumulador = acumulador + tr.obtener(i);
	}
	return acumulador;
}
};
PonderacionMonto::PonderacionMonto(ListaEnlazada<float> tr, int ponderacion) {
	this->ponderacion = ponderacion;
	this->monto = totalizarMonto(tr);
	cout << "Monto : " << this->monto << endl;
}
float PonderacionMonto::getMonto() { return this->monto; }
int PonderacionMonto::getPonderacion() { return this->ponderacion; }
void PonderacionMonto::actualizarMonto(ListaEnlazada<float> tr) {
	this->monto = totalizarMonto(tr);
}

class Moneda {
public:Moneda(string nombre, string contraccion, float lastValueInDollar);
public:Moneda(string moneda_ID_DB);
private:
	string nombre;
	string contraccion;
	float lastValueInDollar;
public: string toString();
};
Moneda::Moneda(string nombre, string contraccion, float lastValueInDollar) {
	this->nombre = nombre;
	this->contraccion = contraccion;
	this->lastValueInDollar = lastValueInDollar;
}
string Moneda::toString() { return this->contraccion; }
Moneda::Moneda(string moneda) {
	
}

class Pregunta {
public:Pregunta(string ID_Pregunta, string nombre, string aspecto, int poderacion, string tipo);
private:
	string ID_Pregunta;
	string nombre;
	string aspecto;
	int ponderacion;
	string tipo;
public:
	string getID_Pregunta();
	string getNombre();
	string getAspecto();
	int	getPonderacion();
	string getTipo();
};
Pregunta::Pregunta(string ID_Pregunta, string nombre, string aspecto, int poderacion, string tipo) {
	this->ID_Pregunta = ID_Pregunta;
	this->nombre = nombre;
	this->aspecto = aspecto;
	this->ponderacion = ponderacion;
	this->tipo = tipo;
}
string Pregunta::getID_Pregunta() { return this->ID_Pregunta; }
string Pregunta::getNombre() { return this->nombre; }
string Pregunta::getAspecto() { return this->aspecto; }
int Pregunta::getPonderacion() { return this->ponderacion; }
string Pregunta::getTipo() { return this->tipo; }

class Opcion {
public:Opcion(string ID_Opcion, string nombre, int calificacion, Pregunta pregunta);
private:
	string ID_Opcion;
	string nombre;
	int	calificacion;
	Pregunta pregunta;
public:
	string getID_Opcion();
	string getNombre();
	int	getCalificacion();
	Pregunta getPregunta();
};
Opcion::Opcion(string ID_Opcion, string nombre, int calificacion, Pregunta _pregunta) : pregunta(_pregunta) {
	this->ID_Opcion = ID_Opcion;
	this->nombre = nombre;
	this->calificacion = calificacion;
	this->pregunta = _pregunta;
}
string Opcion::getID_Opcion() { return this->ID_Opcion; }
string Opcion::getNombre() { return this->nombre; }
int Opcion::getCalificacion() { return this->calificacion; }
Pregunta Opcion::getPregunta() { return this->pregunta; }

class Usuario {
public:Usuario(
	string IDUsuario,
	string nombre,
	string apellidoPaterno,
	string apellidoMaterno,
	string contrasena,
	Fecha fechaRegistro,
	float montoAhorrado,
	string sexo,
	Fecha fechaNacimiento,
	string telefono,
	string codigoPais,
	string pais,
	Moneda monedaPatron);
private:
	string IDUsuario;
	string nombre;
	string apellido_Paterno;
	string apellido_Materno;
	string contrasena;
	Fecha fechaRegistro;
	float montoAhorrado;
	string sexo;
	Fecha fechaNacimiento;
	string telefono;
	string codigoPais;
	string pais;
	Moneda monedaPatron;
public:
	string getIDUsaurio();
	string getNombre();
	string getApellido_Paterno();
	string getApellido_Materno();
	string getContrasena();
	Fecha getFechaRegistro();
	float getMontoAhorrado();
	string getSexo();
	Fecha getFechaNacimiento();
	string getTelefono();
	string getCodigoPais();
	string getPais();
	Moneda getMonedaPatron();
};
Usuario::Usuario(
	string IDUsuario,
	string nombre,
	string apellidoPaterno,
	string apellidoMaterno,
	string contrasena,
	Fecha fechaRegistro,
	float montoAhorrado,
	string sexo,
	Fecha fechaNacimiento,
	string telefono,
	string codigoPais,
	string pais,
	Moneda monedaPatron) : monedaPatron(monedaPatron),
	fechaNacimiento(fechaNacimiento),
	fechaRegistro(fechaRegistro) {
	this->IDUsuario = IDUsuario;
	this->nombre = nombre;
	this->apellido_Paterno = apellidoPaterno;
	this->apellido_Materno = apellidoMaterno;
	this->contrasena = contrasena;
	this->fechaRegistro = fechaRegistro;
	this->montoAhorrado = montoAhorrado;
	this->sexo = sexo;
	this->fechaNacimiento = fechaNacimiento;
	this->telefono = telefono;
	this->codigoPais = codigoPais;
	this->pais = pais;
	this->monedaPatron = monedaPatron;
}
string Usuario::getIDUsaurio() { return this->IDUsuario; }
string Usuario::getNombre() { return this->nombre; }
string Usuario::getApellido_Paterno() { return this->apellido_Paterno; }
string Usuario::getApellido_Materno() { return this->apellido_Materno; }
string Usuario::getContrasena() { return contrasena; }
Fecha Usuario::getFechaRegistro() { return this->fechaRegistro; }
float Usuario::getMontoAhorrado() { return this->montoAhorrado; }
string Usuario::getSexo() { return this->sexo; }
Fecha Usuario::getFechaNacimiento() { return this->fechaNacimiento; }
string Usuario::getTelefono() { return this->telefono; }
string Usuario::getCodigoPais() { return this->codigoPais; }
string Usuario::getPais() { return this->pais; }
Moneda Usuario::getMonedaPatron() { return this->monedaPatron; }

class Transaccion {
public:
	Transaccion(
		string IDTransaccion,
		string tipoTransaccion,
		string categoria,
		string subCategoria,
		string glosa,
		string temporalidad,
		string tipoRepeticion,
		Moneda monedaRegistro,
		Usuario usuario,
		Fecha fecha,
		int ponderacion);
	Transaccion(
		string parametros[],
		Usuario usuario,
		Moneda moneda,
		Fecha fecha);
private:
	string IDTransaccion;
	string tipoTransaccion;
	string categoria;
	string subCategoria;
	string glosa;
	string temporalidad;
	string tipoRepeticion;
	Usuario usuario;
	Moneda monedaRegistro;
	int ponderacion;
	bool compararValidacion(float importancia1, float gasto1, float importncia2,
		float gasto2);
	// En el caso de gasto hara referencia al valor que se le asgina al gasto
	// En el caso del ingreso hace referencia al valor que se el asigna al ingreso
	Fecha fecha;
public:
	string getIDTransaccion();
	string getTipoTransaccion();
	string getCategoria();
	string getSubCategoria();
	string getGlosa();
	string getTemporalidad();
	string getTipoRepeticion();
	Moneda getMonedaRegistro();
	Usuario getUsuario();
	Fecha getFechaRegistro();
	int getPonderacio();
	void setCategoria(string categoria);
	void setGlosa(string glosa);
	void setTipoGasto(string tipoGasto);
	bool compararTransacciones(Transaccion transaccion1, Transaccion transaccion2);
};
Transaccion::Transaccion(
	string IDTransaccion,
	string tipoTransaccion,
	string categoria,
	string subCategoria,
	string glosa,
	string temporalidad,
	string tipoRepeticion,
	Moneda monedaRegistro, Usuario usuario, Fecha fecha, int ponderacion) :
	usuario(usuario),
	monedaRegistro(monedaRegistro),
	fecha(fecha) {
	this->IDTransaccion = IDTransaccion;
	this->tipoTransaccion = tipoTransaccion;
	this->categoria = categoria;
	this->subCategoria = subCategoria;
	this->glosa = glosa;
	this->temporalidad = temporalidad;
	this->tipoRepeticion = tipoRepeticion;  // GOOGLE COLABORATY
	this->monedaRegistro = monedaRegistro;
	this->usuario = usuario;
	this->fecha = fecha;
	this->ponderacion = ponderacion;
}
Transaccion::Transaccion(
	string parametros[],
	Usuario usuario,
	Moneda moneda,
	Fecha fecha) :
	usuario(usuario),
	monedaRegistro(moneda),
	fecha(fecha) {
	this->IDTransaccion = parametros[0];
	this->tipoTransaccion = parametros[2];
	this->categoria = parametros[3];
	this->subCategoria = parametros[4];
	this->glosa = parametros[5];
	this->temporalidad = parametros[6];
	this->tipoRepeticion = parametros[9];
	this->monedaRegistro = moneda;
	this->usuario = usuario;
	this->fecha = fecha;
}
string Transaccion::getIDTransaccion() { return this->IDTransaccion; }
string Transaccion::getTipoTransaccion() { return this->tipoTransaccion; }
string Transaccion::getCategoria() { return this->categoria; }
string Transaccion::getSubCategoria() { return this->subCategoria; }
string Transaccion::getGlosa() { return this->glosa; }
string Transaccion::getTemporalidad() { return this->temporalidad; }
string Transaccion::getTipoRepeticion() { return this->tipoRepeticion; }
Moneda Transaccion::getMonedaRegistro() { return this->monedaRegistro; }
Usuario Transaccion::getUsuario() { return this->usuario; }
Fecha Transaccion::getFechaRegistro() { return this->fecha; }
int Transaccion::getPonderacio() { return this->ponderacion; }
void Transaccion::setCategoria(string categoria) { this->categoria = categoria; }
void Transaccion::setGlosa(string glosa) { this->glosa = glosa; }
bool Transaccion::compararValidacion(float importancia1, float monto1,
	float importncia2, float monto2) {
	// Es economicamente correcto
	if (importancia1 > importncia2) return monto1 >= monto2;
	if (importncia2 > importancia1) return monto2 >= monto1;
	return NULL;
}
bool Transaccion::compararTransacciones(Transaccion transaccion1, Transaccion transaccion2) {
	if (transaccion1.getTipoTransaccion() == transaccion2.getTipoTransaccion()) {
		if (transaccion1.getTipoTransaccion() == "Fijo") {

		}
		if (transaccion1.getTipoTransaccion() == "Variable") {

		}
		if (transaccion1.getTipoTransaccion() == "Periodico") {

		}
	}
	else return NULL;
}

class Presupuesto {
public:Presupuesto(string IDPresupuesto, string categoria, string subCategoria, string tipo, 
	float montoLim, Usuario usuario);
protected:
	string IDPresupuesto;
	string categoria;
	string subCategoria;
	string tipo;
	float montoLim;
	Usuario usuario;
public:
	string getIDPresupuesto();
	string getCategoria();
	string getSubCategoria();
	string getTipo();
	float getMontoLim();
	Usuario getUsuario();
	void setCategoria(string categoria);
	void setSubCategoria(string subCategoria);
	void setTipo(string tipo);
	void setMontoLim(float montoLim);
};
Presupuesto::Presupuesto(
	string IDPresupuesto,
	string categoria,
	string subCategoria,
	string tipo,
	float montoLim,
	Usuario usuario) : usuario(usuario) {
	this->IDPresupuesto = IDPresupuesto;
	this->categoria = categoria;
	this->subCategoria = subCategoria;
	this->tipo = tipo;
	this->montoLim = montoLim;
	this->usuario = usuario;
}
string Presupuesto::getIDPresupuesto() { return this->IDPresupuesto; }
string Presupuesto::getCategoria() { return this->categoria; }
string Presupuesto::getSubCategoria() { return this->subCategoria; }
string Presupuesto::getTipo() { return this->tipo; }
float Presupuesto::getMontoLim() { return this->montoLim; }
Usuario Presupuesto::getUsuario() { return this->usuario; }
void Presupuesto::setCategoria(string categoria) { this->categoria = categoria; }
void Presupuesto::setSubCategoria(string subCategoria) { this->subCategoria = subCategoria; }
void Presupuesto::setTipo(string tipo) { this->tipo = tipo; }
void Presupuesto::setMontoLim(float montoLim) { this->montoLim = montoLim; }
// Creando clases heredadas
class TransaccionPeriodica : public Transaccion {
public: TransaccionPeriodica(
	string periodicidad, 
	bool vConsulta, 
	string IDTransaccion,
	string tipoTransaccion, 
	string categoria, 
	string subCategoria, 
	string glosa,
	string temporalidad, 
	string tipoRepeticion, 
	Moneda monedaRegistro, 
	Usuario usuario,
	Fecha fecha, 
	int ponderacion);
private:
	string periodicidad;
	bool vConsulta; // Consulta si desea ser notificado cuando 
public:
	string getPeriodicidad();
	bool getVConsulta();
};
TransaccionPeriodica::TransaccionPeriodica(
	string periodicidad, 
	bool vConsulta, 
	string IDTransaccion,
	string tipoTransaccion, 
	string categoria, 
	string subCategoria, 
	string glosa, 
	string temporalidad,
	string tipoRepeticion, 
	Moneda monedaRegistro, 
	Usuario usuario, 
	Fecha fecha,
	int ponderacion) : Transaccion(
		IDTransaccion,
		tipoTransaccion,
		categoria,
		subCategoria,
		glosa, 
		temporalidad,
		tipoRepeticion,
		monedaRegistro,
		usuario,
		fecha,
		ponderacion) {
	this->periodicidad = periodicidad;
	this->vConsulta = vConsulta;
}
string TransaccionPeriodica::getPeriodicidad() { return periodicidad; }
bool TransaccionPeriodica::getVConsulta() { return vConsulta; }

class TransaccionTemporalidadFija : public Transaccion {
public: TransaccionTemporalidadFija(
	float monto, 
	string IDTransaccion, 
	string tipoTransaccion,
	string categoria, 
	string subCategoria, 
	string glosa, 
	string temporalidad,
	string tipoRepeticion, 
	Moneda monedaRegistro,
	Usuario usuario, 
	Fecha fecha,
	int ponderacion);
private:
	float monto;
public:
	float getMonto();
};
TransaccionTemporalidadFija::TransaccionTemporalidadFija(
	float monto, 
	string IDTransaccion,
	string tipoTransaccion, 
	string categoria, 
	string subCategoria, 
	string glosa,
	string temporalidad, 
	string tipoRepeticion, 
	Moneda monedaRegistro,
	Usuario usuario, 
	Fecha fecha, int ponderacion) :Transaccion(
		IDTransaccion, 
		tipoTransaccion, 
		categoria,
		subCategoria, 
		glosa, 
		temporalidad, 
		tipoRepeticion, 
		monedaRegistro, 
		usuario, 
		fecha,
		ponderacion) {
	this->monto = monto;
}
float TransaccionTemporalidadFija::getMonto() { return monto; }

class TransaccionTemporalidadVariable : public Transaccion {
public: TransaccionTemporalidadVariable(
	float precio, 
	float cantidad, 
	string IDTransaccion,
	string tipoTransaccion, 
	string categoria, 
	string subCategoria, 
	string glosa,
	string temporalidad, 
	string tipoRepeticion, 
	Moneda monedaRegistro, 
	Usuario usuario,
	Fecha fecha,
	int ponderacion);
private:
	float precio;
	float cantidad;
public:
	float getPrecio();
	float getCantidad();
};
TransaccionTemporalidadVariable::TransaccionTemporalidadVariable(
	float precio, 
	float cantidad, 
	string IDTransaccion,
	string tipoTransaccion, 
	string categoria, 
	string subCategoria, 
	string glosa, string temporalidad,
	string tipoRepeticion, 
	Moneda monedaRegistro,
	Usuario usuario, 
	Fecha fecha,
	int ponderacion) : Transaccion(
		IDTransaccion, 
		tipoTransaccion, 
		categoria, 
		subCategoria, 
		glosa, 
		temporalidad,
		tipoRepeticion, 
		monedaRegistro, 
		usuario, 
		fecha,
		ponderacion) {
	this->precio = precio;
	this->cantidad = cantidad;
}
float TransaccionTemporalidadVariable::getPrecio() { return precio; }
float TransaccionTemporalidadVariable::getCantidad() { return cantidad; }

class Respuesta {
public:Respuesta(
	string ID_Respuesta, 
	Opcion _opcionSeleccionada, 
	Usuario _usuario,
	Transaccion _transaccionConsultada);
private:
	string ID_Respuesta;
	Opcion opcionSeleccionada;
	Usuario usuario;
	Transaccion transaccionConsultada;
public:
	Opcion getOpcionSeleccionada();
	Usuario getUsuario();
	Transaccion getTransaccionConsultada();
	string getIDRespuesta();
};
Respuesta::Respuesta(
	string ID_Respuesta, 
	Opcion _opcionSeleccionada, 
	Usuario _usuario,
	Transaccion _transaccionConsultada) :
	opcionSeleccionada(_opcionSeleccionada), usuario(_usuario),
	transaccionConsultada(_transaccionConsultada) {
	this->ID_Respuesta = ID_Respuesta;
	this->opcionSeleccionada = _opcionSeleccionada;
	this->usuario = usuario;
	this->transaccionConsultada = transaccionConsultada;
}
string Respuesta::getIDRespuesta() { return this->ID_Respuesta;}
Opcion Respuesta::getOpcionSeleccionada() { return this->opcionSeleccionada; }
Usuario Respuesta::getUsuario() { return this->usuario; }
Transaccion Respuesta::getTransaccionConsultada() { return this->transaccionConsultada; }

class ConexionDB {
public:
	virtual void conectar() = 0;
	virtual void desconectar() = 0;
	virtual void ejecutarRegistroEnDB(string SQLStatement) = 0;
	virtual string ejecutarConsultaEnDB(string SQLStatement) = 0;
	virtual	void registrarTransaccion(Transaccion transaccion) = 0;
	virtual void registrarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) = 0;
	virtual void registrarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) = 0;
	virtual void registrarTransaccionPeriodica(TransaccionPeriodica transaccionP) = 0;
	virtual void registrarUsuario(Usuario usuario) = 0;
	virtual void registrarRespuesta(Respuesta respuesta) = 0;
	virtual void registrarPresupuesto(Presupuesto presupuesto) = 0;
	virtual	void modificarTransaccion(Transaccion transaccion) = 0;
	virtual void modificarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) = 0;
	virtual void modificarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) = 0;
	virtual void modificarTransaccionPeriodica(TransaccionPeriodica transaccionP) = 0;
	virtual void modificarUsuario(Usuario usuario) = 0;
	virtual void modificarRespuesta(Respuesta respuesta) = 0;
	virtual void modificarPresupuesto(Presupuesto prespuesto) = 0;
	virtual	void eliminarTransaccion(Transaccion transaccion) = 0;
	virtual void eliminarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) = 0;
	virtual void eliminarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) = 0;
	virtual void eliminarTransaccionPeriodica(TransaccionPeriodica transaccionP) = 0;
	virtual void eliminarUsuario(Usuario usuario) = 0;
	virtual void eliminarRespuesta(Respuesta respuesta) = 0;
	virtual void eliminarPresupuesto(Presupuesto presupuesto) = 0;
	virtual	Transaccion buscarTransaccion(string ID_Transaccion, Usuario usuario) = 0;
	virtual TransaccionTemporalidadFija buscarTransaccionFija(string ID_Transaccion, Usuario usuario) = 0;
	virtual TransaccionTemporalidadVariable buscarTransaccionVariable(string ID_Transaccion, Usuario usuario) = 0;
	virtual TransaccionPeriodica buscarTransaccionPeriodica(string ID_Transaccion, Usuario usuario) = 0;
	virtual Usuario buscarUsuario(string ID_Usuario) = 0;
	virtual Respuesta buscarRespuesta(string ID_Respuesta, Usuario usuario) = 0;
	virtual Opcion buscarOpcion(string ID_Opcion) = 0;
	virtual Pregunta buscarPregunta(string ID_Pregunta) = 0;
	virtual Moneda buscarMoneda(string ID_Moneda) = 0;
};

class ConexionDBSQLServer : public ConexionDB {
public:
	static string generarSeparadoresCasoInsert(int large);
	static string generarSeparadoresCasoUpdate(int large);
	static string generarConsultaCaseInsert(string elementos[], string baseStatement);
	static string generarConsultaCaseUpdate(string elementos[], string columnName[],
		string baseStatement);
	static string generarConsultaCaseDelete(string elementID, string columnElementID,
		string baseStatement);
	static string generarConsultaCaseSelect(string elementID, string columnElementID,
		string baseStatement, string nameColumn);
	static string generarConsulta(int large, string tableName, string elementos[]); // INSERT INTO 
	static string generarConsulta(int large, string tableName, string elementos[], string columnName[]); // UPDATE  WHERE
	static string generarConsulta(string elementID, string columnElementID, string tableName); // DELETE WHERE
	static string generarConsulta(string tableName, string elementID, string columnName,
		string columnElementID); // SELECT FROM 
public:
	ListaEnlazada<Categoria> totalizarMontoTotalConRespectoAspecto(string Aspecto) {

	};
	void conectar() override {
		SQLHENV env; // Handle del entorno
		SQLHDBC dbc; // Handle de la conexi�n
		SQLRETURN ret;

		// Inicializar el entorno
		ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
		ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

		// Establecer la conexi�n
		ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
		ret = SQLDriverConnect(dbc, NULL, (SQLCHAR*) "DRIVER={SQL Server};SERVER=NombreDelServidor;DATABASE=NombreDeLaBaseDeDatos;UID=Usuario;PWD=Contrase�a;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

		// Verificar el estado de la conexi�n
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
			cout << "Conexi�n exitosa a SQL Server" << std::endl;

			// Realizar operaciones en la base de datos...

			// Cerrar la conexi�n
			SQLDisconnect(dbc);
		}
		else {
			cout << "Error al conectar a SQL Server" << std::endl;
		}

	}
	void desconectar() override {
		SQLHENV env; // Handle del entorno
		SQLHDBC dbc; // Handle de la conexi�n


		// Liberar los handles y liberar el entorno

		SQLFreeHandle(SQL_HANDLE_DBC, dbc);
		SQLFreeHandle(SQL_HANDLE_ENV, env);
	}
	void ejecutarRegistroEnDB(string SQLStatement) override {
		SQLHENV env; // Handle del entorno
		SQLHDBC dbc; // Handle de la conexi�n
		SQLHSTMT stmt; // Handle de la declaraci�n
		SQLRETURN ret;

		// Inicializar el entorno
		ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
		ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

		// Establecer la conexi�n
		ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
		ret = SQLDriverConnect(dbc, NULL, (SQLCHAR*)"DRIVER={SQL Server};SERVER=NombreDelServidor;DATABASE=NombreDeLaBaseDeDatos;UID=Usuario;PWD=Contrase�a;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

		// Verificar el estado de la conexi�n
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
			cout << "Conexi�n exitosa a SQL Server" << std::endl;

			// Preparar la declaraci�n
			ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
			ret = SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS);

			// Verificar el estado de la ejecuci�n de la consulta
			if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
				cout << "Consulta ejecutada correctamente" << std::endl;

				// Procesar los resultados de la consulta...

			}
			else {
				cout << "Error al ejecutar la consulta" << std::endl;
			}
		}
		else {
			cout << "Error al conectar a SQL Server" << std::endl;
		}
	}
	string ejecutarConsultaEnDB(string SQLStatement) override {
		return "d";
	}
	void registrarTransaccion(Transaccion transaccion) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES,
			NOMBRE_TABLA_TRANSACCIONES,
			generarListaDeElementosTransacciones(transaccion)));
	}//CV
	void registrarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA,
			NOMBRE_TABLA_TRANSACCION_FIJA, generarListaDeElementosTransaccionesFijas(transaccionFJ)));
	}
	void registrarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE,
			NOMBRE_TABLA_TRANSACCION_VARIABLE, generarListaDeTransaccionesVaribles(transaccionV)));
	}
	void registrarTransaccionPeriodica(TransaccionPeriodica transaccionP) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA,
			NOMBRE_TABLA_TRANSACCION_PERIODICA,
			generarListaDeTransaccionesPeriodicas(transaccionP)));
	}
	void registrarUsuario(Usuario usuario) override {
		ejecutarRegistroEnDB(generarConsulta(CANTIDAD_ARGUMENTOS_TABLA_USUARIOS,
			NOMBRE_TABLA_USUARIOS, generarListaDeElementosUsuarios(usuario)));
	}
	void registrarRespuesta(Respuesta respuesta) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS,
			NOMBRE_TABLA_RESPUESTA, generarListaDeRespuestas(respuesta)));
	}
	void registrarPresupuesto(Presupuesto presupuesto) override {
	ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS,
			NOMBRE_TABLA_PRESUPUESTOS, generarListaDePresupuestos(presupuesto)));
	}
	void modificarTransaccion(Transaccion transaccion) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES,
			NOMBRE_TABLA_TRANSACCIONES, generarListaDeElementosTransacciones(transaccion),
			NOMBRE_COLUMNAS_TRANSACCION));
	}
	void modificarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA,
			NOMBRE_TABLA_TRANSACCION_FIJA, generarListaDeElementosTransaccionesFijas(transaccionFJ),
			NOMBRE_COLUMNAS_TRANSACCION_FIJA));
	}
	void modificarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE,
			NOMBRE_TABLA_TRANSACCION_VARIABLE, generarListaDeTransaccionesVaribles(transaccionV),
			NOMBRE_COLUMNAS_TRANSACCION_VARIABLE));
	}
	void modificarTransaccionPeriodica(TransaccionPeriodica transaccionP) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA,
			NOMBRE_TABLA_TRANSACCION_PERIODICA, generarListaDeTransaccionesPeriodicas(transaccionP),
			NOMBRE_COLUMNAS_TRANSACCION_PERIODICA));
	}
	void modificarUsuario(Usuario usuario) override {
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_USUARIOS,
			NOMBRE_TABLA_USUARIOS, generarListaDeElementosUsuarios(usuario),
			NOMBRE_COLUMNAS_USUARIO));
	}
	void modificarRespuesta(Respuesta respuesta) override {
		string entrada[CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS] = {
			respuesta.getUsuario().getIDUsaurio(),
			respuesta.getTransaccionConsultada().getIDTransaccion(),
			respuesta.getOpcionSeleccionada().getID_Opcion() };
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS,
			NOMBRE_TABLA_RESPUESTA, entrada,
			NOMBRE_COLUMNAS_RESPUESTA));
	}
	void modificarPresupuesto(Presupuesto presupuesto) override {
		string entrada[CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS] = {
		presupuesto.getIDPresupuesto(),presupuesto.getCategoria(),
		presupuesto.getSubCategoria(),to_string(presupuesto.getMontoLim()),presupuesto.getTipo() };
		ejecutarRegistroEnDB(generarConsulta(
			CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS,
			NOMBRE_TABLA_PRESUPUESTOS, entrada,
			NOMBRE_COLUMNAS_PRESUPUESTO));
	}

	void eliminarTransaccion(Transaccion transaccion) override {
		ejecutarRegistroEnDB(generarConsulta(
			transaccion.getIDTransaccion(),
			NOMBRE_COLUMNAS_TRANSACCION[0],
			NOMBRE_TABLA_TRANSACCIONES));
	}
	void eliminarTransaccionFija(TransaccionTemporalidadFija transaccionFJ) override {
		ejecutarRegistroEnDB(generarConsulta(
			transaccionFJ.getIDTransaccion(),
			NOMBRE_COLUMNAS_TRANSACCION_FIJA[0],
			NOMBRE_TABLA_TRANSACCION_FIJA));
	}
	void eliminarTransaccionVariable(TransaccionTemporalidadVariable transaccionV) override {
		ejecutarRegistroEnDB(generarConsulta(
			transaccionV.getIDTransaccion(),
			NOMBRE_COLUMNAS_TRANSACCION_VARIABLE[0],
			NOMBRE_TABLA_TRANSACCION_VARIABLE));
	}
	void eliminarTransaccionPeriodica(TransaccionPeriodica transaccionP) override {
		ejecutarRegistroEnDB(generarConsulta(
			transaccionP.getIDTransaccion(),
			NOMBRE_COLUMNAS_TRANSACCION_PERIODICA[0],
			NOMBRE_TABLA_TRANSACCION_PERIODICA));
	}
	void eliminarUsuario(Usuario usuario) override {
		ejecutarRegistroEnDB(generarConsulta(usuario.getIDUsaurio(),
			NOMBRE_COLUMNAS_USUARIO[0],
			NOMBRE_TABLA_USUARIOS));
	}
	void eliminarRespuesta(Respuesta respuesta) override {
		ejecutarRegistroEnDB(generarConsulta(respuesta.getUsuario().getIDUsaurio(),
			NOMBRE_COLUMNAS_RESPUESTA[0],
			NOMBRE_TABLA_RESPUESTA));
	}
	void eliminarPresupuesto(Presupuesto presupuesto) override {
		ejecutarRegistroEnDB(generarConsulta(
			presupuesto.getIDPresupuesto(),
			NOMBRE_COLUMNAS_PRESUPUESTO[0],
			NOMBRE_TABLA_PRESUPUESTOS));
	}

	Transaccion buscarTransaccion(string ID_Transaccion, Usuario usuario) {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_TRANSACCIONES, ID_Transaccion,
				NOMBRE_COLUMNAS_TRANSACCION[i],
				NOMBRE_COLUMNAS_TRANSACCION[0]));
		}
		return Transaccion(
			valores, usuario,
			buscarMoneda(valores[7]),
			Fecha(valores[1]));
	}
	TransaccionTemporalidadFija buscarTransaccionFija(string ID_Transaccion,
		Usuario usuario) {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_TRANSACCION_FIJA, ID_Transaccion,
				NOMBRE_COLUMNAS_TRANSACCION_FIJA[i],
				NOMBRE_COLUMNAS_TRANSACCION_FIJA[0]));
		}
		Transaccion transaccion = buscarTransaccion(valores[0], usuario);
		return TransaccionTemporalidadFija(
			stof(valores[1]),
			valores[0],
			transaccion.getTipoTransaccion(),
			transaccion.getCategoria(),
			transaccion.getSubCategoria(),
			transaccion.getGlosa(),
			transaccion.getTemporalidad(),
			transaccion.getTipoRepeticion(),
			transaccion.getMonedaRegistro(),
			usuario,
			transaccion.getFechaRegistro(),
			transaccion.getPonderacio());
	}
	TransaccionTemporalidadVariable buscarTransaccionVariable(string ID_Transaccion,
		Usuario usuario) {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_TRANSACCION_VARIABLE, ID_Transaccion,
				NOMBRE_COLUMNAS_TRANSACCION_VARIABLE[i],
				NOMBRE_COLUMNAS_TRANSACCION_VARIABLE[0]));
		}
		Transaccion transaccion = buscarTransaccion(valores[0], usuario);
		return TransaccionTemporalidadVariable(
			stof(valores[1]),
			stof(valores[2]),
			valores[0],
			transaccion.getTipoTransaccion(),
			transaccion.getCategoria(),
			transaccion.getSubCategoria(),
			transaccion.getGlosa(),
			transaccion.getTemporalidad(),
			transaccion.getTipoRepeticion(),
			transaccion.getMonedaRegistro(),
			usuario,
			transaccion.getFechaRegistro(),
			transaccion.getPonderacio());
	}
	TransaccionPeriodica buscarTransaccionPeriodica(string ID_Transaccion, 
			Usuario usuario) override {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_TRANSACCION_PERIODICA, ID_Transaccion,
				NOMBRE_COLUMNAS_TRANSACCION_FIJA[i],
				NOMBRE_COLUMNAS_TRANSACCION_FIJA[0]));
		}
		Transaccion transaccion = buscarTransaccion(valores[0], usuario);
		return TransaccionPeriodica(
			valores[1],
			valores[2]=="1",
			valores[0],
			transaccion.getTipoTransaccion(),
			transaccion.getCategoria(),
			transaccion.getSubCategoria(),
			transaccion.getGlosa(),
			transaccion.getTemporalidad(),
			transaccion.getTipoRepeticion(),
			transaccion.getMonedaRegistro(),
			usuario,
			transaccion.getFechaRegistro(),
			transaccion.getPonderacio());
	}
	Usuario buscarUsuario(string ID_Usuario) override {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_USUARIOS] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_USUARIOS, ID_Usuario,
				NOMBRE_COLUMNAS_USUARIO[i],
				NOMBRE_COLUMNAS_USUARIO[0]));
		}
		return Usuario(
			valores[0], // IDUsuario
			valores[1], // nombre
			valores[2], // apellidoPaterno
			valores[3], // apellidoMaterno
			valores[4], // contrasena
			Fecha(valores[5]), // fechaRegistro
			stof(valores[6]), // montoAhorrado
			valores[7], // sexo
			Fecha(valores[8]), // fechaNacimiento
			valores[9], // telefono
			valores[10], // codigo pais
			valores[11], // pais
			buscarMoneda(valores[12]) // monedaPatron
		);
	}
	Respuesta buscarRespuesta(string ID_Respuesta, Usuario usuario) override {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_RESPUESTA, ID_Respuesta,
				NOMBRE_COLUMNAS_RESPUESTA[i],
				NOMBRE_COLUMNAS_RESPUESTA[0]));
		}
		return Respuesta(
			valores[0],
			buscarOpcion(valores[1]),
			usuario,
			buscarTransaccion(valores[3], usuario));
	}
	Opcion buscarOpcion(string ID_Opcion) override {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_OPCIONES] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_OPCIONES; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_OPCIONES, ID_Opcion,
				NOMBRE_COLUMNAS_OPCIONES[i],
				NOMBRE_COLUMNAS_OPCIONES[0]));
		}
		return Opcion(valores[0],
			valores[1],
			stoi(valores[2]),
			buscarPregunta(valores[3]));
	}
	Pregunta buscarPregunta(string ID_Pregunta) override {
		string valores[CANTIDAD_ARGUMENTOS_TABLA_PREGUNTAS] = {};
		for (int i = 0; i < CANTIDAD_ARGUMENTOS_TABLA_PREGUNTAS; i++) {
			valores[i] = ejecutarConsultaEnDB(generarConsulta(
				NOMBRE_TABLA_PREGUNTAS, ID_Pregunta,
				NOMBRE_COLUMNAS_PREGUNTAS[i],
				NOMBRE_COLUMNAS_PREGUNTAS[0]));
		}
		return Pregunta(valores[0], valores[1], valores[2], stoi(valores[3]),valores[4]);
	}
	Moneda buscarMoneda(string ID_Moneda) override {
		return Moneda("Bolivia","BOB",100);
	}
	static string* generarListaDeElementosUsuarios(Usuario usuario) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_USUARIOS];
		const string spc = "'";
		salida[0] = spc + usuario.getIDUsaurio() + spc;
		salida[1] = spc + usuario.getNombre() + spc;
		salida[2] = spc + usuario.getApellido_Paterno() + spc;
		salida[3] = spc + usuario.getApellido_Materno() + spc;
		salida[4] = spc + usuario.getContrasena() + spc;
		salida[5] = spc + usuario.getFechaRegistro().toString() + spc;
		salida[6] = to_string(usuario.getMontoAhorrado());
		salida[7] = spc + usuario.getSexo() + spc;
		salida[8] = spc + usuario.getFechaNacimiento().toString() + spc;
		salida[9] = spc + usuario.getTelefono() + spc;
		salida[10] = spc + usuario.getCodigoPais() + spc;
		salida[11] = spc + usuario.getPais() + spc;
		salida[12] = spc + usuario.getMonedaPatron().toString() + spc;
		return salida;
	}
	static string* generarListaDeElementosTransacciones(Transaccion transaccion) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES];
		const string spc = "'";
		salida[0] = spc + transaccion.getIDTransaccion() + spc;
		salida[1] = spc + transaccion.getIDTransaccion() + spc;
		salida[2] = spc + transaccion.getTipoTransaccion() + spc;
		salida[3] = spc + transaccion.getCategoria() + spc;
		salida[4] = spc + transaccion.getSubCategoria() + spc;
		salida[5] = spc + transaccion.getGlosa() + spc;
		salida[6] = spc + transaccion.getTemporalidad() + spc;
		salida[7] = spc + transaccion.getMonedaRegistro().toString() + spc;
		salida[8] = spc + transaccion.getUsuario().getIDUsaurio() + spc;
		salida[9] = to_string(transaccion.getPonderacio());
		return salida;
	}
	static string* generarListaDeElementosTransaccionesFijas(TransaccionTemporalidadFija transaccionFJ) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_FIJA];
		const string spc = "'";
		salida[0] = spc + transaccionFJ.getIDTransaccion() + spc;
		salida[1] = transaccionFJ.getMonto();
		return salida;
	}
	static string* generarListaDeTransaccionesVaribles(TransaccionTemporalidadVariable transaccionV) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_VARIABLE];
		const string spc = "'";
		salida[0] = spc + transaccionV.getIDTransaccion() + spc;
		salida[1] = transaccionV.getCantidad();
		salida[2] = transaccionV.getPrecio();
		return salida;
	}
	static string* generarListaDeTransaccionesPeriodicas(TransaccionPeriodica transaccionP) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_TRANSACCION_PERIODICA];
		const string spc = "'";
		salida[0] = spc + transaccionP.getIDTransaccion() + spc;
		salida[1] = spc + transaccionP.getPeriodicidad() + spc;
		salida[2] = spc + to_string(transaccionP.getVConsulta()) + spc;
		return salida;
	}
	static string* generarListaDeRespuestas(Respuesta r) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_RESPUESTAS];
		const string spc = "'";
		salida[0] = spc + r.getIDRespuesta() + spc;
		salida[1] = spc + r.getUsuario().getIDUsaurio() + spc;
		salida[2] = spc + r.getOpcionSeleccionada().getID_Opcion() + spc;
		salida[3] = spc + r.getUsuario().getIDUsaurio() + spc;
		return salida;
	}
	static string* generarListaDePreguntas(Pregunta pregunta) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_PREGUNTAS];
		const string spc = "'";
		salida[0] = spc + pregunta.getID_Pregunta() + spc;
		salida[1] = spc + pregunta.getNombre() + spc;
		salida[2] = spc + pregunta.getAspecto() + spc;
		salida[3] = to_string(pregunta.getPonderacion());
		salida[4] = spc + pregunta.getTipo() + spc;
		return salida;
	}
	static string* generarListaDeOpciones(Opcion opc) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_OPCIONES];
		const string spc = "'";
		salida[0] = spc + opc.getPregunta().getID_Pregunta() + spc;
		salida[1] = spc + opc.getID_Opcion() + spc;
		salida[2] = spc + opc.getNombre() + spc;
		salida[3] = to_string(opc.getCalificacion());
		return salida;
	}
	static string* generarListaDePresupuestos(Presupuesto prst) {
		static string salida[CANTIDAD_ARGUMENTOS_TABLA_PRESUPUESTOS];
		const string spc = "'";
		salida[0] = spc + prst.getIDPresupuesto() + spc;
		salida[1] = spc + prst.getCategoria() + spc;
		salida[2] = spc + prst.getSubCategoria() + spc;
		salida[3] = spc + prst.getTipo() + spc;
		salida[4] = to_string(prst.getMontoLim());
		salida[5] = spc + prst.getUsuario().getIDUsaurio() + spc;
		return salida;
	}
};

string ConexionDBSQLServer::generarSeparadoresCasoInsert(int large) {
	string asteriscos = "";
	string baseStatement = "INSER INTO + ";
	for (int i = 0; i < large; i++) asteriscos = asteriscos + "*,";
	asteriscos = asteriscos.substr(0, asteriscos.length() - 1);
	return baseStatement + "(" + asteriscos + "); ";
}
string ConexionDBSQLServer::generarSeparadoresCasoUpdate(int large) {
	string asteriscos = "";
	string baseStatement = "UPDATE + SET ";
	for (int i = 0; i < large; i++) asteriscos = asteriscos + "$ = *, ";
	asteriscos = asteriscos.substr(0, asteriscos.length() - 2);
	return baseStatement + asteriscos + " WHERE % = *;";
}
string ConexionDBSQLServer::generarConsulta(int large, string tableName, string elementos[]) {
	string baseStatement = generarSeparadoresCasoInsert(large);
	for (int i = 0; i <large; i++) {
		baseStatement.replace(baseStatement.find("*"),1,elementos[i]);
	}
	baseStatement.replace(baseStatement.find("+"), 1, tableName);
	return baseStatement;
}
string ConexionDBSQLServer::generarConsulta(int large, string tableName, string elementos[],
	string columnName[]) {
	string baseStatement = generarSeparadoresCasoUpdate(large);
	cout << "generar COnsulta: " << baseStatement<<endl;
	for (int i = 0; i < large; i++) {
		baseStatement.replace(baseStatement.find("$"), 1, columnName[i]);
		baseStatement.replace(baseStatement.find("*"), 1, elementos[i]);
		cout << "base Stametement mod" << baseStatement << endl;
	}
	baseStatement.replace(baseStatement.find("+"), 1, tableName);
	baseStatement.replace(baseStatement.find("%"), 1, columnName[0]);
	baseStatement.replace(baseStatement.find("*"), 1, elementos[0]);
	return baseStatement;
}
string ConexionDBSQLServer::generarConsulta(string elementID, string columnElementID,
	string tableName) {
	string baseStatement = "DELETE + WHERE * = '?'";
	baseStatement.replace(baseStatement.find("?"), 1, elementID);
	baseStatement.replace(baseStatement.find("*"), 1, columnElementID);
	baseStatement.replace(baseStatement.find("+"), 1, tableName);
	baseStatement.append(";");
	return baseStatement;
}

string ConexionDBSQLServer::generarConsulta(string tableName, string elementID,
	string columnName, string columnElementID) {
	string baseStatement = "SELECT * FROM + WHERE % = '$'";
	baseStatement.replace(baseStatement.find("$"), 1, elementID);
	baseStatement.replace(baseStatement.find("*"), 1, columnName);
	baseStatement.replace(baseStatement.find("%"), 1, columnElementID);
	baseStatement.replace(baseStatement.find("+"), 1, tableName);
	baseStatement.append(";");
	return baseStatement;
}


class FactoryConexionDB {
public:
	static ConexionDB getConexionSQL();
};
// prototipos

void cargarMenuPrincipal(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarTotalDeGastosPorCategoria(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarTotalDeIngresosPorCategoria(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarTotalDeGastosPorPonderacion(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarTotalDeGastosPorPonderacion(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarMenuRegistrarPresupuesto(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void ingresarInformacionGeneral(string& fecha, string& categoria, string& subCategoria,
	string& glosa, string& moneda, int& ponderacion);
void ingresarInformacionGeneral(string& fecha, string& categoria, string& subCategoria,
	string& glosa, string& moneda, int& ponderacion);
void ingresarInformacionPeriodica(string& periodicidad, string& repeticion);
void ingresarInformacionVariable(float& precio, float& cantidad);
void ingresarInformacionFija(float& monto);
void cargarMenuRegistrarTransaccion(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void ingresarInformacionPresupuestoGeneral(string& categoria, string& subCategoria, float& montoLim);
void cargarMenuRegistrarPresupuesto(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);
void cargarTotalDeGastosPorPonderacion(Usuario usuario, int& bandera, ConexionDBSQLServer conexion);

void main() {
	// Prueba
	Usuario usuario = Usuario("1",
		"Pablo", "Arauz", "Caballero",
		"72107014", Fecha::Fecha("2022-5-2023"), 10000,
		"Masculino", Fecha::Fecha("2001-7-12"),
		"77377232", "591", "Bolivia",
		Moneda("Boliviano", "BOB", 6.96));
	cout << ConexionDBSQLServer::generarConsulta(CANTIDAD_ARGUMENTOS_TABLA_USUARIOS, "Usuario", ConexionDBSQLServer::generarListaDeElementosUsuarios(usuario)) << endl;
	cout << ConexionDBSQLServer::generarConsulta(CANTIDAD_ARGUMENTOS_TABLA_USUARIOS, "Usuario", ConexionDBSQLServer::generarListaDeElementosUsuarios(usuario), NOMBRE_COLUMNAS_USUARIO) << endl;
	cout << ConexionDBSQLServer::generarConsulta(usuario.getIDUsaurio(), NOMBRE_COLUMNAS_USUARIO[0], NOMBRE_TABLA_USUARIOS) << endl;
	for (int i = 1; i < CANTIDAD_ARGUMENTOS_TABLA_USUARIOS; i++) {
		cout << ConexionDBSQLServer::generarConsulta(NOMBRE_TABLA_USUARIOS, "10", NOMBRE_COLUMNAS_USUARIO[i], NOMBRE_COLUMNAS_USUARIO[0]) << endl;
	}
	Transaccion trs = Transaccion("1", "v", "d", "da", "da", "daf", "das", Moneda("100", "ad", 100), usuario,
		Fecha::Fecha("2023-8-2"), 10);
	cout << ConexionDBSQLServer::generarConsulta(CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES, "Transacciones", ConexionDBSQLServer::generarListaDeElementosTransacciones(trs)) << endl;
	cout << ConexionDBSQLServer::generarConsulta(CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES, "Transacciones", ConexionDBSQLServer::generarListaDeElementosTransacciones(trs), NOMBRE_COLUMNAS_USUARIO) << endl;
	cout << ConexionDBSQLServer::generarConsulta(trs.getIDTransaccion(), NOMBRE_COLUMNAS_TRANSACCION[0], NOMBRE_TABLA_TRANSACCIONES) << endl;
	for (int i = 1; i < CANTIDAD_ARGUMENTOS_TABLA_TRANSACCIONES; i++) {
		cout << ConexionDBSQLServer::generarConsulta(NOMBRE_TABLA_TRANSACCIONES, "10", NOMBRE_COLUMNAS_TRANSACCION[i], NOMBRE_COLUMNAS_TRANSACCION[0]) << endl;
	}
	// Programa oficial
	ConexionDBSQLServer conexion = ConexionDBSQLServer();
	string usuarioID, contrasena;
	int bandera = -1;
	do {
		cout << "Bienvenido a Easy Conta!!" << endl;
		cout << "Por favor ingrese su ID_Usuario... " << endl;
		cout << "Usuario: ";
		cin >> usuarioID;
		cout << "Contrase�a: ";
		cin >> contrasena;
		//Usuario usuarioIngresado = conexion.buscarUsuario(usuarioID);
		if (usuario.getContrasena() == contrasena) {
			cout << "Bienvenido " + usuario.getNombre() + " " + usuario.getApellido_Paterno() << endl;
			cargarMenuPrincipal(usuario, bandera, conexion);
		}
		else cout << "Contrase�a ingresada incorrectamente..." << endl;
		
	} while (bandera != 0);
}
void cargarMenuPrincipal(Usuario usuario, int &bandera, ConexionDBSQLServer conexion) {
	cout << "--> Menu Principal " << endl;
	cout << "Por favor ingrese la acci�n que desea realizar ... " << endl;
	cout << "0. Salir de la aplicaci�n " << endl;
	cout << "1. Registrar una transacci�n " << endl;
	cout << "2. Registrar un presupuesto " << endl;
	cout << "3. Ver total de ingresos por categorias" << endl;
	cout << "4. Ver total de gastos por categorias" << endl;
	cout << "5. Ver total de ingreso por ponderaci�n" << endl;
	cout << "6. Ver total de ingreso por ponderaci�n" << endl;
	cout << "7. Mostrar transacciones" << endl;
	cout << "Opci�n elegida: ";
	cin >> bandera;
	switch (bandera) {
	case 1:
		cargarMenuRegistrarTransaccion(usuario, bandera,conexion);
		break;
	case 2:
		cargarMenuRegistrarPresupuesto(usuario, bandera, conexion);
		break;
	case 3:
		cargarTotalDeGastosPorCategoria(usuario, bandera, conexion);
		break;
	default:
		cout << "Error, por favor ingrese una opci�n v�lida" << endl;
		cargarMenuPrincipal(usuario, bandera, conexion);
		return;
	}
}
void cargarTotalDeGastosPorCategoria(Usuario usuario, int& bandera, ConexionDBSQLServer conexion) {

}
void cargarTotalDeIngresosPorCategoria(Usuario usuario, int& bandera, ConexionDBSQLServer conexion) {

}
void cargarTotalDeGastosPorPonderacion(Usuario usuario, int& bandera, ConexionDBSQLServer conexion) {

}
void cargarMenuRegistrarPresupuesto(Usuario usuario, int& bandera, ConexionDBSQLServer conexion) {
	int banderaEsp;
	float montoLim;
	string categoria, subCategoria, tipo, IDTransaccion;
	const string ingreso = "Ingreso", gasto = "Gasto";
	cout << "--> Menu Registro de Transacciones " << endl;
	cout << "0. Ir al menu principal " << endl;
	cout << "1. Registrar Presupuesto de Ingreso " << endl;
	cout << "2. Registrar Presupuesto de Gasto " << endl;
	cout << "Opci�n elegida: ";
	cin >> banderaEsp;
	switch (banderaEsp) {
	case 0:
		cargarMenuPrincipal(usuario, bandera, conexion);
		return;
	case 1:
		ingresarInformacionPresupuestoGeneral(categoria, subCategoria, montoLim);
		tipo = ingreso;
		break;
	case 2:
		ingresarInformacionPresupuestoGeneral(categoria, subCategoria, montoLim);
		tipo = gasto;
		break;
	}
}
void ingresarInformacionPresupuestoGeneral(string &categoria, string &subCategoria, float &montoLim) {
	cout << "Ingrese la categoria : ";
	cin >> categoria;
	cout << "Ingrese la sub-categoria: ";
	cin >> subCategoria;
	cout << "Monto L�mite: ";
	cin >> montoLim;
}
void cargarMenuRegistrarTransaccion(Usuario usuario, int &bandera, ConexionDBSQLServer conexion) {
	int banderaEsp = -1, ponderacion;
	string IDTransaccion, fecha, categoria, subCategoria, glosa, moneda, temporalidad, tipo, repeticion, periodicidad, vRepeticion;
	float monto, precio, cantidad;
	const string fija = "Fija", variable = "Variable", ingreso = "Ingreso", gasto = "Gasto",
		periodica = "Periodica", noPeriodica = "No periodica";
	cout << "--> Menu Registro de Transacciones " << endl;
	cout << "0. Ir al menu principal " << endl;
	cout << "1. Registrar Ingreso Variable Periodico " << endl;
	cout << "2. Registrar Ingreso Variable No Periodico " << endl;
	cout << "3. Registrar Ingreso Fijo Periodico " << endl;
	cout << "4. Registrar Ingreso Fijo No Periodico " << endl;
	cout << "5. Registrar Gasto Variable Periodico " << endl;
	cout << "6. Registrar Gasto Variable No Periodico " << endl;
	cout << "7. Registrar Gasto Fijo Periodico " << endl;
	cout << "8. Registrar Gasto Fijo No Periodico " << endl;
	cout << "Opci�n elegida: ";
	cin >> banderaEsp;
	switch (banderaEsp) {
	case 0:
		cargarMenuPrincipal(usuario,bandera, conexion);
		return;
	case 1:
		ingresarInformacionGeneral(fecha,categoria,subCategoria,glosa,moneda, ponderacion);
		tipo = ingreso;
		temporalidad = variable;
		repeticion = periodica;
		ingresarInformacionPeriodica(periodicidad,vRepeticion);
		ingresarInformacionVariable(precio, cantidad);
		break;
	case 2:
		ingresarInformacionGeneral(fecha,categoria,subCategoria,glosa,moneda, ponderacion);
		tipo = ingreso;
		temporalidad = variable;
		repeticion = noPeriodica;
		ingresarInformacionVariable(precio, cantidad);
		break;
	case 3: 
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda, ponderacion);
		tipo = ingreso;
		temporalidad = fija;
		repeticion = periodica;
		ingresarInformacionPeriodica(periodicidad, vRepeticion);
		ingresarInformacionFija(monto);
		break;
	case 4:
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda, ponderacion);
		tipo = ingreso;
		temporalidad = fija;
		repeticion = noPeriodica;
		ingresarInformacionFija(monto);
		break;
	case 5:
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda, ponderacion);
		tipo = gasto;
		temporalidad = variable;
		repeticion = periodica;
		ingresarInformacionPeriodica(periodicidad, vRepeticion);
		ingresarInformacionVariable(precio, cantidad);
		break;
	case 6:
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda, ponderacion);
		tipo = gasto;
		temporalidad = variable;
		repeticion = noPeriodica;
		ingresarInformacionVariable(precio, cantidad);
		break;
	case 7:
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda, ponderacion);
		tipo = gasto;
		temporalidad = fija;
		repeticion = periodica;
		ingresarInformacionPeriodica(periodicidad, vRepeticion);
		ingresarInformacionFija(monto);
		break;
	case 8:
		ingresarInformacionGeneral(fecha, categoria, subCategoria, glosa, moneda,ponderacion);
		tipo = gasto;
		tipo = gasto;
		temporalidad = fija;
		repeticion = noPeriodica;
		ingresarInformacionFija(monto);
		break;

	default:
		cout << "Error, por favor ingrese una opci�n v�lida" << endl;
		cargarMenuRegistrarTransaccion(usuario, bandera, conexion);
		return;
	}
	conexion.registrarTransaccion(
		Transaccion(
			IDTransaccion,
			tipo,
			categoria,
			subCategoria,
			glosa,
			temporalidad,
			repeticion,
			Moneda::Moneda(moneda),
			usuario,
			Fecha::Fecha(fecha),
			ponderacion));
	if (temporalidad==variable) {
		conexion.registrarTransaccionVariable(
			TransaccionTemporalidadVariable(
				precio,
				cantidad,
				IDTransaccion,
				tipo,
				categoria,
				subCategoria,
				glosa,
				temporalidad,
				repeticion,
				Moneda::Moneda(moneda),
				usuario,
				Fecha::Fecha(fecha),
				ponderacion));
	}
	else {
		conexion.registrarTransaccionFija(
			TransaccionTemporalidadFija(
				monto,
				IDTransaccion,
				tipo,
				categoria,
				subCategoria,
				glosa,
				temporalidad,
				repeticion,
				Moneda::Moneda(moneda),
				usuario,
				Fecha::Fecha(fecha),
				ponderacion));
	}
	if (repeticion == periodica) {
		conexion.registrarTransaccionPeriodica(TransaccionPeriodica(
			periodicidad,
			vRepeticion=="1",
			IDTransaccion,
			tipo,
			categoria,
			subCategoria,
			glosa,
			temporalidad,
			repeticion,
			Moneda::Moneda(moneda),
			usuario,
			Fecha::Fecha(fecha),
			ponderacion));
	}
}
void ingresarInformacionGeneral(string &fecha, string &categoria, string &subCategoria, 
		string &glosa,string &moneda, int &ponderacion) {
	cout << "Ingrese la fecha en que realizo la transaccion: " ;
	cin >> fecha;
	cout << "Ingrese la categoria de la transacci�n: ";
	cin >> categoria;
	cout << "Ingrese la categoria de la transacci�n: ";
	cin >> subCategoria;
	cout << "Ingrese alguna glosa / nota que desee guardar: ";
	cin >> glosa;
	cout << "Ingrese la contracci�n de alguna moneda: ";
	cin >> moneda;
	cout << "Ingrese del 1 al 10 que tan importante es tu gasto: ";
	cin >> ponderacion;
}
void ingresarInformacionPeriodica(string &periodicidad, string &repeticion) {
	cout << "Ingrese la periodicidad: ";
	cin >> periodicidad;
	cout << "Ingrese la repetici�n: (Ingrese 1 para confirmar y 0 para cancelar): ";
	cin >> repeticion;
	if (repeticion != "1" && repeticion != "0") 
		ingresarInformacionPeriodica(periodicidad, repeticion);
}
void ingresarInformacionVariable(float &precio, float&cantidad) {
	cout << "Ingrese el precio del item que compro: ";
	cin >> precio;
	cout << "Ingrese la cantidad del item que compro: ";
	cin >> cantidad;
}
void ingresarInformacionFija(float &monto) {
	cout << "Ingrese el monto del aspecto que compro: ";
	cin >> monto;
}

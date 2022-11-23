#include <iostream>
#include <sstream>
#define NOMBRE_ARCHIVO2 "Admins.csv"
#define NOMBRE_ARCHIVO1 "Categorias.csv"
#include "Cliente.h"
#include "Personal.h"
#include "Venta.h"
using namespace std;
#include <vector>
#include <fstream>


void Start();
void Enter();
void NewUser();
void Admin();
void Ingreso();
void ReadAdmins();
void AddToBin(Personal p);
void ReadCategorias();
void ReadProductos();
vector<Personal> dataInfo;
vector<Categoria> categorias;
vector<Cliente> clientes;
vector<Producto> productos;
vector<Venta> ventas;

void Menu(Venta unaVenta)
{
	int number;
	cout << "1. Agregar Objeto" << endl;
	cout << "2. Eliminar Producto" << endl;
	cout << "3. Listar venta" << endl;
	cout << "4. Recibir total" << endl;
	
	cin >> number;
    
	if (number == 1) {
		if(!productos.empty())
		{
			int index;
			for(int i = 0; i < productos.size(); i++){
				cout << i << ": "<< productos[i].GetNomProducto() << endl;
			}
			cin >> index;			
			unaVenta.IngresarProductos(productos[index]);
		}else
		{
			cout << "Aun no hay productos" << endl;
		}
	}else if(number == 2)
	{
		int index;
		cout << "Ingrese codigo a eliminar" << endl; cin >> index;
		unaVenta.Eliminar(index);
	}
	else if(number == 3)
	{
		unaVenta.Listar();
	}else if(number == 4)
	{
		cout << "Ingreso total: " << unaVenta.GetTotalVenta() << endl;
	}

	Menu(unaVenta);
}

void StartClient()
{
	string dir;
	int ruc;
	string nombreApellido;
	
	cout << "Ingrese Nombre: " << endl;
	cin >> nombreApellido;
	cout << "Ingrese La Direccion: " << endl;
	cin >> dir;
	cout << "Ingrese RUC: " << endl;
	cin >> ruc;

	Cliente newAccount(clientes.size(),nombreApellido,dir,ruc);

	clientes.push_back(newAccount);
	Venta unaVenta(ventas.size(), "1", "Activa", clientes.size());
	Menu(unaVenta);
}

void CrearProducto(){
	string nomProducto;
	float preProducto;
	int stkProducto;
	int aux;
	
	cout << "------------------------------" << endl;
	cout << "Ingrese nombre del producto: "; cin >> nomProducto;
	cout << "Ingrese precio del producto: "; cin >> preProducto;
	cout << "Ingrese stock del producto: "; cin >> stkProducto;
	cout << "------------------------------" << endl;

	cout << "" << endl;
	cout << "Seleccione categoria:" << endl;
	for(int i =0;i<categorias.size();i++){
		cout << "[" << i <<"] " << categorias[i].GetName() << endl;
	}
  
	cout << "Numero de la categoria: "; cin >> aux;
	Producto nuevoProducto(productos.size(), nomProducto, preProducto, stkProducto, categorias[aux]);

	ofstream archivo;
		
	archivo.open("Admins.csv", ios::app);
		
	if(archivo.good()){
	
		archivo<<nomProducto<<";"<<preProducto<<";"<<stkProducto<<";"<< categorias[aux].GetCodigo() <<";"<<endl;
			
			
		cout<<"Datos ingresados correctamente"<<endl;
			
		archivo.close();
	}
	else{
			
		cout<<"Ocurrió un error al abrir el archivo. Inténtalo de nuevo. "<<endl;
	}
	productos.push_back(nuevoProducto);
	Admin();
}

int main(int argc, char* argv[])
{
	ReadCategorias();
	ReadAdmins();
	Ingreso();
	
	
}

void Ingreso()
{
	int number;

	cout << "1. Eres administrador" << endl;
	cout << "2. Eres cliente" << endl;

	cin >> number;
    
	if (number == 1) {
		Start();
	}else if (number == 2) {
		StartClient();
	}else
	{
		Ingreso();
	}
}

void Start() {
	int number;
	bool ingreso = false;

	if(ingreso){
		Admin();
	}{
		cout << "1. Ingresar" << endl;
		cout << "2. Registrar Usuario" << endl;

		cin >> number;
    
		if (number == 1) {
			Enter();
		}
		if (number == 2) {
			NewUser();
		}
	}
	
}

void Enter() {
	string user;
	string password;

	cout << "Usuario: ";
	cin >> user;
	cout << "Contraseña: ";
	cin >> password;

	for (int i = 0; i < dataInfo.size(); i++) {
		if (user == dataInfo[i].GetUsuario()) {
			if (password == dataInfo[i].GetPassword()) {
				cout << "Has ingresado correctamente" << endl;
				Admin();
				break;
			}
			cout << "  Contraseña Incorrecta" << endl;
			Start();
			break;
		}
		if (i + 1 == dataInfo.size()) {
			cout << "User no encontrado";
			Start();
			break;
		}
	}
}

void NewUser() {
	string user;
	string password;
	string nombreApellido;
	
	cout << "Ingrese Nombre y Apellido: ";
	cin >> nombreApellido;
	cout << "Ingrese Nuevo Usuario: ";
	cin >> user;
	cout << "Ingrese Contraseña: ";
	cin >> password;

	Personal newAccount(dataInfo.size(),nombreApellido,user,password);

	dataInfo.push_back(newAccount);
	

	ofstream archivo;
		
	archivo.open("Admins.csv", ios::app);
		
	if(archivo.good()){
	
		archivo<<nombreApellido<<";"<<user<<";"<<password<<";"<<endl;
			
			
		cout<<"Datos ingresados correctamente"<<endl;
			
		archivo.close();
	}
	else{
			
		cout<<"Ocurrió un error al abrir el archivo. Inténtalo de nuevo. "<<endl;
	}

	Start();
}

Categoria CrearCategorias(){
	int cod;
	string nom;
	cout << "Ingrese nom: "; cin >> nom;
	Categoria a(categorias.size(), nom);
        

	ofstream archivo;
		
	archivo.open("Categorias.csv", ios::app);
		
	if(archivo.good()){
	
		archivo<<nom<<";"<<endl;
			
		archivo.close();
	}
	else{
			
		cout<<"Ocurrió un error al abrir el archivo. Inténtalo de nuevo. "<<endl;
	}

	return a;
}

void Admin(){
	int a;
	cout << "Bienvenido administrador, que accion quiere realizar? "<< endl;
	cout << "1. Agregar Categorias" << endl;
	cout << "2. Agregar Objetos" << endl;
	cout << "3. Regresar" << endl;
	cin >> a;
	if(a == 1){
		categorias.push_back(CrearCategorias());
		Admin();
	}
	if(a == 2){
		if(categorias.empty()){
			cout << "No hay categorias" << endl;
			Admin();
		}else{
			CrearProducto();
		}
	}if(a == 3)
	{
		Ingreso();
	}
}

void ReadAdmins()
{
	string user;
	string password;
	string nombreApellido;
	
	string a;
	int i = 0;
	ifstream archivo(NOMBRE_ARCHIVO2);
	string linea;
	const char delimitador = ';';
							
	getline(archivo,linea);
							
							
							
	while(getline(archivo,linea)){
								
		
		stringstream stream(linea);
		getline(stream, nombreApellido, delimitador);
		getline(stream, user, delimitador);
		getline(stream, password, delimitador);
		
		Personal admin(dataInfo.size(), nombreApellido, user, password);
							
							
		dataInfo.push_back(admin);
								
		cout<<endl<<endl;
	}
	
}

void ReadCategorias()
{
	string nom;
	string a;
	int i = 0;
	ifstream archivo(NOMBRE_ARCHIVO1);
	string linea;
	const char delimitador = ';';
							
	getline(archivo,linea);
							
							
							
	while(getline(archivo,linea)){
		
		stringstream stream(linea);
		getline(stream, nom, delimitador);
		Categoria unaCategoria(categorias.size(),nom);
							
							
		categorias.push_back(unaCategoria);
								
		cout<<endl<<endl;
	}
	
}


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void asignarDoctor(){
	ifstream Leer("Tarea.txt");
	string nombre, genero, estado;
	int edad;
	string cuiValue, Bclave;

	std::cout << "Ingrese su CUI para buscar" << std::endl;
	std::cin >> Bclave;

	bool encontrado = false;

    while (Leer >> nombre >> cuiValue >> edad >> genero >> estado) {
        if (cuiValue == Bclave) { 
            encontrado = true;
            cout << "Nombre...." << nombre << endl;
            cout << "Cui..." << cuiValue << endl;
            cout << "Edad..." << edad << endl;
            cout << "Genero..." << genero << endl;
            cout << "Estado..." << estado << endl;
            break; 
        }
    }

    if (encontrado) {
        if (estado == "Grave") {
            cout << "Doctor asignado: Dr. Juan Perez" << endl;
        } else if (estado == "Enfermo") {
            cout << "Doctor asignado: Dr. Maria Lopez" << endl;
        } else {
            cout << "Estado no reconocido" << endl;
        }
    } else {
        cout << "CUI no encontrado" << std::endl;
    }
    Leer.close();
}

void case2(){
	ifstream Leer;
	string nombre, genero, estado;
	int edad;
	string cui, Bclave;
	int opcion2;

	cout<<"*** MENU SECUNDARIO ***"<<endl;
	cout<<"1. Buscar Paciente"<<endl;
	cout<<"2. Todos los Pacientes"<<endl;
	cin>>opcion2;

	switch(opcion2){
		case 1:{
		Leer.open("Tarea.txt");
		Leer>>nombre;
		
		bool encontrado = false;
		
		cout<<"Ingrese su CUI para buscar"<<endl;
		cin>>Bclave;

		while(!Leer.eof()){
			Leer>>cui;
			if(cui==Bclave){
				encontrado=true;
				Leer>>edad;
				Leer>>genero;
				Leer>>estado;
				cout<<"Nombre...."<<nombre<<endl;
				cout<<"Cui..."<<cui<<endl;
				cout<<"Edad..."<<edad<<endl;
				cout<<"Genero..."<<genero<<endl;
				cout<<"Estado..."<<estado<<endl;
				cout<<endl;
			}
			Leer>>nombre;
			}
			
			if(encontrado==false){
				cout<<"CUI INCORRECTO"<<endl;
			}
			
			Leer.close();

			break;
		}

		case 2:{
			Leer.open("Tarea.txt");
			while (!Leer.eof())
			{
				while(Leer >> nombre >> cui >> edad >> genero >> estado){
					cout<<"Paciente"<<endl;
					cout<<"Nombre "<<nombre<<endl;
					cout<<"CUI "<<cui<<endl;
					cout<<"Edad "<<edad<<endl;
					cout<<"Genero "<<genero<<endl;
					cout<<"Estado "<<estado<<endl;
					cout<<endl;
				}
			}
			Leer.close();
		break;
		}
	}
}

int main(){
	int cui, opcion, edad;
	char nombre[30];
	char genero[30];
	char estado[30];
	ofstream Guardar;
	ifstream Leer;
	Guardar.open("Tarea.txt", ios::app);
	while(opcion!=4){
		cout<<"*** BIENVENIDOS AL HOSPITAL SAL LUCAS ***"<<endl;
		cout<<"1. Guardar Pacientes"<<endl;
		cout<<"2. Reportes"<<endl;
		cout<<"3. Asignar Doctor"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Ingrese una opcion:"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1:{
				cout<<"Ingrese Nombre"<<endl;
				cin>>nombre;
				cout<<"Ingrese CUI"<<endl;
				cin>>cui;
				cout<<"Ingrese Edad"<<endl;
				cin>>edad;
				cout<<"Ingrese Genero"<<endl;
				cin>>genero;
				cout<<"Ingrese su Estado de Salud: 1.Grave, 2.Enfermo, 3.Malo"<<endl;
				cin>>estado;
				
				Guardar<<nombre<<" "<<cui<<" "<<edad<<" "<<genero<<" "<<estado<<endl;
				break;
			}
			case 2:{
				case2();
				break;
			}
			case 3:{
				asignarDoctor();
				break;
			}	
		}
	}
	return 0;
}
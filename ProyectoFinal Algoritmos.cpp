#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

struct Citas {
    char nombrePaciente[30];
    char especialidad[50];
    int dia; 
    int mes; 
    int ano;

};

const int total_citas = 10;
Citas listadecitas[total_citas];
int totalcitas = 0;

void agregarCita() {
    if(totalcitas < total_citas) {  
        Citas nuevaCita;
        cout << "Ingrese el nombre del paciente: ";
        cin >> nuevaCita.nombrePaciente;
        cout << "Para que es la cita?: ";
        cin.ignore(); 
		cin.getline(nuevaCita.especialidad, sizeof(nuevaCita.especialidad));	
		
        cout << "Ingrese la fecha para la cita: (dd/mm/yyyy) ";
        char separador; 
        
        cin >> nuevaCita.dia >> separador >> nuevaCita.mes >> separador >> nuevaCita.ano;
        listadecitas[totalcitas] = nuevaCita;
        totalcitas++;
        cout << "Cita agregada con exito!" << endl;
    } else {
        cout << "Lo siento, la cola está llena!" << endl;
    }	
}
void consultarCitas() {
    cout << "Listado de Citas: " << endl;
    for(int i = 0; i < totalcitas; ++i) {
    	cout << i + 1 << ".";
        cout << "Nombre: " << listadecitas[i].nombrePaciente << ", Edad: " << listadecitas[i].especialidad << ", Fecha: " << listadecitas[i].dia << "/" << listadecitas[i].mes << "/" << listadecitas[i].ano << endl;
    }	
}

int main() {
    int opcion;
    do {
        cout << "Menu: " << endl;
        cout << "1. Registrar Cita" << endl;
        cout << "2. Consultar Citas" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarCita();
                break;
           	case 2:
                consultarCitas();
                break;
            case 3:
                cout << "Saliendo del aplicativo" << endl;
                break;
            default:
                cout << "Error! Seleccione una opcion válida, por favor." << endl;
                break;
        }
    } while(opcion != 3);

    return 0;
}



#include <iostream> //Incluimos la librer�a para poder haer uso de entrada/salida de C++

using namespace std; //Declaramos para evitar el uso de std:: 

//Declaramos la estructura de Citas y establecemos sus componentes. 
struct Citas {
	int id; //Id �nico para cada cita.
    char nombrePaciente[10];  //Declaraci�n de variable de tipo char para el nombre del paciente con un limite de 10 car�cteres. 
    char apellidoPaciente[10]; //Declaraci�n de variable de tipo char para el apellido del paciente con un limite de 10 car�cteres. 
    char especialidad[25]; //Declaraci�n de variable de tipo char para la especialidad con un limite de 25 car�cteres. 
	int numerodetelefono; //Declaraci�n de variable de tipo int para el numero de telefono. 
    int dia; //Declaraci�n de variable de tipo int para el d�a. 
    int mes; //Declaraci�n de variable de tipo int para el mes. 
    int ano; //Declaraci�n de variable de tipo int para el a�o. 

};

const int total_citas = 10; //Declaramos una constante (para que no pueda ser modificada ejecutado el programa) de total_citas para podes establecer un limite de registros. 
Citas listadecitas[total_citas]; //Aqu� declaramos listadecitas, su longitud esta determinada por total_citas. 
int totalcitas = 0; //Inicializa la variable citas en 0. 

//Funcion para agregar una nueva cita
void agregarCita() { //Se declara la funci�n editarCitas con void para que no regrese ning�n valor.
    if(totalcitas < total_citas) {  //Agreamos la condicion que eval�a si el totalcitas es menor que el numero total de citas permitidas en total_citas. 
        Citas nuevaCita; //Declaramos una variable de tipo Citas que fue declarada anteriormente, llamada nuevaCita. 
        nuevaCita.id = totalcitas + 1; // Se asigna un id �nico a la nueva cita.
        cout << "Ingrese el nombre del paciente: "; //Nos muestra en pantalla para que ingresemos el nombre del paciente.
        cin >> nuevaCita.nombrePaciente; //Nos pide ingresar los datos para almacenarlos.
        cout << "Ingrese el apellido del paciente: "; 
        cin >> nuevaCita.apellidoPaciente;  //Nos pide ingresar los datos para almacenarlos.
        cout << "Ingrese el numero de telefono: "; 
        cin >> nuevaCita.numerodetelefono; //Nos pide ingresar los datos para almacenarlos.
        cout << "Para que es la cita?: "; //Nos pide ingresar la especialidad.  
        cin.ignore();  //Esta funci�n se utiliza para que nos permita leer de nuevo un valor de entrada.
		cin.getline(nuevaCita.especialidad, sizeof(nuevaCita.especialidad)); //Funci�n que se utiliza para leer una l�nea completa de texto(hasta que se encuentra un salto de linea o se alcanza el limite) y almacena los car�cteres
        cout << "Ingrese la fecha para la cita: (dd/mm/yyyy) "; //Nos pide ingresar la fecha con el formato requerido. 
        char separador;  //Nos permite agregar un separador entre las fechas para no dejar el espacio en blanco. 10 12 2023 => 10/12/2023
        cin >> nuevaCita.dia >> separador >> nuevaCita.mes >> separador >> nuevaCita.ano; //Nos pide ingresar los datos de la fecha para almacernarlo. 
        listadecitas[totalcitas] = nuevaCita; //Asigna el valor de nuevaCita al elemento de totalcitas en listadecitas, para que agregue al final de la posici�n que corresponde a totalcitas. 
        totalcitas++; //Contiene operador de incremento para totalcitas, as� se pueden registrar m�s
        cout << "Cita agregada con exito!" << endl; //Si se cumple correctamente la informaci�n, nos muestra en pantalla. 
    } else {
        cout << "Lo siento, la cola est� llena!" << endl; //Si se llego al limite de citas que se estableci� anteriormente, nos muestra el siguiente mensaje. 
    }	
}
//Funcion para consultar citas
void consultarCitas() { //Se declara la funci�n editarCitas con void para que no regrese ning�n valor.
	if(totalcitas == 0){ //Se declara el if para cuando se ingrese al men� detecte si hay citas registradas. 
        cout << "No hay citas registradas! " <<endl; //Si se cumple la condici�n, nos muestra este mensaje en pantalla. 
        cout << "Por favor, agrega una cita! " << endl; //Muestra en pantalla el mensaje para que se agregue una cita. 
		 
	}else{ //Si no se cumple la condici�n, nos muestra recarga la funcion. 
		cout << "Listado de Citas: " << endl; //Muestra en pantalla el mensaje.
		for(int i = 0; i < totalcitas; ++i) { //Establecemos un bucle que recorre a traves de todas las citas en listadecitas, i es un indice que empieza en 0 y termina en totalcitas - 1.
    	cout << i + 1 << "."; //Imprime en pantalla el numero de cita que va incrementando en 1 para que empiece en 1 y no en 0. 
    	//Imprime los datos del paciente en las citas. 
        cout << "Nombre: " << listadecitas[i].nombrePaciente << " " << listadecitas[i].apellidoPaciente 
			 << ", Numero de Telefono: " << listadecitas[i].numerodetelefono << ", Especialidad: " << listadecitas[i].especialidad 
			 << ", Fecha programada: " << listadecitas[i].dia << "/" << listadecitas[i].mes << "/" << listadecitas[i].ano << endl;
		}
    }	
}
//Funcion para editar las citas
void editarCitas(){  //Se declara la funci�n editarCitas con void para que no regrese ning�n valor. 
	int id;	//Declaramos int para una variable llamada id
	cout << "Ingrese el numero de cita que desea modificar: "; //Mostramos el mensaje en consola
	cin >> id; //Nos pide ingresar el id. 
	
	if(id >= 1 && id <= totalcitas){ //Creamos la estructura if para que se ejecute el programa con una condici�n, la condici�n verifica si el valor de id se encuentra en el rango numero 1 de totalcitas; 
	// y con &&(y) ejecuta la segunda condicion que verifica si id es menor o igual a total citas, el if se ejecuta si ambas condiciones son verdaderas. 
		Citas &cita = listadecitas[id - 1]; //Obtiene el id de la cita que se modificara 
		cout << "Ingrese el nombre del paciente: "; //Nos muestra en pantalla para que ingresemos el nombre del paciente. 
		cin >> cita.nombrePaciente; //Nos pide ingresar los datos para almacenarlos. 
		cout << "Ingrese el apellido del paciente: "; //Nos muestra en pantalla para que ingresemos el apellido del paciente. 
		cin >> cita.apellidoPaciente; //Nos pide ingresar los datos para almacenarlos
		cout << "Ingrese el numero de telefono: "; //Nos muestra en pantalla para que ingresemos el telefono del paciente. 
		cin >> cita.numerodetelefono; //Nos pide ingresar los datos para almacenarlos
		cout << "Para qu� es la cita: "; //Nos pide ingresar la especialidad.  
		cin.ignore();  //Esta funci�n se utiliza para que nos permita leer de nuevo un valor de entrada. 
		cin.getline(cita.especialidad, sizeof(cita.especialidad)); //Funci�n que se utiliza para leer una l�nea completa de texto(hasta que se encuentra un salto de linea o se alcanza el limite) y almacena los car�cteres
		cout << "Ingrese la nueva fecha para la cita (dd/mm/yyyy): "; //Nos pide ingresar la fecha con formato d�a/mes/a�o.  
		char separador; //Nos permite agregar un separador entre las fechas para no dejar el espacio en blanco. 10 12 2023 => 10/12/2023
		cin >> cita.dia >> separador >> cita.mes >> separador >> cita.ano; //Nos pide ingresar los datos para almacenarlos
		cout << "Se edito la cita con exito!" <<endl; // Si todo funciona correctamente, nos muestra este mensaje en pantalla. 
	}else{ 
		cout << "Numero de cita invalido! " << endl; //Si ingresamos un id de cita que no existe nos muestra automaticamente este mensaje. 
	}
}

//Declaramos la funci�n para que devuelva un valor entero. 
int main() {
    int opcion; //Declaramos la variable llamada opcion para almacenar la opcion. 
    do { //Iniciamos un bucle do-while
    	//Nos imprime en pantalla un menu para seleccionar una opci�n.  
        cout << "Menu: " << endl; 
        cout << "1. Registrar Cita" << endl; 
        cout << "2. Consultar Citas" << endl;
        cout << "3. Editar Citas" <<endl; 
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion; //Nos permite ingresar el numero de opci�n
		
		///Agregamos la estructura switch para manejar las opciones ingresadas. 
        switch (opcion) {
            case 1: //Si es 1, ejecuta la funci�n de agregarCita
                agregarCita();
                break; //Se utiliza la instrucci�n para detener el programa prematuramente. 
           	case 2:
                consultarCitas(); //Si es 1, ejecuta la funci�n de consultarCitas
                break; 
            case 3:  //Se utiliza la instrucci�n para detener el programa prematuramente.
            	editarCitas();  //Si es 3, ejecuta la funci�n de editarCitas
            	break;
            case 4: //Se utiliza la instrucci�n para detener el programa prematuramente.
                cout << "Saliendo del aplicativo" << endl; // Si es 4, nos muestra un mensaje en pantalla y se cierra.  
                break; //Se utiliza la instrucci�n para detener el programa prematuramente.
            default: //Si la opci�n no coincide con ninguna del men�, ejecutar� el siguiente bloque de c�digo. 
                cout << "Error! Seleccione una opcion v�lida, por favor." << endl; //Nos muestra en pantalla si ninguna opci�n coincide con las del men�. 
                break; //Se utiliza la instrucci�n para detener el programa prematuramente.
        }
    } while(opcion != 4); //Evalua las interacciones del bucle, si opcion no es 4, el bucle se estar� ejecuntando, si es 4, el programa sale del bucle. 

    return 0; //Nos indica para indicar que el programa se ejecuto correctamente. 
}



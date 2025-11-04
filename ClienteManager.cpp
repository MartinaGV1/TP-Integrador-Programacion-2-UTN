#include <iostream>
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
#include "funcionesGlobales.h"
#include <cstring>

using namespace std;

void ClienteManager::cargarCliente(Cliente &obj){
    char dni[9];
    char nombre[30];
    char apellido[30];
    char email [30];
    char telefono [12];

    cout<<"DNI: ";
    do{
        cargarCadena(dni, 9);

        if (!sonNumeros(dni)){
            cout<<"El DNI tiene que ser numerico. Intente de nuevo: ";
        }
        else if (_archivoC.buscarPorDNI(dni) != -1){
            cout<<"Ya existe un cliente con ese DNI. Intente de nuevo: ";
        }

    } while(!sonNumeros(dni) || _archivoC.buscarPorDNI(dni) != -1);
    obj.setDNI(dni);

    cout<<"Nombre: ";
    do{
        cargarCadena(nombre, 30);
        if (!sonLetras(nombre)){
            cout<<"El nombre tiene que tener letras. Intente de nuevo: ";
        }

    } while (!sonLetras(nombre));
    obj.setNombre(nombre);

    cout<<"Apellido: ";
    do{
        cargarCadena(apellido, 30);
        if (!sonLetras(apellido)){
            cout<<"El apellido tiene que tener letras. Intente de nuevo: ";
        }

    } while (!sonLetras(apellido));
    obj.setNombre(apellido);

    cout<<"Email: ";
    cargarCadena(email, 30);
    obj.setEmail(email);

    cout<<"Telefono: ";
    do{
        cargarCadena(telefono, 12);

        if (!sonNumeros(dni)){
            cout<<"El Telefono tiene que ser numerico. Intente de nuevo: ";
        }

    } while(!sonNumeros(telefono));
    obj.setDNI(dni);

    obj.setEstado(true);
}

void ClienteManager::cargar(){
    Cliente nuevoCliente;

    cargarCliente(nuevoCliente);

    if (_archivoC.guardar(nuevoCliente)){

        cout<<"Cliente cargado exitosamente."<<endl;
    }
    else {
        cout<<"No se pudo cargar el cliente. "<<endl;
    }
}

void ClienteManager::mostrarCliente(Cliente obj){

    cout<<"******************************"<<endl;
    cout<<"DNI: "<<obj.getDNI()<<endl;
    cout<<"Nombre: "<<obj.getNombre()<<endl;
    cout<<"Apellido: "<<obj.getApellido()<<endl;
    cout<<"Email: "<<obj.getEmail()<<endl;
    cout<<"Telefono: "<<obj.getTelefono()<<endl;
    cout<<"******************************"<<endl;
}

void ClienteManager::mostrarTodos(){
    Cliente obj; //declaro un objeto cliente
    int total = _archivoC.contarRegistros(); //cuento el total del registro

    if (total==0){
        cout<<"No hay clientes registrados."<<endl; //si no hay registros, vuelve.
        return;
    }

    cout<<"*** Listado de Clientes ***"<<endl;
    for (int i=0; i<total; i++){
        if (_archivoC.leer(obj, i)){//lee el registro en cada iteracion

            if (obj.getEstado()){//muestra los que est n activos
                mostrarCliente(obj);
            }
        }
    }
}

void ClienteManager::buscar(){
    int opcion;

    cout << "--------------------------------" << endl;
    cout << "        Buscar Cliente          " << endl;
    cout << "--------------------------------" << endl;
    cout << " 1. Buscar por DNI" << endl;
    cout << " 2. Buscar por Nombre" << endl;   // <-- MODIFICADO
    cout << " 3. Buscar por Apellido" << endl; // <-- NUEVO
    cout << " 0. Volver al Menu Principal" << endl;
    cout << "--------------------------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion){
        case 1:
            buscarPorDNI();
            break;
        case 2:
            buscarPorNombre();
            break;
        case 3:
            buscarPorApellido();
            break;
        case 0:
            break;
        default:
            cout<<"Opci¢n incorrecta."<<endl;
            break;
    }
}

void ClienteManager::buscarPorDNI(){
    char dni[9];
    int pos;
    Cliente obj;

    cout<<"Ingrese el DNI a buscar: ";
    cargarCadena(dni,9);

    pos = _archivoC.buscarPorDNI(dni);

    if (pos==-1){
        cout<<"No se encontr¢ ningun cliente con ese DNI."<<endl;
        return;
    }

    if (_archivoC.leer(obj, pos)){
        cout<<"--- Cliente encontrado ---"<<endl;
        mostrarCliente(obj);
    } else {
        cout<<"No se encontr¢ el cliente"<<endl;
    }

}

void ClienteManager::buscarPorNombre(){
    char nombre[30];
    int total = _archivoC.contarRegistros();
    bool encontrado = false;
    Cliente obj;

    cout<<"Ingrese el nombre: ";
    cargarCadena(nombre, 30);

    for (int i=0; i<total; i++){
        if (_archivoC.leer(obj, i)){

            if (strcmp(obj.getNombre(), nombre)==0 && obj.getEstado() == true){
                mostrarCliente(obj);
                encontrado=true;
            }
        }
    }

    if (!encontrado){
        cout<<"No se encontr¢ el cliente"<<endl;
    }
}

void ClienteManager::buscarPorApellido(){
    char apellido[30];
    int total = _archivoC.contarRegistros();
    bool encontrado = false;
    Cliente obj;

    cout<<"Ingrese el nombre: ";
    cargarCadena(apellido, 30);

    for (int i=0; i<total; i++){
        if (_archivoC.leer(obj, i)){

            if (strcmp(obj.getApellido(), apellido)==0 && obj.getEstado() == true){
                mostrarCliente(obj);
                encontrado=true;
            }
        }
    }

    if (!encontrado){
        cout<<"No se encontr¢ el cliente"<<endl;
    }
}

void ClienteManager::modificar(){
    char dni[9];
    int pos;
    Cliente obj;

    cin.ignore();
    cout << "--------------------------------" << endl;
    cout << "       Modificar Cliente        " << endl;
    cout << "--------------------------------" << endl;
    cout << " Ingrese el dni del cliente: ";
    cargarCadena(dni, 9);

    pos = _archivoC.buscarPorDNI(dni);
    if(pos==-1){
        cout<<"Cliente no encontrado."<<endl;
        return;
    }

    if(!_archivoC.leer(obj, pos)){
        cout<<"No se pudo leer el archivo."<<endl;
        return;
    }

    cout<<"--- Cliente encontrado ---"<<endl;
    mostrarCliente(obj);

    int opcion;
    cout << "--------------------------------" << endl;
    cout << "¨Que  desea modificar?" << endl;
    cout << " 1. Nombre" << endl;
    cout << " 2. Apellido" << endl;
    cout << " 3. Email" << endl;
    cout << " 4. Telefono" << endl;
    cout << " 0. Cancelar" << endl;
    cout << "--------------------------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    char aux[30];
    bool modificado=false;

    switch(opcion){
        case 1:{
            cout<<"Ingrese el nuevo Nombre: ";

            do{
                cargarCadena(aux, 30);
                if(!sonLetras(aux)){
                    cout<<"El nombre solo admite letras. Intente de nuevo: ";
                }

            } while (!sonLetras(aux));

            obj.setNombre(aux);
            modificado=true;
            break;
        }
        case 2:{
            cout<<"Ingrese el nuevo Apellido: ";

            do{
                cargarCadena(aux, 30);
                if(!sonLetras(aux)){
                    cout<<"El apellido solo admite letras. Intente de nuevo: ";
                }

            } while (!sonLetras(aux));

            obj.setApellido(aux);
            modificado=true;
            break;
        }
        case 3:{
            cout<<"Ingrese el nuevo Email: ";
            cargarCadena(aux, 30);
            obj.setEmail(aux);
            modificado=true;
            break;
        }
        case 4:
            cout<<"Ingrese el nuevo Telefono: ";
            do{
                cargarCadena(aux, 12);
                if(!sonNumeros(aux)){
                    cout<<"El Telefono solo admite numeros. Intente de nuevo: ";
                }

            } while (!sonNumeros(aux));
            obj.setTelefono(aux);
            modificado=true;
            break;

        case 0:
            cout<<"Modificaci¢n cancelada." <<endl;
            return;

        default:
            cout<<"Opci¢n incorrecta."<<endl;
            return;
    }

    if (modificado){
        if (_archivoC.modificar(obj, pos)){
            cout<<"Cliente modificado exitosamente."<<endl;
        }else {
            cout<<"No se pudo modificar."<<endl;
        }
    }

}

void ClienteManager::eliminar(){
    char dni[9];
    int pos;
    Cliente obj;

    cin.ignore();
    cout << "--------------------------------" << endl;
    cout << "       ELIMINAR CLIENTE         " << endl;
    cout << "--------------------------------" << endl;
    cout << "Ingrese el DNI del cliente a dar de baja: ";
    cargarCadena(dni, 9);

    pos=_archivoC.buscarPorDNI(dni);

    if(pos==-1){
        cout<<"No se encontr¢ el cliente."<<endl;
        return;
    }

    if(_archivoC.leer(obj, pos)){
        cout<<"No se pudo leer el registro."<<endl;
        return;
    }

    if (obj.getEstado()==false){
        cout<<"El cliente ya est  inactivo."<<endl;
        return;
    }

    char opcion;
    cout<<"--- Cliente encontrado ---"<<endl;
    mostrarCliente(obj);

    cout<<"¨Desea continuar con la baja? (S/N)"<<endl;
    cin>> opcion;

    if(opcion !='S' && opcion != 's'){
        cout<<"Baja cancelada."<<endl;
        return;
    }

    obj.setEstado(true);

    if(_archivoC.modificar(obj, pos)){
        cout<<"Cliente "<<obj.getDNI()<<" eliminado exitosamente."<<endl;
    } else{
        cout<<"No se pudo eliminar, error en el registro."<<endl;
    }
}

void ClienteManager::restaurar(){
    char dni[9];
    int pos;
    Cliente obj;

    cin.ignore();
    cout << "--------------------------------" << endl;
    cout << "      Restaurar Cliente         " << endl;
    cout << "--------------------------------" << endl;
    cout << "Ingrese el DNI del cliente: ";
    cargarCadena(dni, 9);

    pos=_archivoC.buscarPorDNI(dni);

    if (pos ==-1){
        cout<<"Cliente no encontrado."<<endl;
        return;
    }

    if(!_archivoC.leer(obj, pos)){
        cout<<"No se pudo leer."<<endl;
        return;
    }

    if (obj.getEstado()==true){
        cout<<"El cliente "<<obj.getDNI()<<" ya se encuentra activo."<<endl;
        return;
    }

    obj.setEstado(true);

    if(_archivoC.modificar(obj, pos)){
        cout<<"Cliente: "<<obj.getDNI()<<" restaurado exitosamente."<<endl;
    } else{
        cout<<"No se pudo restaurar."<<endl;
    }
}

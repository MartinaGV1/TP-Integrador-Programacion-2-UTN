#include <iostream>
#include "Menu.h"
#include "funcionesGlobales.h"

using namespace std;

void Menu::ejecutar(){
    int opcion;

    while(true){
        system("cls");
        menuPrincipal();//Muestra el menu principal
        opcion = leerEntero();

        switch(opcion){
            case 1:
                menuClientes();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                system("cls");
                cout<<"Saliendo del programa..."<<endl;
                return;
            default:
                cout<<"Opci¢n incorrecta."<<endl;
                break;
        }
        system("pause");
    }
}

void Menu::menuPrincipal(){
    cout << "================================" << endl;
    cout << "          Menu Principal        " << endl;
    cout << "================================" << endl;
    cout << " 1. Clientes" << endl;
    cout << " 2. Peliculas" << endl;
    cout << " 3. Salas" << endl;
    cout << " 4. Ventas" << endl;
    cout << " 5. Reportes"<<endl;
    cout << " 0. Salir" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
}

void Menu::menuClientes(){
    int opcion;

    while(true){
        system("cls");
        cout << "================================" << endl;
        cout << "         Menu Clientes          " << endl;
        cout << "================================" << endl;
        cout << " 1. Cargar" << endl;
        cout << " 2. Buscar" << endl;
        cout << " 3. Modificar" << endl;
        cout << " 4. Eliminar" << endl;
        cout << " 5. Restaurar" << endl;
        cout << " 6. Listar" << endl;
        cout << " 0. Volver al Menu Principal" << endl;
        cout << "================================" << endl;
        cout << "Opcion: ";

        opcion= leerEntero();

        switch(opcion){
            case 1:
                _managerCliente.cargar();
                break;
            case 2:
                _managerCliente.buscar();
                break;
            case 3:
                _managerCliente.modificar();
                break;
            case 4:
                _managerCliente.eliminar();
                break;
            case 5:
                _managerCliente.restaurar();
                break;
            case 6:
                _managerCliente.mostrarTodos();
                break;
            case 0:
                return;
            default:
                cout<<"Opci¢n incorrecta."<<endl;
                break;
        }
        system("pause");
    }

}

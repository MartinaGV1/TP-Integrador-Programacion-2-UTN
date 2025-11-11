#include <iostream>
#include <cstring>
#include "SalaManager.h"
#include "funcionesGlobales.h"

using namespace std;

void SalaManager::cargar(){
    system("cls");
    Sala obj;

    if(cargarSala(obj)){
        if(_archivoS.guardar(obj)){
            cout << "Sala cargada correctamente." << endl;
        } else {
            cout << "Error al guardar la sala." << endl;
        }
    }
    system("pause");
}

bool SalaManager::cargarSala(Sala &obj){
    int id= _archivoS.asignarID();
    obj.setIDSala(id);
    cout<<"ID asginado: "<<id<<endl;

    char nombre[30];
    cout<<"Nombre de la sala: ";
    cargarCadena(nombre, 30);
    obj.setNombreSala(nombre);

    cout << "Tipo de sala:" << endl;
    cout << " 1) Est ndar" << endl;
    cout << " 2) Premium" << endl;
    cout << " 3) Comfort Plus" << endl;
    cout << "Opci¢n: ";
    int tipo = leerEntero();

    while(tipo < 1 || tipo > 3){
        cout << "Opci¢n inv lida, intente de nuevo: ";
        tipo = leerEntero();
    }
    obj.setTipoSala(tipo);

    cout << "Capacidad de la sala: ";
    int capacidad = leerEntero();

    while(capacidad<10 || capacidad>500){
        cout << "La capacidad invalida. Reingrese: ";
        int capacidad = leerEntero();
    }
    obj.setCapacidadSala(capacidad);

    obj.setEstado(true);
    return true;
}

void SalaManager::mostrarSala(Sala &obj){
    cout << "--------------------------------" << endl;
    cout << "ID Sala: " << obj.getIDSala() << endl;
    cout << "Nombre: " << obj.getNombreSala() << endl;

    cout << "Tipo: ";
    switch(obj.getTipoSala()){
        case 1: cout << "Est ndar"; break;
        case 2: cout << "Premium"; break;
        case 3: cout << "Comfort Plus"; break;
    }
    cout << endl;
    cout << "Capacidad: " << obj.getCapacidadSala() << endl;
    cout << "--------------------------------" << endl;
}


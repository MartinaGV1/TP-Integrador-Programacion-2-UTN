#include <iostream>
#include <cstring>
#include "PeliculaManager.h"
#include "funcionesGlobales.h"

using namespace std;

void PeliculaManager::cargar(){
    system("cls");

    Pelicula nueva;

    if(!cargarPelicula(nueva)) return;

    if(_archivoP.guardar(nueva)){
        cout<<"Pelicula cargada exitosamente."<<endl;
    }else{
        cout<<"Error al guardar la pelicula."<<endl;
    }
}

bool PeliculaManager::cargarPelicula(Pelicula &obj){
    int id;
    cout<<"ID: ";
    id = leerEntero();

    if(_archivoP.buscarPorID(id) != -1){
        cout<<"Ya existe una pelicula con ese ID"<<endl;
        return false;
    }
    obj.setIDPelicula(id);

    char nombre[50];
    cout << "Nombre de la pel¡cula: ";
    do{
        cargarCadena(nombre, 50);
        if (!sonLetras(nombre)){
            cout<<"El nombre tiene que tener letras. Intente de nuevo: ";
        }

    } while (!sonLetras(nombre));
    obj.setNombrePelicula(nombre);

    char director[60];
    cout << "Director: ";
    do{
        cargarCadena(director, 50);
        if (!sonLetras(director)){
            cout<<"El nombre tiene que tener letras. Intente de nuevo: ";
        }

    } while (!sonLetras(director));
    obj.setNombreDirector(director);

    char genero[50];
    cout<<"Genero: ";
    do{
        cargarCadena(genero, 50);
        if (!sonLetras(genero)){
            cout<<"El nombre tiene que tener letras. Intente de nuevo: ";
        }

    } while (!sonLetras(genero));
    obj.setNombrePelicula(genero);

    int clasificacion;
    do{
        cout << "\nClasificacion:"<<endl;;
        cout << " 1) ATP\n";
        cout << " 2) +13\n";
        cout << " 3) +18\n";
        cout << "Opcion: ";
        clasificacion=leerEntero();

        cout << "Opcion invalida. Intente de nuevo."<<endl;

    }while(clasificacion <1 || clasificacion >3);
    obj.setClasificacion(clasificacion);

    Fecha fecha;
    cout<<"Fecha de estreno: ";
    fecha.cargar();
    obj.setFechaEstreno(fecha);

    obj.setEstado(true);
    return true;

}

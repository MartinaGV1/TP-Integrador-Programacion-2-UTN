#pragma once
#include "PeliculaArchivo.h"

class PeliculaManager {
    private:
        PeliculaArchivo _archivoP;

    public:
        //void menu();
        bool cargarPelicula(Pelicula &obj);
        void cargar();
        void mostrarTodas();
        void buscarPorID();
        void modificar();
        void eliminar();
};

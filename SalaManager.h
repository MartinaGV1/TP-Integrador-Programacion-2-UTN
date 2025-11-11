#pragma once
#include "Sala.h"
#include "SalaArchivo.h"

class SalaManager {
private:
    SalaArchivo _archivoS;

    bool cargarSala(Sala &obj);
    void mostrarSala(Sala &obj);

    void buscarPorID();
    void buscarPorNombre();

public:
    void cargar();
    void mostrarTodos();
    void buscar();
    void modificar();
    void eliminar();
    void restaurar();
};

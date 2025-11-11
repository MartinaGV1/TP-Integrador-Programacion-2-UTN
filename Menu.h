#pragma once
#include "ClienteManager.h"
#include "PeliculaManager.h"

class Menu{
    private:
        ClienteManager _managerCliente;
        PeliculaManager _managerPelicula;

        void menuPrincipal();
        void menuClientes();
        void menuPeliculas();
        void menuSalas();
        void menuVentas();

    public:
        void ejecutar();
};

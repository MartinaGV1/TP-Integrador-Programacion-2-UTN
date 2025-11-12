#pragma once
#include "ClienteManager.h"
#include "PeliculaManager.h"
#include "SalaManager.h"

class Menu{
    private:
        ClienteManager _managerCliente;
        PeliculaManager _managerPelicula;
        SalaManager _managerSala;

        void menuPrincipal();
        void menuClientes();
        void menuPeliculas();
        void menuSalas();
        void menuVentas();

    public:
        void ejecutar();
};

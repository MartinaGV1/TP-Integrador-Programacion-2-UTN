#pragma once
#include "ClienteManager.h"

class Menu{
    private:
        ClienteManager _managerCliente;

        void menuPrincipal();
        void menuClientes();
        void menuPeliculas();
        void menuSalas();
        void menuVentas();

    public:
        void ejecutar();
};

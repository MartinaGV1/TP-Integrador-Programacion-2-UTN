#pragma once
#include "Fecha.h"

class Venta {
    private:
        int _idVenta;
        int _idPelicula;
        int _idSala;
        int _cantEntradas;
        float _importeTotal;
        Fecha _fechaProyeccion;
        char _dniComprador[9];
        bool _estado;

    public:
        Venta();

        //setters
        void setIDVenta(int idVenta);
        void setIDPelicula(int idPelicula);
        void setIDSala(int idSala);
        // El importe se calcula automaticamente al fijar la cantidad y el precio
        void setCantEntradas(int cantEntradas);
        void setFechaProyeccion(Fecha fechaP);
        void setDNIComprador(const char *dniComprador);
        void setEstado(bool estado);

        //getters
        int getIDVenta();
        int getIDPelicula();
        int getIDSala();
        int getCantEntradas();
        float getImporteTotal();
        Fecha getFechaProyeccion();
        const char* getDNIComprador();
        bool getEstado();
};

#ifndef VENTA_H_INCLUDED
#define Venta_H_INCLUDED
#include "Fecha.h"

class Venta {
    private:
        int idVenta;
        int idPelicula;
        int idSala;
        int cantEntradas;
        float importeTotal;
        Fecha fechaProyeccion;
        char dniComprador[9];
        bool estado;

    public:
        void Cargar();
        void Mostrar();

        //setters
        void setIDVenta(int idV);
        void setIDPelicula(int idP);
        void setIDSala(int idS);
        void setCantEntradas(int cantE);
        //(el importe total deberia cambiar automaticamente al modificar la cantidad de entradas)
        //void calcularImporteTotal();
        void setFechaProyeccion(Fecha fechaP);
        void setDNIComprador(char comprador);
        void setEstado(bool est);

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

#endif // VENTA_H_INCLUDED

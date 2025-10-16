#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#include "Fecha.h"

class Pelicula {
    private:
        int idPelicula;
        int clasificacion;
        char nombrePelicula[50];
        char nombreDirector[50];
        char genero[50];
        Fecha fechaEstreno;
        bool estado;

    public:
        void Cargar();
        void Mostrar();

        //setters
        void setIDPelicula(int idP);
        void setClasificacion(int clasif);
        void setNombrePelicula(const char *nombreP);
        void setNombreDirector(const char *direc);
        void setGenero(const char *genre);
        void setFechaEstreno(Fecha fechaE);
        void setEstado(bool est);

        //getters
        int getIDPelicula();
        int getClasificacion();
        const char* getNombrePelicula();
        const char* getNombreDirector();
        const char* getGenero();
        Fecha getFechaEstreno();
        bool getEstado();
};

#endif // PELICULAS_H_INCLUDED

#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#include "Fecha.h"

class Pelicula {
    private:
        int _idPelicula;
        int _clasificacion;
        char _nombrePelicula[50];
        char _nombreDirector[50];
        char _genero[50];
        Fecha _fechaEstreno;
        bool _estado;

    public:
        void Cargar();
        void Mostrar();

        //setters
        void setIDPelicula(int idPeli);
        void setClasificacion(int clasificacion);
        void setNombrePelicula(const char *nombrePeli);
        void setNombreDirector(const char *nombreDirector);
        void setGenero(const char *genero);
        void setFechaEstreno(Fecha fechaEstreno);
        void setEstado(bool estado);

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

#include <iostream>
#include <cstring>      //necesario para strncpy
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() {
    _idPelicula = 0;
    _clasificacion = 0;
    _nombrePelicula[0] = '\0';
    _nombreDirector[0] = '\0';
    _genero[0] = '\0';
    _estado = false;
}

// Setters
void Pelicula::setIDPelicula(int idPeli) {
    _idPelicula = idPeli;
}

void Pelicula::setClasificacion(int clasificacion) {
    _clasificacion = clasificacion;
}

void Pelicula::setNombrePelicula(const char *nombrePeli) {
    strncpy(_nombrePelicula, nombrePeli, sizeof(_nombrePelicula) - 1);
}

void Pelicula::setNombreDirector(const char *nombreDirector) {
    strncpy(_nombreDirector, nombreDirector, sizeof(_nombreDirector) - 1);
}

void Pelicula::setGenero(const char *genero) {
    strncpy(_genero, genero, sizeof(_genero) - 1);
}

void Pelicula::setFechaEstreno(Fecha fechaEstreno) {
    _fechaEstreno = fechaEstreno;
}

void Pelicula::setEstado(bool estado) {
    _estado = estado;
}


// Getters
int Pelicula::getIDPelicula() {
    return _idPelicula;
}

int Pelicula::getClasificacion() {
    return _clasificacion;
}

const char* Pelicula::getNombrePelicula() {
    return _nombrePelicula;
}

const char* Pelicula::getNombreDirector() {
    return _nombreDirector;
}

const char* Pelicula::getGenero() {
    return _genero;
}

Fecha Pelicula::getFechaEstreno() {
    return _fechaEstreno;
}

bool Pelicula::getEstado() {
    return _estado;
}

#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() {
    _dni[0] = '\0';
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _email[0] = '\0';
    _telefono[0] = '\0';
    _estado = false;
}

// Setters
void Cliente::setDNI(const char *dni) {
    strncpy(_dni, dni, sizeof(_dni) - 1);
    //_dni[8] = '\0';
}

void Cliente::setNombre(const char *nombre) {
    strncpy(_nombre, nombre, sizeof(_nombre) - 1);
}

void Cliente::setApellido(const char *apellido) {
    strncpy(_apellido, apellido, sizeof(_apellido) - 1);
}

void Cliente::setEmail(const char *mail) {
    strncpy(_email, mail, sizeof(_email) - 1);
}

void Cliente::setTelefono(const char *telefono) {
    strncpy(_telefono, telefono, sizeof(_telefono) - 1);
}

void Cliente::setEstado(bool estado) {
    _estado = estado;
}

// Getters
const char* Cliente::getDNI() { return _dni; }
const char* Cliente::getNombre() { return _nombre; }
const char* Cliente::getApellido() { return _apellido; }
const char* Cliente::getEmail() { return _email; }
const char* Cliente::getTelefono() { return _telefono; }
bool Cliente::getEstado() { return _estado; }

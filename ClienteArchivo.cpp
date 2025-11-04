#include <iostream>
#include <cstring>
#include <cstdio>
#include "ClienteArchivo.h"
#include "Cliente.h"

using namespace std;

ClienteArchivo::ClienteArchivo(const char* nombreArchivo) {
    strncpy(_nombreArchivo, nombreArchivo, sizeof(_nombreArchivo) - 1);
}

bool ClienteArchivo::guardar(Cliente& obj) {
    FILE *p;
    p = fopen(_nombreArchivo, "ab");

    if (p == nullptr) { return false; }

    bool escribio = fwrite(&obj, sizeof(Cliente), 1, p);
    fclose(p);

    return escribio;
}

bool ClienteArchivo::modificar(Cliente& obj, int pos) {
    FILE *p;
    p = fopen(_nombreArchivo, "rb+");

    if (p == nullptr) { return false; }

    fseek(p, pos * sizeof(Cliente), SEEK_SET);

    // Escribe el objeto modificado
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, p);
    fclose(p);

    return escribio;
}

bool ClienteArchivo::leer(Cliente &obj, int pos) {
    FILE *p;
    p = fopen(_nombreArchivo, "rb");

    if (p == nullptr) { return false; }

    fseek(p, pos * sizeof(Cliente), SEEK_SET);

    bool leyo = fread(&obj, sizeof(Cliente), 1, p);
    fclose(p);

    return leyo;
}

int ClienteArchivo::contarRegistros() {
    FILE *p;
    p = fopen(_nombreArchivo, "rb");

    if (p == nullptr) { return false; }

    fseek(p, 0, SEEK_END); // Mueve el puntero al final del archivo
    int tam = ftell(p);
    fclose(p);

    return tam / sizeof(Cliente);
}

int ClienteArchivo::buscarPorDNI(const char* dni) {
    int total = contarRegistros();

    Cliente obj;

    for (int i = 0; i < total; i++) {
        if (leer(obj, i)) {
            if (strcmp(obj.getDNI(), dni) == 0) {// Compara el dni del registro con el dni buscado
                return i; //retorna la posicion
            }
        }
    }

    return -1; //si no lo encontro retorna -1
}

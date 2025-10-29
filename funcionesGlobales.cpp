#include <iostream>
#include <cstring> // Necesario para strlen()
#include "funcionesGlobales.h"

using namespace std;

void cargarCadena(char *palabra, int tam) {
    do {
        cin.getline(palabra, tam);

        if (strlen(palabra) == 0) { // Valida si la cadena est  vac¡a
            cout << "Error, no puede estar vacio. Intente de nuevo: ";
        }
    } while (strlen(palabra) == 0); // Repite el bucle si la cadena est  vac¡ia
}

bool sonNumeros(const char *cadena) {

    //Si el caracter es menor que '0' o mayor que '9' entonces no es un n£mero
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return false; // retorna falso si no es numero
        }
    }
    return true; //retorna true si son solo numeros
}


bool sonLetras(const char *cadena) {

    for (int i = 0; cadena[i] != '\0'; i++) {

        char c = cadena[i];//obttiene el caracter acutual

        bool mayuscula = (c >= 'A' && c <= 'Z');
        bool minuscula = (c >= 'a' && c <= 'z');
        bool espacio = (c == ' ');

        // Si no es mayuscula, min£scula y no  es un espacio, entonces es inv lido

        if (!mayuscula && !minuscula && !espacio) {
            return false; //retorna falso si no cumple con lo anterior
        }
    }
    return true; //retorna true si se cumple con todo
}

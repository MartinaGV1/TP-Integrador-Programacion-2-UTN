#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio) {
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

void Fecha::Cargar() {
    cout << "  Dia: ";
    cin >> _dia;
    cout << "  Mes: ";
    cin >> _mes;
    cout << "  Anio: ";
    cin >> _anio;
}

void Fecha::Mostrar() {
    cout << _dia << "/" << _mes << "/" << _anio;
}

bool Fecha::esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    }
    return false;
}

bool Fecha::esFechaValida() {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (_anio < 1900 || _mes < 1 || _mes > 12) {
        return false;
    }

    if (_mes == 2 && esBisiesto(_anio)) {
        diasPorMes[2] = 29;
    }

    if (_dia < 1 || _dia > diasPorMes[_mes]) {
        return false;
    }

    return true;
}

//setters
void Fecha::setDia(int dia) {
    _dia = dia;
}

void Fecha::setMes(int mes) {
    _mes = mes;
}

void Fecha::setAnio(int anio) {
    _anio = anio;
}

//getters
int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

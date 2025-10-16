#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int d = 0, int m = 0, int a = 0);
        void Cargar();
        void Mostrar();

        //setters
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        //getters
        int getDia();
        int getMes();
        int getAnio();
};


#endif // FECHA_H_INCLUDED

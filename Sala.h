#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

class Sala {
    private:
        int _idSala;
        int _tipoSala;
        int _capacidadSala;
        char _nombreSala[30];
        bool _estado;

    public:
        void Cargar();
        void Mostrar();

        //setters
        void setIDSala(int idS);
        void setTipoSala(int tipoS);
        void setCapacidadSala(int capS);
        void setNombreSala(const char *nombreS);

        //getters
        int getIDSala();
        int getTipoSala();
        int getCapacidadSala();
        const char* getNombreSala();
        bool getEstado();
};

#endif // SALA_H_INCLUDED

#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

class Sala {
    private:
        int idSala, tipoSala, capacidadSala;
        char nombreSala[30];
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
        char getNombreSala();
};

#endif // SALA_H_INCLUDED

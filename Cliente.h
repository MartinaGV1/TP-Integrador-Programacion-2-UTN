#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente{
    private:
        char dni[9];
        char nombre[30];
        char apellido[30];
        char email[30];
        char telefono[12];
        bool estado;

    public:
        void Cargar();
        void Mostrar();

        //setters
        void setDNI(const char *dni);
        void setNombre(const char *nom);
        void setApellido(const char *ap);
        void setEmail(const char *mail);
        void setTelefono(const char *tel);
        void setEstado(bool est);

        //getters
        const char* getDNI();
        const char* getNombre();
        const char* getApellido();
        const char* getEmail();
        const char* getTelefono();
        bool getEstado();
};

#endif // CLIENTES_H_INCLUDED

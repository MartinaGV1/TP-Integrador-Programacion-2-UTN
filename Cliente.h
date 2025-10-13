#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente{
    private:
        char dni[9], nombre[30], apellido[30], email[30], telefono[12];
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
        //getters
        char getDNI();
        char getNombre();
        char getApellido();
        char getEmail();
        char getTelefono();
        bool getEstado();
};

#endif // CLIENTES_H_INCLUDED

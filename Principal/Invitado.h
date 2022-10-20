#include <string>
#include <iostream>

using namespace std;

class invitado{
    public:
        string nickname;
        string pwd;
        int rol;
};

class usuario : public invitado{
   public:
        int resultado_loguin;
        int resultado_registro;
        string ganador;
        
        bool cargar_datos();
        void cargartablero();

   private:
        void cargar_invitado();
        bool validar_usuario();
        
};

class administrador : public invitado{
   public:
        string lista_archivos;
};
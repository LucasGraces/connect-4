#include <string>
#include <iostream>
using namespace std;

class invitado{
    public:
        string nickname;
        string pwd;
        int rol;
};

class Usuario : public invitado{
   public:
     int resultado_loguin;
     int resultado_registro;
     int resul_vali;
     int validar_ingreso;
     string ganador;

     bool cargar_datos();
     void cargartablero(char tablero[]);
     bool validar_usuario(int opcion);

   private:
     void cargar_invitado();
};

class Administrador : public invitado{
   public:
        string lista_archivos;
};
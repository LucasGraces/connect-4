#include <string>
#include <iostream>

using namespace std;

class Archivo{
    public:
        string nickname;
        string pwd;
        string rol;
        int ganada1;
        int ganada2;
        int ganada3;
        int ganada4;
        
        int registrar_usuario(string nick, string pass); //Metodo para grabar tanto el nickname y la contraseña en el archivo.
        int buscar_usuario(string nick, string pass);
        string buscar_disponibles();
        void cargar_archivo();
    
};
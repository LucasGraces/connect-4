#include <string>
#include <iostream>

using namespace std;

class Archivo{
    public:
        string nickname;
        string pwd;
        string rol;
        
        int registrar_usuario(string nick, string pass); //Metodo para grabar tanto el nickname y la contraseña en el archivo.
        int buscar_usuario(string nick, string pass);
        string buscar_disponibles();
        void cargar_archivo();
    
};
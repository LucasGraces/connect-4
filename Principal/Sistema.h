#include <string>
#include <iostream>

using namespace std;

class Sistema{
    public:
        bool aprendizaje;
        
        string visualizar_archivos();
        bool elegir_archivo(string nombre);
        bool generar(string nombre);
    
    private:
        void setear_archivo(string nombre);

};
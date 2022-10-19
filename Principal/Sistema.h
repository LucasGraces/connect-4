#include <string>
#include <iostream>

using namespace std;

class Sistema{
    public:
        bool aprendizaje;
        
        int visualizar_archivos();
        string elegir_archivo();
        bool generar(string nombre);
    
    private:
        void setear_archivo();

};
#include <string>
#include <iostream>
#include "Sistema.h"
#include "Archivo.h"
#include "Invitado.h"

using namespace std;

string Sistema::visualizar_archivos(){
    Archivo archi;
    return archi.buscar_disponibles();
};

bool Sistema::elegir_archivo(string nombre){
    bool resultado = true;

    

    return resultado;
};

bool Sistema::generar(string nombre){

};

void Sistema::setear_archivo(){
    
};

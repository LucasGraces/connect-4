#include <string>
#include <iostream>
#include <fstream>
#include "Sistema.h"
#include "Archivo.h"
#include "Invitado.h"

using namespace std;

string Sistema::visualizar_archivos(){
    Archivo archi;
    string resultado;

    resultado = archi.buscar_disponibles();

    return resultado; 
};

bool Sistema::elegir_archivo(string nombre){
    bool resultado = true;

    

    return resultado;
};

bool Sistema::generar(string nombre){
    bool resultado = false;

    string nombre2 = nombre + ".txt";

    ofstream archivo;
    archivo.open(nombre2,ios::trunc);

    if(!archivo.fail()){
        resultado = true;
        setear_archivo(nombre);
    }
    else{
        resultado = false;
    }

    archivo.close();
    return resultado;
};

void Sistema::setear_archivo(string nombre){
    string nombre2 = nombre + ".txt";
        
    ofstream archivo;
    archivo.open("nom_archivos.txt", ios::app);

    archivo<<nombre2 + "\n";
    
};

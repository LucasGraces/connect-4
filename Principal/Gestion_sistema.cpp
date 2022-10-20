#include <string>
#include <iostream>
#include <fstream>
#include "Gestion_sistema.h"
#include "administrador.h"

using namespace std;


bool Gestion_sistema::crear_archivo(){
    bool resultado = false;
    administrador admin;
    string nombre = admin.nom_archivo + ".txt";

    ofstream archivo;
    archivo.open(nombre,ios::trunc);

    if(!archivo.fail()){
        resultado = true;
        cargar_list_archivos();
    }
    else{
        resultado = false;
    }

    archivo.close();
    return resultado;
};

void Gestion_sistema::cargar_list_archivos(){
    if(crear_archivo() == true){
        administrador admin;
        string nombre = admin.nom_archivo + ".txt";
        
        ofstream archivo;
        archivo.open("nom_archivos.txt", ios::app);

        archivo<<nombre + "\n";
    }
};
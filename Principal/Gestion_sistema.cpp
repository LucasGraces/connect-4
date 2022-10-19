#include <string>
#include <iostream>
#include <fstream>
#include "Gestion_sistema.h"
#include "administrador.h"

using namespace std;

string Gestion_sistema::mostras_partidas(){
    string linea;
    string resultado;

    ifstream archivo;
    archivo.open("nom_archivos.txt", ios::in);

    while(!archivo.eof()){
        getline(archivo,linea);
        resultado = resultado + linea + "\n";
    }

    archivo.close();
    return resultado;
};

bool Gestion_sistema::prepara_archivo(){
    bool resultado = true;
    administrador admin;

    admin.num_archivo = archivo_acargar;

    return resultado;
};

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
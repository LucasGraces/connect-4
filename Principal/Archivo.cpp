#include <string>
#include <iostream>
#include <fstream>
#include "Archivo.h"
#include "Invitado.h"

using namespace std;

int Archivo::buscar_usuario(){
    int estado = 0;
    
    usuario usu;

    string contenido;
    string contenido2;
    Archivo archi;
    ifstream Archivo;
    ifstream Archivo2;

    Archivo.open("nickname_us.txt", ios::in);
    Archivo2.open("contraseñas_us.txt", ios::in);

    Archivo >> contenido;
    Archivo2 >> contenido2;

    if(usu.cargar_datos() == true){
        if(contenido == usu.nickname and contenido2 == usu.pwd){
            estado = 3;
            return estado;
        }
        else if(contenido2 != usu.pwd and contenido == usu.nickname){
            estado = 1;
        }
        else if(contenido != usu.nickname and contenido2 == usu.pwd){
            estado = 2;
        }
    }
    Archivo.close();
    Archivo2.close();
    return estado;
};

int Archivo::registrar(string nom_us, string password){
    int estado = 0;
    
    validar vali;
    ifstream fs("nickname_us.txt");
    string contenido;
    
    fs >> contenido;
    
    if(vali.validar_datos(nom_us,password) == false){
        estado = 3;
    }
    else if(contenido == nom_us){ 
        estado = 2;
    }
    else{
        ofstream archivo;
        ofstream archivo1;

        archivo.open("contraseñas_us.txt",ios::app);
        archivo<<password + "\n";

        archivo1.open("nickname_us.txt",ios::app);
        archivo1<<nom_us + "\n";
        
        estado = 1;
        archivo.close();
    }
    fs.close();
    return estado;
};
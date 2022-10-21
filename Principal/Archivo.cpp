#include <string>
#include <iostream>
#include <fstream>
#include "Archivo.h"
#include "Invitado.h"

using namespace std;

int Archivo::buscar_usuario(){
    int estado = 0;
    string contenido;
    string contenido2;

    Usuario usu;

    ifstream Archivo;
    ifstream Archivo2;

    Archivo.open("nickname_us.txt", ios::in);
    Archivo2.open("contraseñas_us.txt", ios::in);

    Archivo >> contenido;
    Archivo2 >> contenido2;
    cout<<"N "<<usu.nickname<<endl;
    cout<<"P "<<usu.pwd<<endl;
    if(contenido == usu.nickname and contenido2 == usu.pwd){
        estado = 3;
    }
    else if(contenido2 != usu.pwd and contenido == usu.nickname){
        estado = 1;
    }
    else if(contenido != usu.nickname and contenido2 == usu.pwd){
        estado = 2;
    }
    
    Archivo.close();
    Archivo2.close();
    return estado;
};

int Archivo::registrar_usuario(string nick, string pass){
    int estado = 0;

    ifstream fs("nickname_us.txt");
    string contenido;
    
    fs >> contenido;
    
    if(buscar_usuario() == 3){
       estado = 4;
    }
    else{
        ofstream archivo;
        ofstream archivo1;

        archivo.open("password_us.txt",ios::app);
        archivo<<pass + "\n";

        archivo1.open("nickname_us.txt",ios::app);
        archivo1<<nick + "\n";
        
        estado = 1;
        archivo.close();
    }
    fs.close();
    return estado;
};

string Archivo::buscar_disponibles(){
    string resultado;

    string linea;

    ifstream archivo;
    archivo.open("nom_archivos.txt", ios::in);

    while(!archivo.eof()){
        getline(archivo,linea);
        resultado = resultado + linea + "\n";
    }

    archivo.close();
    return resultado;
};
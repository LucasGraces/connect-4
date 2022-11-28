#include <string>
#include <iostream>
#include <fstream>
#include "Archivo.h"
#include "Invitado.h"

using namespace std;

int Archivo::buscar_usuario(string nick, string pass){
    int estado = 0;
    string contenido;
    string contenido2;

    ifstream Archivo;
    ifstream Archivo2;

    Archivo.open("nickname_us.txt", ios::in);
    Archivo2.open("password_us.txt", ios::in);

    Archivo >> contenido;
    Archivo2 >> contenido2;

    if(contenido == nick and contenido2 == pass){
        estado = 3;
    }
    else if(contenido2 != pass and contenido == nick){
        estado = 1;
    }
    else if(contenido != nick and contenido2 == pass){
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
    
    if(buscar_usuario(nick,pass) == 3){
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

void Archivo::cargar_archivo(){
    ofstream archivo;
   bool resultado = false;
   archivo.open("jugadas_ia.txt",ios::app);
   archivo<<ganada1;
   archivo<<" ";
   archivo<<ganada2;
   archivo<<" ";
   archivo<<ganada3;
   archivo<<" ";
   archivo<<ganada4;
   archivo<<"\n";

   if(archivo.fail()){
      resultado = false;
   }
   resultado = true;

   archivo.close();
};
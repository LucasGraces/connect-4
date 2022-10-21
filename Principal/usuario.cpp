#include <string>
#include <iostream>
#include <fstream>
#include "Invitado.h"
#include "Gestor_juego.h"

using namespace std;

bool Usuario::cargar_datos(){
    bool resultado = true;

    if(validar_usuario() == true){
        resultado = true;
    }
    else{
        resultado = false;
    }
    return resultado;
};

bool Usuario::validar_usuario(){
    bool resultado = false;

    if(nickname.length() >= 8){
        resultado = true;
    }
    else{

        resultado = false;
    }
    if(pwd.length() >= 8){
        for(int i=0; i < pwd.length(); i++){
            char a = pwd[i];
			int letra = (int)a;
            if(letra >= 65 || letra <= 90 || (letra >= 97 && letra <= 122) || letra == 32 || letra == 95){
                resultado=true;
            }
        }
    }
    else{
        resultado = false;
    }
    return resultado;
};

void Usuario::cargar_invitado(){
    Usuario usu;

    string jugador_1;
    string jugador_2;

    jugador_1 = usu.nickname;
};

void Usuario::cargartablero(){
    cargar_invitado();
    Gestor_juego gs;

    int col=0;

   for(int l = 0; l < 42 ;l++){
      cout<<"| "<<gs.tablero[l];
      col++;
  
      if(col==7) {
         col=0;
         cout<<" |"<<endl;
      }
   }
};
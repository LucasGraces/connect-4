#include <string>
#include <iostream>
#include <fstream>
#include "Invitado.h"
#include "Gestor_juego.h"
#include "Archivo.h"

using namespace std;

bool Usuario::cargar_datos(){

};

bool Usuario::validar_usuario(int opcion){
    // Si la opcion es igual 1 es para ver si esta logueado, 2 si es para registrar.
    bool resultado = false;
    bool bandera = false;
    
    Archivo archi;
    
    if(nickname.length() >= 8 and pwd.length() >= 8 and nickname != "" and pwd != ""){
        for(int i = 0; i < pwd.length(); i++){
            char a = pwd[i];
            int letra = (int)a;
            if(letra >= 65 || letra <= 90 || (letra >= 97 && letra <= 122) || letra == 32 || letra == 95){
                resultado = true;
                bandera = true;
            }
        }
        if(bandera == true){
            if(opcion == 1){
                resul_vali = archi.buscar_usuario(nickname, pwd);
            }
            else{
                resul_vali = archi.registrar_usuario(nickname, pwd);
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

void Usuario::cargartablero(char tablero[]){
    int col=0;

   for(int l = 0; l < 42 ;l++){
      cout<<"| "<<tablero[l];
      col++;
  
      if(col == 7) {
         col = 0;
         cout<<" |"<<endl;
      }
   }
};
#include <string>
#include <iostream>
#include "Gestor_juego.h"

using namespace std;

bool Gestor_juego::verificar_victoria(){
    bool resultado = false;
    
    for(int i = 0; i < 294; i = i + 4){
        if(tablero[lineas[i]] == tablero[lineas[i + 1]]
        && tablero[lineas[i]] == tablero[lineas[i + 2]]
        && tablero[lineas[i]] == tablero[lineas[i + 3]]
        && tablero[lineas[i]] != '\0'){
            resultado = true;
      }   
   }
   return resultado;
};

int Gestor_juego::jugar_ficha(int colum){
    int o;
   int l;
   ficha--;
   bool flag = false;
   bool fla = false;

   if(jugadores == true){
      for( o = ficha; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o-7] = 'X'; 
            flag=true;
            break;
         }
      }
      if(flag==false){
         tablero[35+ficha]='X';
      }

   } 
  if(jugadores == false){
     for( l = ficha; l < 42; l = l + 7){
         if(tablero[l] != '\0'){
            tablero[l-7] = 'O'; 
            fla=true;
            break;
         }
      }
      if(fla == false){
         tablero[35+ficha] = 'O';
      }
   } 
};
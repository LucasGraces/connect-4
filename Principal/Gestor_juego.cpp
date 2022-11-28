#include <string>
#include <iostream>
#include "Gestor_juego.h"
#include "Archivo.h"
using namespace std;

bool Gestor_juego::verificar_victoria(){
   Archivo ar;
    bool resultado = false;

    for(int i = 0; i < 294; i = i + 4){
        if(tablero[lineas[i]] == tablero[lineas[i + 1]]
        && tablero[lineas[i]] == tablero[lineas[i + 2]]
        && tablero[lineas[i]] == tablero[lineas[i + 3]]
        && tablero[lineas[i]] != '\0'){
         ar.ganada4 = lineas[i];
         ar.ganada3 = lineas[i + 1];
         ar.ganada2 = lineas[i + 2];
         ar.ganada1 = lineas[i + 3];
         resultado = true;
      }   
   }
   return resultado;
};

int Gestor_juego::jugar_ficha(int colum, bool jugadores, char tablero[]){
   int o;
   int l;
   colum--;
   bool flag = false;
   bool fla = false;

   if(jugadores == true){
      for( o = colum; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o - 7] = 'X'; 
            flag = true;
            break;
         }
      }
      if(flag==false){
         tablero[35 + colum] = 'X';
      }

   } 
  if(jugadores == false){
     for( l = colum; l < 42; l = l + 7){
         if(tablero[l] != '\0'){
            tablero[l - 7] = 'O'; 
            fla = true;
            break;
         }
      }
      if(fla == false){
         tablero[35 + colum] = 'O';
      }
   } 
};

void Gestor_juego::setear_tablero(char tablero[]){
   for(int i = 0; i < 42; i++){ 
      tablero[i] = 0;
   }
};

int Gestor_juego::juego_ia(int colum, bool jugadores, char tablero[]){
   int i;
   int o;
   colum--;
   bool flag = false;
   bool fla = false;
   if(jugadores == true){
     for( o = colum; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o - 7] = 'X';
            fla = true;
            break;
        }                             // JUEGA EL JUGADOR
      }
      if(fla==false){
         tablero[35 + colum] = 'X';
        }
   }
   if(jugadores == false){
      for(i = 0 ;i < numeros.size() ; i = i + 4){
         if(tablero[numeros[i]] == tablero[numeros[i + 1]]
            && tablero[numeros[i]] == tablero[numeros[i + 2]] ){  // Trata de ganar y e
            tablero[numeros[i + 3]] = 'O';
         }
      }
   }
   else{
         // Pone la ficha en un lugar aleatorio
         int b;
         b = 1 + rand() % 8; //genera un numero entre 1 y 7
         int posicion = b;
         for( int j = posicion; j < 42; j = j + 7){
            if(tablero[j] != '\0'){
               tablero[j - 7] = 'O'; 
               flag = true;            //ESTE YA FUNCIONA
               break;
            }
         }
         if(flag == false){
            tablero[35 + posicion] = 'O';
         }
      }
};

void Gestor_juego::archivo(){
   int resu;
   
   ifstream archivo("jugadas_ia.txt");

   while(archivo>>resu){
      numeros.push_back(resu);
   }

   archivo.close();
};

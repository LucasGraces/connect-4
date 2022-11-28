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
   int o;
   colum--;
   bool flag = false;
   bool fla = false;
   if(jugadores == true){
     for( o = colum; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o - 7] = 'X'; 
            flag = true;
            break;
         }                             // JUEGA EL JUGADOR
      }
      if(flag==false){
         tablero[35 + colum] = 'X';
      }
   }

   else if(jugadores == false){
      int largo = numeros.size();
      
      for(int i = 0 ;i < largo; i = i + 4 ){
         if(tablero[numeros[i]] = 'O'
            && tablero[numeros[i + 1]] == 'O'
            && tablero[numeros[i + 2]] == 'O'
            && tablero[numeros[i]] != '\0'){  // Trata de ganar
            
            if(tablero[numeros[i + 3]] + 7 != '\0'){
               tablero[numeros[i + 3]] == 'O';
            }
            else if(tablero[numeros[i+3]] + 7 == '\0'){
               int b;
               b = 1 + rand() % 8;
               colum = b;
               for( o = colum; o < 42; o = o + 7){
                  if(tablero[o] != '\0'){
                     tablero[o-7] = 'O'; 
                     flag=true;            //re
                     break;
                  }
               }
            }
         }
         else if(tablero[numeros[i]] = 'X'
            && tablero[numeros[i + 1]] == 'X'
            && tablero[numeros[i + 2]] == 'X'
            && tablero[numeros[i]] != '\0'){  // Evita que el contricante gane
            
            if(tablero[numeros[i+3]] + 7 != '\0'){
               tablero[numeros[i + 3]] == 'O';
            }
            else if(tablero[numeros[i+3]] + 7 == '\0'){
               int b;
               b = 1 + rand() % 8;
               colum = b;
               for( o = colum; o < 42; o = o + 7){
                  if(tablero[o] != '\0'){
                     tablero[o-7] = 'X'; 
                     flag=true;            
                     break;
                  }
               }
            }
         }
         else if(tablero[numeros[i]] == 'O' or tablero[numeros[i]] == '\0'
            && tablero[numeros[i+1]] == 'O' or tablero[numeros[i+1]] == '\0'
            && tablero[numeros[i+2]] == 'O' or tablero[numeros[i+2]] == '\0'
            && tablero[numeros[i+3]] == 'O' or tablero[numeros[i+3]] == '\0'){     // Trata de hacer una jugada
            
            
            if(tablero[numeros[i]] + 7 != '\0' and tablero[i + 7] == 'X'
               and tablero[numeros[i + 1]] + 7 != '\0' and tablero[i + 8] == 'X'
               and tablero[numeros[i + 2]] + 7 != '\0' and tablero[i + 9] == 'X'
               and tablero[numeros[i + 3]] + 7 != '\0' and tablero[i + 10] == 'X'){
               int a = rand() % 4; 
               tablero[numeros[i + a]] = 'O';
               break;
            }
            else{             // Pone la colum en un lugar aleatorio
               int b;
               b = 1 + rand() % 8; //genera un numero entre 1 y 7
               int posicion = b;
               for( int j = posicion; j < 42; j = j + 7){
                  if(tablero[j] != '\0'){
                     tablero[j - 7] = 'O'; 
                     flag = true;       
                     break;
                  }
               }
               if(flag == false){
                  tablero[35 + posicion] = '0';
               }
               break;
            }
            
         }
         else{
            // Pone la colum en un lugar aleatorio
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
               tablero[35 + posicion] = '0';
            }
         }
      
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

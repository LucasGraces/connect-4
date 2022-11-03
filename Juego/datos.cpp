#include <string>
#include <iostream>
#include <fstream>
#include "datos.h"
#include <vector>
#include <random>

using namespace std;

void Prueba::tablero_juego(){
   int col=0;
   int numeros[7] = {1,2,3,4,5,6,7};
   cout<<" ";
   for(int i=0; i< 7;i++){
      cout<<numeros[i];
      cout<<"  ";
   }
   cout<<"\n";
   for(int l = 0; l < 42 ;l++){
      cout<<"| "<<tablero[l];
      col++;
  
      if(col==7) {
         col=0;
         cout<<" |"<<endl;
      }
   }
};
bool Prueba::ver_ganador(){
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

void Prueba::agregarficha(bool jugadores){
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

void Prueba::archivo(){
   int resu;
   
   ifstream archivo("jugadas_ia.txt");

   while(archivo>>resu){
      numeros.push_back(resu);
   }

   archivo.close();
};

void Prueba::juego_ia(bool jugadores){
   
   int o;
   ficha--;
   bool flag = false;
   bool fla = false;
   if(jugadores == true){
     for( o = ficha; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o - 7] = 'X'; 
            flag = true;
            break;
         }                             // JUEGA EL JUGADOR
      }
      if(flag==false){
         tablero[35 + ficha] = 'X';
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
               ficha = b;
               for( o = ficha; o < 42; o = o + 7){
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
               ficha = b;
               for( o = ficha; o < 42; o = o + 7){
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
               cout<<"hola"<<endl;
               int a = rand() % 4; 
               tablero[numeros[i + a]] = 'O';
               break;
            }
            else{             // Pone la ficha en un lugar aleatorio
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
               tablero[35 + posicion] = '0';
            }
         }
      
      } 
   }
};

/*

         
*/
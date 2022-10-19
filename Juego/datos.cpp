#include <string>
#include <iostream>
#include <fstream>
#include "datos.h"
#include <vector>

using namespace std;

/*
void Prueba::tablero(){
   int numeros[7] = {1,2,3,4,5,6,7};
   int lista[7] = {0,0,0,0,0,0,0};
   int lista1[7] = {0,0,0,0,0,0,0};
   int lista2[7] = {0,0,0,0,0,0,0};
   int lista3[7] = {0,0,0,0,0,0,0};
   int lista4[7] = {0,0,0,0,0,0,0};
   int lista5[7] = {0,0,0,0,0,0,0};
   
   cout<<" ";
   for(int i=0; i< 7;i++){
      cout<<numeros[i];
      cout<<" ";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i <7; i++){
      cout<<lista[i];
      cout<<"|";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i < 7; i++){
      cout<<lista1[i];
      cout<<"|";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i < 7; i++){
      cout<<lista2[i];
      cout<<"|";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i < 7; i++){
      cout<<lista3[i];
      cout<<"|";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i < 7; i++){
      cout<<lista4[i];
      cout<<"|";
   }
   cout<<"\n";
   cout<<"|";
   for(int i =0; i < 7; i++){
      cout<<lista5[i];
      cout<<"|";
   }
   cout<<"\n";

}*/

void Prueba::tablero_juego(){
  // system("cls");

   int col=0;
   for(int l = 0; l < 42 ;l++){
      cout<<"|"<<tablero[l];

      col++;
  

      if(col==7) {
         col=0;
         cout<<'|'<<endl;

      }

   
     
   }

     
};
bool Prueba::ver_ganador(){
   string resultado;
   for(int i = 0; i < 42; i = i + 4){
      if(tablero[lineas[i]] == tablero[lineas[i + 1]]
         && tablero[lineas[i]] == tablero[lineas[i + 2]]
         && tablero[lineas[i]] == tablero[lineas[i + 3]]
         && tablero[lineas[i] != '\0']){
      }
   }
}

void Prueba::agregarficha(bool jugadores){


   if(jugadores == true){
     
 

     // int x = x + ficha;
      for(int o = 0; o < 42; o = o + 7){
         if(tablero[o] = '0'){
            tablero[o-7] = 'X'; 
            cout<<"IIIII";
            break;

         }

      }
   } 
      
  /*if(jugadores = false){
      for(int o = 0; o < 6;o = o + 7){
         if(tablero[o] == tablero[o + 7]
         && tablero[o] == tablero[o + 7]
         && tablero[o] == tablero[o + 7]
         && tablero[o] == tablero[o + 7]
         && tablero[o] == tablero[o + 7]
         && tablero[o] == tablero[o + 7]
         && tablero[o] != '\0'){
            tablero[o] == 'O'; 
         }
      }
   } 
*/
   

}; 
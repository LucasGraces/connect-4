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
  
   int col=0;
   int numeros[7] = {1,2,3,4,5,6,7};
   cout<<" ";
   for(int i=0; i< 7;i++){
      cout<<numeros[i];
      cout<<" ";
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
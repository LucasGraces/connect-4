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
   cout<<"  ";
   for(int i=0; i< 7;i++){
      cout<<numeros[i];
      cout<<"   ";
   }
   cout<<"\n";
   for(int l = 0; l < 42 ;l++){
      cout<<"| "<<tablero[l]<<" ";
      col++;
  
      if(col==7) {
         col=0;
         cout<<"|"<<endl;
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

/*
void Prueba::juego_ia(bool jugadores){
   int o;
   int i;
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
      if(flag == false){
         tablero[35+ficha]='X';
      }
   } 
   if(jugadores == false){
      for(i = 0; i < 294; i = i + 2){
         if(tablero[lineas[i]] == 'X' 
            && tablero[lineas[i + 1]] == 'X'
            && tablero[lineas[i + 2]] == 'X'
            && tablero[lineas[i]] != '\0'){//Si esta por perder
               tablero[lineas[i+2]] = 'O';
               fla=true;
               break;
         }
         else if(tablero[i] == 'X'){//Ingresa ramdom
            tablero[i-7] = 'O';
            break;
         }
         else if(fla == false){//Para empatar
            tablero[35+ficha] = 'O';
         }

         else if(tablero[lineas[i]] == 'O'
            && tablero[lineas[i+1]] == 'O'
            && tablero[lineas[i+2]] == 'O'){//Si esta por ganar
               tablero[lineas[i+3]] = 'O';
            }
         
      }
   }
};*/

void Prueba::archivo(){
   int resu;
   int i=0;

   cout<<"SPOD;KGJIDSOIGJJKGOIDSJ";
   ifstream archivo("jugadas_ia.txt");

   while(archivo>>resu){
      numbers[i] = resu;
      i++; 
   }
   
   for(int t = 0; t < 3; t++){
      cout<<numbers[t];
   }
   archivo.close();
};

/*void Prueba::juego_ia(bool jugadores){
   int o;
   int i;
   ficha--;
   bool flag = false;
   bool fla = false;
   if(jugadores == true){
      for( o = ficha; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o-7] = 'X'; 
            flag=true;                       // Esto la parte en la que juega el usuario
            break;
         }
      }
      if(flag == false){
         tablero[35+ficha]='X';
      }
   }
   else if(jugadores == false ){
      for(i = 0 ;i < 1000; i = i + 4 ){
         if(tablero[numbers[i]] = 'O'
            && tablero[numbers[i + 1]] == 'O'
            && tablero[numbers[i + 2]] == 'O'
            && tablero[numbers[i]] != '\0'){  // Trata de ganar
            
            if(tablero[numbers[i+3]] + 7 != '\0'){
               tablero[numbers[i + 3]] == 'O';
            }
            else if(tablero[numbers[i+3]] + 7 == '\0'){
               int b;
               b = 1 + rand() % 8;
               ficha = b;
               for( o = ficha; o < 42; o = o + 7){
                  if(tablero[o] != '\0'){
                     tablero[o-7] = 'O'; 
                     flag=true;            
                     break;
                  }
               }
            }
         }
         else if(tablero[numbers[i]] = 'X'
            && tablero[numbers[i + 1]] == 'X'
            && tablero[numbers[i + 2]] == 'X'
            && tablero[numbers[i]] != '\0'){  // Evita que el contricante gane
            
            if(tablero[numbers[i+3]] + 7 != '\0'){
               tablero[numbers[i + 3]] == 'O';
            }
            else if(tablero[numbers[i+3]] + 7 == '\0'){
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
         else if(tablero[numbers[i]] == 'O' or tablero[numbers[i]] == '\0'
               && tablero[numbers[i+1]] == 'O' or tablero[numbers[i+1]] == '\0'
               && tablero[numbers[i+2]] == 'O' or tablero[numbers[i+2]] == '\0'
               && tablero[numbers[i+3]] == 'O' or tablero[numbers[i+3]] == '\0'){     // Trata de hacer una jugada
               int a;
               a = rand() % 4; // Genera un valor entre 0 y 9
               tablero[numbers[i+a]] == 'O';
         }
         else{  // Pone la ficha en un lugar aleatorio
            int b;
            b = 1 + rand() % 8; //genera un numero entre 1 y 7
            ficha = b;
            for( o = ficha; o < 42; o = o + 7){
               if(tablero[o] != '\0'){
                  tablero[o-7] = 'O'; 
                  flag=true;            
                  break;
               }
            }
         }
      } 
   }
};*/
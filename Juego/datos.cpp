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
   for(int i=0; i< 7;i++){// muere
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
   for(int i = 0; i < 294; i = i + 4){ //muere
      if(tablero[lineas[i]] == tablero[lineas[i + 1]]
        && tablero[lineas[i]] == tablero[lineas[i + 2]]
        && tablero[lineas[i]] == tablero[lineas[i + 3]]
        && tablero[lineas[i]] != '\0'){
            ganada4 = lineas[i];
            ganada3 = lineas[i + 1];
            ganada2 = lineas[i + 2];
            ganada1 = lineas[i + 3];
            return true;
        }
    }
   return false;
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

void Prueba::cargar_archivo(){
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
}

void Prueba::juego_ia(bool jugadores){
   int i;
   int o;
   ficha--;
   bool flag = false;
   bool fla = false;
   if(jugadores == true){
/*       for(int h = 0; h < 42;h++){
        cout<<"PEPITO: "<< tablero[h]<<endl;
      } */
     for( o = ficha; o < 42; o = o + 7){
         if(tablero[o] != '\0'){
            tablero[o - 7] = 'X';
            fla = true;
            break;
        }                             // JUEGA EL JUGADOR
      }
      if(fla==false){
         tablero[35 + ficha] = 'X';
        }
   }
   if(jugadores == false){
      for(i = 0 ;i < numeros.size() ; i = i + 4){
         if(tablero[numeros[i]] == tablero[numeros[i + 1]]
            && tablero[numeros[i]] == tablero[numeros[i + 2]] ){  // Trata de ganar y e
            cout<<numeros[i + 3]<<endl;
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
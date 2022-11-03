#include <string>
#include <iostream>
#include "datos.h"

using namespace std;

int main(){
    Prueba pr;
    int opcion = 0;
    bool jugador = true;
    int columna = 0;
    pr.archivo();
    while(opcion != 2){
        pr.tablero_juego();

        if(columna != 0){
            pr.juego_ia(jugador);
            pr.tablero_juego();
            if(pr.ver_ganador() == false){
                jugador =! jugador;
                pr.ficha = 0;
                //system("cls");
            }
            else{
                
                cout<<"Gano la IA"<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
            }
        }
        
        cout<<"Juega el Jugador"<<endl;
        cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
        cin>>pr.ficha;
        columna = pr.ficha;

        pr.juego_ia(jugador);
        if(pr.ver_ganador() == false){
            jugador =! jugador;

             //system("cls");
        }
        else{
            cout<<"Gano el jugador"<<endl;
        }
    }
};
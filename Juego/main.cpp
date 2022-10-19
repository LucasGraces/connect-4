#include <string>
#include <iostream>
#include "datos.h"

using namespace std;



int main(){
    Prueba pr;
    int opcion = 0;
    while(opcion != 2){
        pr.tablero_juego();
        pr.ver_ganador();
        cout<<"Juega el Jugador 1"<<endl;
        cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
        cin>>pr.ficha;
        
        pr.agregarficha(true);
        pr.tablero_juego();

        if(pr.ver_ganador() == false){
            cout<<"Juega el Jugador 2"<<endl;
            cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
            cin>>pr.ficha;

            pr.agregarficha(false);
        }
        else{
            cout<<"Gano el jugador 1"<<endl;
        }
    }
    return 0;
};
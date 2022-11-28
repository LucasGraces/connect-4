#include <string>
#include <iostream>
#include <cstdlib>
#include "Archivo.h"
#include "Gestor_juego.h"
#include "Invitado.h"
#include "Sistema.h"

using namespace std;

// 26/10 SOLO FALTA TERMINAR LA IA Y AGREGARLA AL PRINCIPAL

Usuario usu;
Administrador admin;
Archivo ar;
Sistema sis;
Gestor_juego gj;

void menu_admin(){
    system("cls");
    char cop_adm;
    int op_adm = 0;
    while(op_adm != 51){
        cout<<"=============================================="<<endl;
        cout<<"            Bienvenido ADMINISTRADOR          "<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;
        cout<<"Los archivos existentes son: "<<endl;
        cout<<sis.visualizar_archivos()<<endl;
        cout<<"1- Seleccionar archivo ya en el sistema \n2- Crear un archivo \n3-Salir"<<endl;
        cin>>cop_adm;
        op_adm = (int)cop_adm;
        
        if(op_adm == 49){
            string nom_archivo;
            cout<<"Ingrese el nombre del archivo el cual se utilizara"<<endl;
            cin.ignore();
            getline(cin, nom_archivo);

            if(sis.elegir_archivo(nom_archivo) == true){
                cout<<"El archivo se selecciono correctamente"<<endl;
            }
            else{
                cout<<""<<endl;
            }
        }
        else if(op_adm == 50){
            string nom_archivo;
            cout<<"Ingrese el nombre del archivo"<<endl;
            cin.ignore();
            getline(cin, nom_archivo);

            if(sis.generar(nom_archivo) == true){
                cout<<"El archivo fue creado correctamente"<<endl;
            }
        }
        else if(op_adm == 51){
            cout<<"Hasta Luego Administrador"<<endl;
            system("cls");
        }
        else{
            cout<<"Opcion invalida"<<endl;
        }
    }
    
    
};

void menu_uno(){
    cout<<"ingrese usuario"<<endl;
    cin.ignore();
    getline(cin,usu.nickname);
    cout<<endl;
    cout<<"ingrese contraseña"<<endl;
    getline(cin,usu.pwd);
    cout<<endl;
    cout<<"Ingrese su rol"<<endl;
    cout<<"1- Usuario"<<endl;
    cout<<"2- Administrador"<<endl;
    cin>>usu.rol;

    if(usu.validar_usuario(1) == true){
        if(usu.resul_vali == 3 and usu.rol == 1){
            system("cls");
            cout<<"Ingreso exitoso"<<endl;
            usu.validar_ingreso = 1;
        }
        else if(usu.resul_vali == 2){
            cout<<"El nombre de usuario ingresado no existe"<<endl;
        }
        else if(usu.resul_vali == 1){
            cout<<"La contraseña ingresada no existe"<<endl;
        }
        else if(usu.resul_vali == 3 and usu.rol == 2){
            menu_admin();
        }
        else{
            cout<<"Ocurrio un error"<<endl;
        }
    }
    else{
        cout<<"Formato incorrecto"<<endl;
    }
};

void menu_registrar(){
    cout<<"El nombre de usuario debe ser mayor a 8 caracteres "<<endl;
    cout<<"La contrasena mayor a 8 caracteres y no debe contener numeros"<<endl;
    cout<<endl;
    cout<<"Ingrese nombre de usuario"<<endl;
    cin.ignore();
    getline(cin,usu.nickname);
    cout<<endl;
    cout<<"Ingrese contrasena"<<endl;
    getline(cin,usu.pwd);
    cout<<endl;

    if(usu.validar_usuario(2) == true){
        if(usu.resul_vali == 1){
            cout<<"El usuario fue registrado exitosamente"<<endl;
        }
        else{
            cout<<"El usuario ya existe"<<endl;
        }
    }
    else{
        cout<<"El formato ingresado es incorrecto"<<endl;
    }
};

void menu_2_jugadores(){
    int juego_in_op = 0;
    bool jugador = true;
    system("cls");
    while(juego_in_op != 2 or juego_in_op == 1){
        int columna = 0;

        if(juego_in_op == 1){
            gj.setear_tablero(gj.tablero);
            juego_in_op = 0;
        }
        cout<<"================================================="<<endl;
        cout<<"           Juego contra otra persona             "<<endl;
        cout<<"================================================="<<endl;
        cout<<endl;
        usu.cargartablero(gj.tablero);
        if(jugador == true){
            cout<<endl;
            cout<<"Juega "<<usu.nickname<<endl;
        }
        else{
            cout<<endl;
            cout<<"Juega invitado"<<endl;
        }
        cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
        cin>>columna;
        
        gj.jugar_ficha(columna, jugador, gj.tablero);
        if(gj.verificar_victoria() == false){
            jugador =! jugador;
            system("cls");
        }
        else{
            system("cls");
            cout<<"================================================="<<endl;
            cout<<"               FELICIDADES GANASTE               "<<endl;
            cout<<"================================================="<<endl;
            cout<<endl;
            usu.cargartablero(gj.tablero);
            if(jugador == true){
                cout<<"Gano el jugador "<<usu.nickname<<endl;
            }
            else{
                cout<<"Gano el jugador invitado"<<endl;
            }
            cout<<endl;
            cout<<"Se desea volver a jugar? "<<endl;
            cout<<"1- Volver a jugar"<<endl;
            cout<<"2- Salir"<<endl;
            cin>>juego_in_op;
        }
    }
};

void menu_ia(){
    int juego_in_op = 0;
    bool jugador = true;
    //system("cls");
    gj.archivo();
    while(juego_in_op != 2 or juego_in_op == 1){
        int columna = 0;

        if(juego_in_op == 1){
            gj.setear_tablero(gj.tablero);
            juego_in_op = 0;
        }
        cout<<"================================================="<<endl;
        cout<<"           Juego contra la computadora           "<<endl;
        cout<<"================================================="<<endl;
        cout<<endl;
        usu.cargartablero(gj.tablero);
        
        if(jugador == true){
            cout<<endl;
            cout<<"Juega "<<usu.nickname<<endl;
            cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
            cin>>columna;
        }
        gj.juego_ia(columna, jugador, gj.tablero);
        if(gj.verificar_victoria() == false){
            jugador =! jugador;
            //system("cls");
        }
        else{
            //system("cls");
            cout<<"================================================="<<endl;
            cout<<"               FELICIDADES GANASTE               "<<endl;
            cout<<"================================================="<<endl;
            cout<<endl;
            usu.cargartablero(gj.tablero);
            if(jugador == true){
                cout<<"Gano el jugador "<<usu.nickname<<endl;
            }
            else{
                cout<<"Gano la IA"<<endl;
            }
            ar.cargar_archivo();
            cout<<endl;
            cout<<"Se desea volver a jugar? "<<endl;
            cout<<"1- Volver a jugar"<<endl;
            cout<<"2- Salir"<<endl;
            cin>>juego_in_op;

            if(juego_in_op == 1){
                gj.archivo();
            }
        }
    }
};

int main(){
    system("Title 4 EN LINEA");
    system("Color 4e");
    char copcion;
    int opcion = 0;
    int registro = 0;
    while(opcion != 52){
        cout<<"=============================================="<<endl;
        cout<<"                   Bienvenido                 "<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;
        cout<<"Ingrese su opcion del juego"<<endl;
        cout<<"1- Ingreso"<<endl;
        cout<<"2- Registrarse"<<endl;
        cout<<"3- Jugar"<<endl; 
        cout<<"4- Salir"<<endl;
        cin>>copcion;
        opcion = (int)copcion;
        
        if(opcion == 49){
            menu_uno();
        }
        else if(opcion == 50){
            menu_registrar();
        }
        else if(opcion ==51){
            if(usu.validar_ingreso == 1){
                char aopcion;
                int opcion2;
                cout<<"=============================================="<<endl;
                cout<<"             METODOS DE JUEGOS                "<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;
                cout<<"ingrese 1 si quiere jugar contra la computadora"<<endl;
                cout<<"ingrese 2 si quiere jugar contra otra persona"<<endl;
                cin>>aopcion;
                cin.ignore();
                opcion2 = (int)aopcion;

                if(opcion2 == 49){
                    menu_ia();
                }
                if(opcion2 == 50){
                   menu_2_jugadores();
                }
                else{
                    cout<<"Ingrese una opcion valida"<<endl;
                }
            }
            else{
                cout<<"Por favor loguearse antes de jugar"<<endl;
            }
        }
        else if(opcion == 52){
            cout<<"Hasta Luego"<<endl;
        }
        else{
            cout<<"Ingrese una opcion valida"<<endl;
        }
    }
    return 0;
};
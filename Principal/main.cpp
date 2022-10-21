#include <string>
#include <iostream>
#include "Archivo.h"
#include "Gestor_juego.h"
#include "Invitado.h"
#include "Sistema.h"

using namespace std;

int main(){
    Usuario usu;
    Administrador admin;
    Archivo ar;
    Sistema sis;
    Gestor_juego gj;

    char copcion;
    int opcion = 0;
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
            cout<<"ingrese usuario"<<endl;
            cin.ignore();
            getline(cin,usu.nickname);
            cout<<"ingrese contraseña"<<endl;
            getline(cin,usu.pwd);
            cout<<"Ingrese su rol"<<endl;
            cout<<"1- Usuario"<<endl;
            cout<<"2- Administrador"<<endl;
            cin.ignore();
            cin>>usu.rol;

            while(usu.nickname == "" or usu.pwd == "" or usu.cargar_datos() == false){
                cout<<"Por favor ingrese correctamente los datos"<<endl;
                cout<<endl;
                cout<<"Ingrese nombre de usuario"<<endl;
                getline(cin,usu.nickname);
                cout<<"Ingrese contraseña"<<endl;
                getline(cin,usu.pwd);
            }
            if(ar.buscar_usuario() == 0){
                cout<<"Formato incorrecto"<<endl;
            }
            else if(ar.buscar_usuario() == 1){
                cout<<"Contraseña incorrecta"<<endl;
            }
            else if(ar.buscar_usuario() == 2){
                cout<<"Nombre de usuario incorrecto"<<endl;
            }
            else if(ar.buscar_usuario() == 3 and usu.rol == 2){
                int op_adm = 0;
                cout<<"=============================================="<<endl;
                cout<<"                   Bienvenido                 "<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;
                cout<<"Los archivos existentes son: "<<endl;
                sis.visualizar_archivos();
                cout<<endl;
                cout<<"1- Seleccionar archivo ya en el sistema \n2- Crear un archivo"<<endl;
                cin.ignore();
                cin>>op_adm;
                
                if(op_adm == 1){
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
                else if(op_adm == 2){
                    string nom_archivo;
                    cout<<"Ingrese el nombre del archivo"<<endl;
                    cin.ignore();
                    getline(cin, nom_archivo);

                    if(sis.generar(nom_archivo) == true){
                        cout<<"El archivo fue creado correctamente"<<endl;
                    }
                }
                else{
                    cout<<"Opcion invalida"<<endl;
                }
            }
            else if(ar.buscar_usuario() == 3 and usu.rol == 1){
                cout<<"Ingreso exitoso"<<endl;
            }
        }
        if(opcion == 50){
            cout<<"El nombre de usuario debe ser mayor a 8 caracteres "<<endl;
            cout<<"La contrasena mayor a 8 caracteres y no debe contener numeros"<<endl;

            cout<<"Ingrese nombre de usuario"<<endl;
            cin.ignore();
            getline(cin,usu.nickname);
            cout<<"Ingrese contrasena"<<endl;
            getline(cin,usu.pwd);

            while(usu.nickname == "" or usu.pwd == "" or usu.cargar_datos() == false){
                cout<<usu.nickname;
                cout<<usu.pwd;
                cout<<"Por favor vuelva a ingresar los datos correctamente"<<endl;
                cout<<endl;
                cout<<"Ingrese nombre de usuario"<<endl;
                getline(cin,usu.nickname);
                cout<<"Ingrese contraseña"<<endl;
                getline(cin,usu.nickname);
            }
            if(ar.registrar_usuario() == 1){
                cout<<"El usuario fue registrado exitosamente"<<endl;
            }
            else{
                cout<<"El usuario ya existe"<<endl;
            }
        }
        if(opcion ==51){
            if(ar.buscar_usuario() == 3){
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
                    /*cout<<"================================================="<<endl;
                    cout<<"           Juego contra la computadora           "<<endl;
                    cout<<"================================================="<<endl;
                    cin>>gj.jugar_ia();
                    while(sis.verificarfinal() != false){
                        cout<<"ingrese columna de la ficha"<<endl;
                        cin>>ficha;
                        cin.ignore();

                    }
                    if(sis.verificarfinal() == true){
                        cout<<"el ganador es "<<endl;

                    }
                    if(sis.fichas == 48){
                        cout<<"El juego termino en empate"<<endl;

                    }*/

                }
                if(opcion2 == 50){
                    int juego_in_op = 0;
                    bool jugador = true;
                    while(juego_in_op != 2){
                        int columna = 0;
                        cout<<"================================================="<<endl;
                        cout<<"           Juego contra otra persona             "<<endl;
                        cout<<"================================================="<<endl;
                        cout<<endl;
                        usu.cargartablero();
                        cout<<"Juega "<<usu.nickname<<endl;
                        cout<<"Ingrese numero de columna que quiere ingresar ficha"<<endl;
                        cin>>columna;
                        
                        gj.jugar_ficha(columna, jugador);
                        if(gj.verificar_victoria() == false){
                            jugador=!jugador;
                            system("cls");
                        }
                        else{
                            cout<<"Gano el jugador"<<endl;
                        }
                    }
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
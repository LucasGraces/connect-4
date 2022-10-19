#include <string>
#include <iostream>
#include "Archivo.h"
#include "Gestor_juego.h"
#include "Invitado.h"
#include "Sistema.h"


using namespace std;

usuario usu;
administrador admin;
Archivo ar;
Sistema sis;
Gestor_juego gj;

int opcion = 0;
int main(){
    char copcion;

    while(opcion != 52){
        cout<<"=============================================="<<endl;
        cout<<"                   Bienvenido                 "<<endl;
        cout<<"=============================================="<<endl;
        cout<<endl;
        cout<<"Ingrese su opcion del juego"<<endl;
        cout<<"1- Ingreso"<<endl;
        cout<<"2- Registrarse"<<endl;
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
            getline(cin,usu.rol);

            while(usu.nickname == "" or usu.pwd == "" or usu.cargar_datos() == false){
                cout<<"Por favor ingrese correctamente los datos"<<endl;
                cout<<endl;
                cout<<"Ingrese nombre de usuario"<<endl;
                getline(cin,usu.nickname);
                cout<<"Ingrese contraseña"<<endl;
                getline(cin,usu.pwd);
            }
            if(usu.buscar_usuario(usu.nickname) == 0 and vali.buscar_password(usu.pwd) == 0){
                cout<<"El usuario existe"<<endl;
            }
            else if(vali.buscar_usuario(usu.nickname) == 1 and vali.buscar_password(usu.pwd) == 1){
                cout<<"=============================================="<<endl;
                cout<<"                   Bienvenido                 "<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;
                cout<<"Los archivos existentes son: "<<endl;
                gs.mostras_partidas();
                cout<<endl;
                cout<<"1- Seleccionar archivo ya en el sistema \n2- Crear un archivo"<<endl;
                cin.ignore();
                cin>>admin.op_adm;
                
                if(admin.op_adm == 1){
                    cout<<"Ingrese el nombre del archivo el cual se utilizara"<<endl;
                    cin.ignore();
                    getline(cin,admin.num_archivo);

                    if(vali.validar_num() == true){
                        if(gs.prepara_archivo() == true){
                            cout<<"Archivo listo para su utilizacion"<<endl;
                        }
                    }
                    else{
                        cout<<"El nombre es incorrecto"<<endl;
                    }
                }
                else if(admin.op_adm == 2){
                    cout<<"Ingrese el nombre del archivo"<<endl;
                    cin.ignore();
                    getline(cin,admin.nom_archivo);

                    if(vali.validar_nom() == true){
                        if(gs.crear_archivo() == true){
                            cout<<"Archivo creado con exito"<<endl;
                        }
                        else{
                            cout<<"Ocurrio un error"<<endl;
                        }
                    }
                    else{
                        cout<<"El archivo ya existe"<<endl;
                    }
                }
                else{
                    cout<<"Opcion invalida"<<endl;
                }
            }
            else{
                cout<<"La contraseña o el usuario son incorrectos"<<endl;
            }
        }
        
        if(opcion == 50){
            cout<<"El nombre de usuario debe ser mayor a 8 caracteres "<<endl;
            cout<<"La contraseña mayor a 8 caracteres y no debe contener numeros"<<endl;

            cout<<"Ingrese nombre de usuario"<<endl;
            cin.ignore();
            getline(cin,usu.nickname);
            cout<<"Ingrese contraseña"<<endl;
            getline(cin,usu.pwd);

            while(usu.nickname == "" or usu.pwd == ""){
                cout<<"Por favor vuelva a ingresar los datos correctamente"<<endl;
                cout<<endl;
                cout<<"Ingrese nombre de usuario"<<endl;
                getline(cin,usu.nickname);
                cout<<"Ingrese contraseña"<<endl;
                getline(cin,usu.nickname);
            }
            if(ar.registrar(usu.nickname, usu.pwd) == 1){
                cout<<"El usuario fue registrado"<<endl;
            }
            else if(ar.registrar(usu.nickname, usu.pwd) == 2){
                cout<<"El usuario ya existe"<<endl;
            }
            else if(ar.registrar(usu.nickname, usu.pwd) == 3){
                cout<<"la contraseña no cumple con los requerimientos"<<endl;
            }
        }
        /*if(opcion ==51){
            if(usu.buscar_usuario()=true and usu.buscar_password()=true){
                cin>>usu.cargartalbero();
                cout<<"=============================================="<<endl;
                cout<<"                   Jugar                      "<<endl;
                cout<<"=============================================="<<endl;
                cout<<endl;
                cout<<"ingrese 1 si quiere jugar contra la computadora"<<endl;
                cout<<"ingrese 2 si quiere jugar contra otra persona"<<endl;
                cin>>usu.aopcion;
                cin.ignore();

                if(usu.elegir_modojuego() = 49){
                    cout<<"================================================="<<endl;
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

                    }

                }
                if(usu.elegir_modojuego() == 50){
                    while(usu.player2 != 2){    
                        cout<<"================================================="<<endl;
                        cout<<"           Juego contra otra persona             "<<endl;
                        cout<<"================================================="<<endl;
                        cout<<endl;
                        cout<<"1- si el player 2 esta registrado?"<<endl;
                        cout<<"2- Si quiere salir"<<endl;
                        cin.ignore();
                        cin>>usu.player2;

                            if(usu.player2 == 49){
                                cout<<"ingrese usuario"<<endl;
                                cin.ignore();
                                getline(cin,usu.nickname);
                                cout<<"ingrese contraseña"<<endl;
                                cin.ignore();
                                getline(cin,usu.pwd);


                                while(usu.nickname == "" or usu.pwd == "" or usu.datos(usu.nickname,usu.pwd) == false){
                                    cout<<"Por favor ingrese correctamente los datos"<<endl;
                                    cout<<endl;
                                    cout<<"Ingrese nombre de usuario"<<endl;
                                    getline(cin,usu.nickname);
                                    cout<<"Ingrese contraseña"<<endl;
                                    getline(cin,usu.pwd);
                                }
                                if(vali.buscar_usuario(usu.nickname) == true ){ //and vali.buscar_password(usu.pwd) == true){
                                    cout<<"El usuario existe"<<endl;
                                }
                                else if(vali.buscar_usuario(usu.nickname) == false){
                                    cout<<"EL usuario no existe"<<endl;
                                }
                                else if(vali.buscar_password(usu.pwd) == false){
                                    cout<<"La contraseña no existe"<<endl;
                                
                                }
                            }

                        if(usu.player2 == 50){
                        }

                    }

                }
            
                
            }
            else{
                cout<<"Por favor loguearse antes de jugar"<<endl;
            }

        }*/

        else if(opcion == 52){
            cout<<"Hasta Luego"<<endl;
        }
        else{
            cout<<"Ingrese una opcion valida"<<endl;
        }
    }
    return 0;
};
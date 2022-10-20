int validar::buscar_password(string password){
    int estado = 0;
    string contenido;
    Archivo archi;
    administrador admin;
    ifstream fs("contraseñas_us.txt");

    admin.contrasena = "administrador1234";
    
    while(fs >> contenido){
        if(contenido == admin.contrasena){
            estado = 1;
            return estado;
        }
        else if(contenido == password){
            estado = 0;
            archi.estado_login = 0;
            return estado;
        }
        else{
            estado = 2;
            archi.estado_login = 1;
        }
    }
    fs.close();
    return estado;
};

bool validar::validar_num(){
    bool resultado = false;
    administrador admin;
    string contenido;
    ifstream archivo("nom_archivos.txt");

    while(archivo >> contenido){
        if(admin.num_archivo == contenido){
            resultado = true;
            return resultado;
        }
        else{
            resultado = false;
        }
    }
    return resultado;
};

bool validar::validar_nom(){
    bool resultado = false;
    administrador admin;
    string contenido;
    ifstream archivo("nom_archivos.txt");

    while(archivo >> contenido){
        if(admin.num_archivo != contenido){
            resultado = true;
            return resultado;
        }
        else{
            resultado = false;
        }
    }
    return resultado;
};
/************Variables que se utilizaran en el iterador***************/
int Usuarios=0;
struct Usuario{
    /***Campos que va a llevar el log de usuarios***/
    string NombreUsuario;
    string Clave;
    string Sucursal;
};
/*****Preparando iterador para agregar usuarios******/
Usuario *usuario = new Usuario[minimo];

void LeerUsuarios(){
    /*Nombre del txt*/
    string NombreArchivo = "bd/usuarios.txt";
    string Linea;
    Usuarios = 0;
    /*Si no existe el archivo, muestro el mensaje*/
    ifstream Archivo(NombreArchivo.c_str());
    if( Archivo.fail() ){
        cout << "No existe el fichero " << NombreArchivo << endl;
        /*Salir del sistema*/
        exit(1);
    }
    /*Mientras no est� al final del archivo*/
    while (!Archivo.eof()) {
        getline(Archivo,Linea);
         /*Mientras no est� al final del archivo*/
        if (!Archivo.eof()){
            vector <string> Contenido;
            stringstream revisar(Linea);
            string Intermedio;
            while(getline(revisar, Intermedio, '|')){
                /*Guardo el contenido del archivo en el vector*/
                Contenido.push_back(Intermedio);
            }
            /*Recorro los registros del archivo, cada tres espacios separados por pipe es una tupla*/
            for(int i = 0; i < Contenido.size(); i=i+3){
                usuario[Usuarios].NombreUsuario = Contenido[i];
                usuario[Usuarios].Clave         = Contenido[i+1];
                usuario[Usuarios].Sucursal      = Contenido[i+2];
                Usuarios++;
             }

        }
    }
    /*Cierro el archivo*/
    Archivo.close();
}
void ConfirmarUsuarios(){
    /*Primero elimino el archivo, porque no puedo hacer filtro para modificar solo el campo que quiero*/
    remove("bd/usuarios.txt");
    /*Abro el archivo usuarios*/
    ofstream Arhivo("bd/usuarios.txt");
    for(int i = 0; i < Usuarios; i++){
        /*Cargo todo de nuevo, separando toda la informacion con pipes*/
        Arhivo << usuario[i].NombreUsuario << "|" ;
        Arhivo << usuario[i].Clave << "|";
        Arhivo << usuario[i].Sucursal << endl;
    }
    /*Cierro el archivo*/
    Arhivo.close();
}
void AgregarUsuarios(){
    /*Formulario para pedir informacion de los usuarios*/
    cout << "***********Formulario para Agregar Usuarios************ ";
    cout << "Introduce el nombre de usuario: "<< "\n";
    getline(cin, usuario[Usuarios].NombreUsuario);
    cin.sync();
    cout << "Introduce la Clave: "<< "\n";
    getline(cin, usuario[Usuarios].Clave);
    cin.sync();
    cout << "Introduce la Sucursal: "<< "\n";
    getline(cin, usuario[Usuarios].Sucursal);
    cin.sync();
    Usuarios++;
    /*Confirmo el usuario*/
    ConfirmarUsuarios();
    /*Y vuelvo a leer el iterador*/
    LeerUsuarios();
    cout << "Usuario Creado" << endl;
    Limpiar();
}
void VerUsuarios(){
    /*Mostrar los usuarios que estane en el iterador*/
    for (int i=0; i<Usuarios; i++){
        cout << "Usuario: " << usuario[i].NombreUsuario << "\n";
    }
    Limpiar();
}
void ModificarUsuarios(){
    string Nombre = "";
    string Clave = "";
    int Numero;
    int Existe = 0;
    cout << "Ingrese nombre de usuario: ";
    getline(cin,Nombre);
    cin.sync();
    /*Reviso si existe un usuario con ese nombre en el iterador*/
    for(int i = 0; i < Usuarios; i++){
        if(Nombre == usuario[i].NombreUsuario){
            Existe = 1;
            Numero = i;
            break;
        }
    }
    /*Si encontre coincidencias, continuo*/
    if(Existe==1){
        cout << "Ingrese clave anterior: ";
        getline(cin, Clave);
        cin.sync();
        /*Para mayor seguridad, pido la clave anterior*/
        if(usuario[Numero].Clave == Clave){
            string NuevaClave = "";
            cout << "Ingrese nueva clave: ";
            getline(cin, NuevaClave);
            cin.sync();
            usuario[Numero].Clave = NuevaClave;
        }else{
            cout << "La clave anterior es incorrecta." << endl;
        }

    }else{
        cout << "El usuario no esta registrado" << endl;
    }
    ConfirmarUsuarios();
    LeerUsuarios();
    Limpiar();
}
void InicioSesion(){
    /*Variable para saber si la clave es correcta*/
    bool Correcto = true;
    /*En un do while mientras las credenciales no sean las correctas*/
    do{
        cout << "\t\t\tCredenciales" << endl;
        string NombreUsuario ="";
        string Clave ="";
        cout << "\n\tUsuario: ";
        getline(cin, NombreUsuario);
        cout << "\t\nIngrese su clave "<< endl;
        getline(cin, Clave);
        for(int i = 0; i < Usuarios; i++){
            /*Si usuario y clave con correctos, ya no sigo buscando coincidencias en el iterador*/
            if(usuario[i].NombreUsuario == NombreUsuario && usuario[i].Clave == Clave){
                Correcto    = false;
                sucursal    = usuario[i].Sucursal;
                sesion      = usuario[i].NombreUsuario;
                break;
            }
        }
        if(Correcto){
            /*Si no ingresa correctamente sus datos*/
            cout << "Credenciales Incorrectos" << endl;
            Limpiar();
        }
    }while(Correcto);
    /*Limpio la pantalla*/
    system("cls");
}



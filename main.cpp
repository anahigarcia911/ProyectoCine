#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>
 #include <time.h>
using namespace std;
//variables constantes, para tener un límite de regitros a ingresar
 int maximo = 5000;
const int minimo = 100;

//variables glob ales, para saber quien se ha conectado y en que sucursal
string sucursal = "";
string sesion   = "";
/**/
void Limpiar(){
    system("pause");
    system("cls");
}
/*Agrego el algoritmo de usuarios*/
#include "usuario.h"
void Iniciar();
/*Agrego el algorimo de peliculas*/
#include "peliculas.h"
/*Agrego el algorimo de Ticktes*/
#include "boletos.h"
/*Variable para almacenar el numero de opcion*/
int opcion;
int main(){
    Iniciar();
    return 0;
}
/*Arranco con las funciones de inicio*/
void Iniciar(){
    LeerPeliculas();
    LeerUsuarios();
    LeerBoletos();
    InicioSesion();
    /*Do While para el menu, siempre pedirá usuario y contraseña, si y solo si los datos son erroneos*/
    do
    {
        cout << "Usuario Conectado: " << sesion << endl <<" Sucursal: "<< sucursal << endl;
        cout << "Menu Principal:" << endl;
        cout << "1)  Agregar Pelicula" << endl;
        cout << "2)  Editar Pelicula" << endl;
        cout << "3)  Mostrar todas las peliculas" << endl;
        cout << "4)  Mostrar peliculas segun anio de produccion" << endl;
        cout << "5)  Mostrar peliculas de estreno" << endl;
        cout << "6)  Crear boleto" << endl;
        cout << "7) Ver boletos" << endl;
        cout << "8)  Agregar usuario" << endl;
        cout << "9) Cambiar contrasenia usuario" << endl;
        cout << "10) Salir Del sistema" << endl;

        cin >> opcion;
        cin.sync();
        system("cls");

        //Opciones
        switch(opcion){
            case 1:
                AgregarPeliculas();
                break;

            case 2:
                ModificarPeliculas();
                break;

            case 3:
                VerPeliculas();
                break;

            case 4:
                PeliculasPorAnio();
                break;

            case 5:
                PeliculasEstreno();
                break;

            case 6:
                AgregarBoleto();
                break;

            case 7:
                VerBoletos();
                break;

            case 8:
                AgregarUsuarios();
                break;
            case 9:
                ModificarUsuarios();;
                break;
            case 10:
                cout << "Fin del programa" << endl;
                break;
            default:
                cout << "Opcion no existe" << endl;
                Limpiar();
                break;
        }
    } while (opcion != 10);
}

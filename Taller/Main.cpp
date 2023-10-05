#include <iostream>
#include "Interfaz.h"

using namespace std;

void menuNino();
void menuAdmin();
void menuNormal();
void login();
void menuJuegos(Interfaz *interfaz);
void menuOfimatica(Interfaz * interfaz);
void menuProduccionN(Interfaz* interfaz);
string name; string pass; int age;
int main(int argc, char const *argv[]){
    Interfaz *interfaz = new Interfaz();

    interfaz -> cargarBase();
    cout<<"Base de datos lista"<<endl;
    bool log = false;
    login();
    log = interfaz ->login(name,pass);

    if(log == true){
        int age = interfaz->returnEdad();
        if(age == 99999){
            menuAdmin();


        }else if(age < 18){
            menuNino();


        }else if(age >17){
            menuNormal();
            int op = -1;
            int num = 0;

            while(op != 6){
                menuNormal();
                cout << "Ingrese opcion: " << endl;
                cin >> op;

                switch(op){
                    case 1:
                        menuJuegos(interfaz);
                        break;

                    case 2:
                        menuOfimatica(interfaz);
                        break;

                    case 3: 
                        cout<<"a"<<endl;

                        break;

                    case 4:
                        cout<<"a"<<endl;

                        break;

                    case 5:
                        cout<<"a"<<endl;

                        break;

                    case 6:
                        cout<<"a"<<endl;

                        break;

                    default:
                        cout << "Número ingresado inválido" << endl;
                        break;
                }
            }
        }
    }
    cout<<"Paso! "<<endl;

    return 0;
}

//Imprime menu del nino
void menuNino(){
    cout<<"         Menu            "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Navegador "<<endl;
    cout<<"3.- Social "<<endl;
    cout<<"4.- Salir "<<endl;

}
//Imprime menu de Admin
void menuAdmin(){
    cout<<"         Menu Admin            "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Produccion  "<<endl;
    cout<<"4.- Navegador "<<endl;
    cout<<"5.- Seguridad "<<endl;
    cout<<"6.- Social "<<endl;
    cout<<"7.- Salir "<<endl;
}
//Imprime menu Normal
void menuNormal(){
    cout<<"         Menu             "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Produccion  "<<endl;
    cout<<"4.- Navegador "<<endl;
    cout<<"5.- Social "<<endl;
    cout<<"6.- Salir "<<endl;
}
//Cout de login, y cin para guardar datos
void login(){
    cout<<"--------Login--------"<<endl;
    cout<<"Ingrese Nombre: "<<endl;
    cin>> name;
    cout<<"Ingrese Contrasena: "<<endl;
    cin >> pass;
    return;
}


void menuJuegos(Interfaz* interfaz){
    string ej = "";
    int num = 0;

    string name = "";
    string genNuevo = "";

    while(num != 5){
        cout<<"1.- Mostrar Juegos "<<endl;
        cout<<"2.- Jugar algun juego "<<endl;
        cout<<"3.- Cambiar genero de un juego "<<endl;
        cout<<"4.- Mostrar generos de los Juegos . "<<endl;
        cout<<"5.- Volver. "<<endl;

        
        cin>>num;

        switch (num){
        

            case 1:
                interfaz ->imprimirJuegos();
                
                break;

            case 2:

                cout<<"\nIngrese nombre del Juego "<<endl;
                cin>>ej;

                interfaz->jugarJuego(ej);
                
                
                break;
            
            case 3:
                cout<<"\nIngrese nombre del juego: "<<endl;
                cin>>name;

                cout<<"\nIngrese genero nuevo: "<<endl;
                cin>>genNuevo;

                interfaz -> cambiarGeneroJuego(name,genNuevo);

                
                break;

            case 4:
                interfaz->mostrarGeneroJuegos();
                
                break;

            case 5:
                break;
            default:

                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}

/*

void menuJuegos(Interfaz* interfaz){

    int opcion;
    string ej;
    do {
        cout << "Menú:" << endl;
        cout << "1. Opción 1" << endl;
        cout << "2. Opción 2" << endl;
        cout << "3. Opción 3" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Has seleccionado la Opción 1." << endl;
                // Coloca aquí el código para la opción 1.
                break;
            case 2:
                cout<<"\nIngrese nombre del Juego "<<endl;
                cin>>ej;

                interfaz->jugarJuego(ej);
                
                break;
            case 3:
                cout << "Has seleccionado la Opción 3." << endl;
                // Coloca aquí el código para la opción 3.
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }

    } while (opcion != 4);

    return ;
}
*/
void menuOfimatica(Interfaz* interfaz){
        string ej = "";
    int num = 0;

    if(num != 4){
        cout<<"1.- Mostrar Softwares de Ofimatica "<<endl;
        cout<<"2.- Trabajar en un sofware(Add archivo) "<<endl;
        cout<<"3.- Eliminar trabajo(Delete arch) "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirOfimatica();
                menuOfimatica(interfaz);
                break;

            case 2:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->addArch(ej);
                menuOfimatica(interfaz);
                break;

            case 3:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->deleteArch(ej);
                menuOfimatica(interfaz);
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}

void menuProduccionN(Interfaz* interfaz){
    string ej = "";
    int num = 0;

    string name = "";
    string genNuevo = "";

    if(num != 4){
        cout<<"1.- Mostrar Softwares de Ofimatica "<<endl;
        cout<<"2.- Trabajar en un sofware(Add archivo) "<<endl;
        cout<<"3.- Eliminar trabajo(Delete arch) "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirOfimatica();
                menuProduccionN(interfaz);
                break;

            case 2:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->addArch(ej);
                menuProduccionN(interfaz);
                break;

            case 3:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->deleteArch(ej);
                menuProduccionN(interfaz);
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
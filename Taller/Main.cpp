#include <iostream>
#include "Interfaz.h"

using namespace std;

void menuNino();
void menuAdmin();
void menuNormal();
void logine(bool log);
void menuJuegos(Interfaz *interfaz);
void menuOfimatica(Interfaz * interfaz);
void menuProduccionN(Interfaz* interfaz);
void menuNavegador(Interfaz* interfaz);
void menuSocial(Interfaz* interfaz);
void switchNormal(Interfaz* interfaz, int op,int numero);
int reLog();
string name; string pass; int age;int numero;
int main(int argc, char const *argv[]){
    Interfaz *interfaz = new Interfaz();

    interfaz -> cargarBase();
    cout<<"Base de datos lista"<<endl;

    numero = 0;
    bool log = true;

    logine(log);
    while(numero != -1){
            
            log = interfaz ->login(name,pass);
            if(log != false){
                int age = interfaz->returnEdad();
                if(age == 99999){
                    menuAdmin();


                }else if(age < 18){
                    menuNino();


                }else if(age >17){
                    int op = -1;
                    int num = 0;

                    while(op != 6){
                        menuNormal();
                        cout << "Ingrese opcion: " << endl;
                        cin >> op;
                        switchNormal(interfaz,op,numero);

                    }   

                    


                    
                }

        
            }
            logine(log);
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
void logine(bool log){
    int a = 0;
do {
    cout << "1.- Loguear." << endl;
    cout << "2.- Salir." << endl;
    cin >> a;

    if (a != 1 && a != 2) {
        cout << "Ingrese una opcion valida." << endl;
    }
} while (a != 1 && a != 2);

if (a == 1) {
    cout << "--------Login--------" << endl;
    cout << "Ingrese Nombre: ";
    cin >> name;
    cout << "Ingrese Contrasena: ";
    cin >> pass;
} else {
    numero = -1;
    log = false;
}
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

void menuOfimatica(Interfaz* interfaz){
        string ej = "";
    int num = 0;

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Ofimatica "<<endl;
        cout<<"2.- Trabajar en un sofware(Add archivo) "<<endl;
        cout<<"3.- Eliminar trabajo(Delete arch) "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirOfimatica();
                
                break;

            case 2:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->addArch(ej);
                
                break;

            case 3:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->deleteArch(ej);
                
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

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Produccion "<<endl;
        cout<<"2.- Cambiar de tipo un software "<<endl;
        cout<<"3.- Mostrar tipos de Softawares "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirProduccion();
                break;

            case 2:
                cout<<"\nIngrese nombre del Software de produccion: "<<endl;
                cin>>name;
                cout<<"\nIngrese tipo nuevo: "<<endl;
                cin>>genNuevo;

                interfaz->cambiarTipoProduccion(name,genNuevo);
                break;

            case 3:
                interfaz->deleteArch(ej);
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}

void menuNavegador(Interfaz* interfaz){
    string ej = "";
    string ej1="";
    int num = 0;
    string url = "";
    string nav = "";

    while(num != 4){
        cout<<"1.- Mostrar Navegadores "<<endl;
        cout<<"2.- Mostrar historial "<<endl;
        cout<<"3.- Borrar Historial "<<endl;
        cout<<"4.- Agregar Pagina al historial"<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirNavegador();
                break;

            case 2:
                cout<<"Ingrese el nombre del navegador: "<<endl;
                cin>>ej;
                interfaz->mostrarHistorial(ej);
                break;

            case 3:
                cout<<"Ingrese el nombre del navegador para borrar el historial: "<<endl;
                cin>>ej1;
                interfaz->eliminarHistorial(ej1);
                break;

            case 4:
                cout<<"Ingrese el nombre del navegador: "<<endl;
                cin>>nav;
                cout<<"Ingrese el URL: "<<endl;
                cin>>url;
                interfaz->agregarPagHistorial(nav,url);
                break;

            case 5:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}

void menuSocial(Interfaz* interfaz){ //FALTA TERMINAR
    string ej = "";
    int num = 0;

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Ofimatica "<<endl;
        cout<<"2.- Trabajar en un sofware(Add archivo) "<<endl;
        cout<<"3.- Eliminar trabajo(Delete arch) "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirOfimatica();
                
                break;

            case 2:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->addArch(ej);
                
                break;

            case 3:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>ej;
                interfaz->deleteArch(ej);
                
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}

void switchNormal(Interfaz* interfaz, int op,int numero){
                switch(op){
                    case 1:
                        menuJuegos(interfaz);
                        break;

                    case 2:
                        menuOfimatica(interfaz);
                        break;

                    case 3: 
                        menuProduccionN(interfaz);
                        break;

                    case 4:
                        cout<<"a"<<endl;

                        break;

                    case 5:
                        cout<<"a"<<endl;

                        break;

                    case 6:
                        break;

                    default:
                        cout << "Número ingresado inválido" << endl;
                        break;
                }
}

int reLog(){
    int elec = 0;
    cout<<"Desea re-loguear(1) o Salir(2). "<<endl;
    cin>>elec;
    while(elec!=1 && elec!=2){
        cout<<"Invalido, seleccione nuevamente. "<<endl;
        cin>>elec;
    }
    if(elec=1){
        return 1;
    }else{
        return 2;
    }

}
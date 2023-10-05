#include <iostream>
#include "Interfaz.h"

using namespace std;

void menuNino();
void menuAdmin();
void menuNormal();
void login();
void menuJuegos(int num);
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
            cout<<"Ingrese opcion: "<<endl;
            cin>>op;
            switch(op){
                case 1:
                        
                    cout<<"a"<<endl;
                    break;

                case 2:
                    cout<<"a"<<endl;
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




            }

        }





    }
    cout<<"Paso! "<<endl;

   



    return 0;
}


void menuNino(){
    cout<<"         Menu            "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Navegador "<<endl;
    cout<<"3.- Social "<<endl;
    cout<<"4.- Salir "<<endl;

}

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

void menuNormal(){
    cout<<"         Menu             "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Produccion  "<<endl;
    cout<<"4.- Navegador "<<endl;
    cout<<"5.- Social "<<endl;
    cout<<"6.- Salir "<<endl;
}

void login(){
    cout<<"--------Login--------"<<endl;
    cout<<"Ingrese Nombre: "<<endl;
    cin>> name;
    cout<<"Ingrese Contrasena: "<<endl;
    cin >> pass;
    return;
}

void menuJuegos(int num,Interfaz* interfaz){
    string ej = "";
    while(num != -1){
        cout<<"1.- Mostrar Juegos "<<endl;
        cout<<"2.- Jugar algun juego "<<endl;
        cout<<"3.- Cambiar genero de un juego "<<endl;
        cout<<"4.- Volver. ";
        cin>>num;

        if(num = 1){
            interfaz ->imprimirJuegos();
        }else if (num =2)
        {
            cout<<"Ingrese nombre del Juego "<<endl;
            cin>>ej;
            interfaz->jugarJuego(ej);
        }
        

    }
}



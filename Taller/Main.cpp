#include <iostream>
#include "Interfaz.h"

using namespace std;

void menuNino();
void menuAdmin();
void menuNormal();
void login();
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
            cout<<"Ingrese opcion: "<<endl;

            switch(op){
                case 1:
                        cout<<"a"<<endl;
                    break;

                case 2:

                    break;

                case 3: 

                    break;

                case 4:

                    break;

                case 5:

                    break;

                case 6:

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




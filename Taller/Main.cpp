#include <iostream>
#include "Interfaz.h"

using namespace std;

void menuNino();
void menuAdmin();
void menuNormal();
void logine(bool log,Interfaz* interfaz);
void menuJuegos(Interfaz *interfaz);
void menuJuegosAdmin(Interfaz *interfaz);
void menuOfimatica(Interfaz * interfaz);
void menuProduccionN(Interfaz* interfaz);
void menuProduccionAdmin(Interfaz* interfaz);
void menuNavegador(Interfaz* interfaz);
void menuNavegadorAdmin(Interfaz* interfaz);
void menuSocial(Interfaz* interfaz);
void menuSocialAdmin(Interfaz* interfaz);
void menuOfimaticaAdmin(Interfaz * interfaz);
void switchNormal(Interfaz* interfaz, int op,int numero);
void switchAdmin(Interfaz* interfaz, int op,int numero);
void switchNino(Interfaz* interfaz, int op,int numero);
void menuSeguridadAdmin(Interfaz* interfaz);
void crearUser(Interfaz *interfaz);
void crearAdmin(Interfaz *interfaz);
string name; string pass; int age;int numero;
int op;int num;
int main(int argc, char const *argv[]){
    Interfaz *interfaz = new Interfaz();
    interfaz -> cargarBase();
    cout<<"Base de datos lista"<<endl;

    numero = 0;
    bool log = true;

    logine(log,interfaz);
    while(numero != -1){
            log = interfaz ->login(name,pass);
            if(log != false){
                int age = interfaz->returnEdad();
                if(age == 99999){
                    op = -1;
                    num = 0;
                    while(op!= 8){
                         menuAdmin();
                         cout<<"Ingrese opcion: "<< endl;
                         cin>>op;
                         switchAdmin(interfaz,op,numero);
                    }
                }else if(age < 18){      
                    op = -1;
                    num = 0;
                    while(op!=5){
                        menuNino();
                        cout << "Ingrese opcion: " << endl;
                        cin >> op;
                        switchNino(interfaz,op,numero);
                    }
                }else if(age >17){
                    op = -1;
                    num = 0;
                    while(op != 6){
                        menuNormal();
                        cout << "Ingrese opcion: " << endl;
                        cin >> op;
                        switchNormal(interfaz,op,numero);
                    }   
                }
            }
            logine(log,interfaz);
    }
    cout<<"Log Out! "<<endl;
    return 0;
}

//Imprime menu del nino
void menuNino(){
    cout<<"         Menu            "<<endl;
    cout<<"1.- Juegos "<<endl;
    cout<<"2.- Ofimatica "<<endl;
    cout<<"3.- Navegador "<<endl;
    cout<<"4.- Social "<<endl;
    cout<<"5.- Salir "<<endl;

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
    cout<<"7.- Crear un Admin"<<endl;
    cout<<"8.- Salir "<<endl;
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
void logine(bool log,Interfaz* interfaz){
    int a = 0;
do {
    cout << "1.- Loguear." << endl;
    cout<<"2.- Crear Usuario"<<endl;
    cout << "3.- Salir." << endl;
    cin >> a;

    if (a != 1 && a != 2 && a != 3 ) {
        cout << "Ingrese una opcion valida." << endl;
    }
} while (a != 1 && a != 2 && a != 3);

if (a == 1) {
    cout << "--------Login--------" << endl;
    cout << "Ingrese Nombre: ";
    cin >> name;
    cout << "Ingrese Contrasena: ";
    cin >> pass;
} else if(a == 2){
    crearUser(interfaz);
}else{
    numero = -1;
    log = false;
}
}
//Menu juegos
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
//Menu Software Ofimatica
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
//Menu Software Produccion
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
                cout<<"\n Numero ingresado invalido "<<endl;
                break;
        }
        

    }
}
//Menu Software Navegacion
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
//Menu Software Social
void menuSocial(Interfaz* interfaz){ //FALTA TERMINAR
    string ej = "";
    int num = 0;

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Social "<<endl;
        cout<<"2.- Add amigo "<<endl;
        cout<<"3.- Delete amigo "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz -> imprimirSocial();
                break;

            case 2:

                
                break;

            case 3:

                
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Opciones del Usuario Normal
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
                        menuNavegador(interfaz);

                        break;

                    case 5:
                        menuSocial(interfaz);

                        break;

                    case 6:
                        break;

                    default:
                        cout << "Número ingresado inválido" << endl;
                        break;
                }
}
//Opcion de relogueo

//Opciones del Usuario Admin
void switchAdmin(Interfaz* interfaz, int op,int numero){
                switch(op){
                    case 1:
                        menuJuegosAdmin(interfaz);
                        break;

                    case 2:
                        menuOfimaticaAdmin(interfaz);
                        break;

                    case 3: 
                        menuProduccionAdmin(interfaz);
                        break;

                    case 4:
                        menuNavegadorAdmin(interfaz);
                        break;

                    case 5:
                        menuSeguridadAdmin(interfaz);
                        break;

                    case 6:
                        menuSocialAdmin(interfaz);
                        break;

                    case 7:
                        crearAdmin(interfaz);
                        break;

                    case 8:
                        break;
                    default:
                        cout << "Número ingresado inválido" << endl;
                        break;
                }
}
//Menu juegos Admin
void menuJuegosAdmin(Interfaz* interfaz){
    string ej = "";
    int num = 0;
    int edad = 0;
    int precio;
    string name = "";
    string genNuevo = "";
    string dev="";

    while(num != 5){
        cout<<"1.- Mostrar Juegos "<<endl;
        cout<<"2.- Agregar Juego "<<endl;
        cout<<"3.- Eliminar Juego "<<endl;
        cout<<"4.- Mostrar el registro de Usuarios de un juego 'X' . "<<endl;
        cout<<"5.- Volver. "<<endl;     
        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirJuegos();           
                break;

            case 2:
                cout<<"\nIngrese nombre del juego (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"\nIngrese genero del juego: "<<endl;
                cin>>genNuevo;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;
                interfaz->agregarSoftJuego(name,dev,edad,precio,genNuevo);
                break;
            
            case 3:
                cout<<"\nIngrese nombre del juego (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                interfaz -> eliminarJuego(name);
                break;

            case 4:
                cout<<"\nIngrese nombre del juego (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                interfaz->mostrarUsuariosJuego(name);    
                break;

            case 5:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Menu ofimatica Admin
void menuOfimaticaAdmin(Interfaz* interfaz){
    int edad = 0;
    int precio;
    string name = "";
    string genNuevo = "";
    string dev="";
    int num = 0;

    while(num != 5){
        cout<<"1.- Mostrar Softwares de Ofimatica "<<endl;
        cout<<"2.- Add Software de Ofiimatica "<<endl;
        cout<<"3.- Eliminar Software de Ofimatica "<<endl;
        cout<<"4.- Mostrar el registro de Usuarios de un software de Ofimatica 'X' . "<<endl;
        cout<<"5.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirOfimatica();
                break;

            case 2:
                cout<<"\nIngrese nombre del Software (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;
                interfaz->agregarSoftOfimatica(name,dev,edad,precio);
                break;

            case 3:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>name;
                interfaz->eliminarOfimatica(name);          
                break;

            case 4:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>name;
                interfaz ->mostrarUsuariosOfimatica(name);
                break;

            case 5:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Menu Produccion admin
void menuProduccionAdmin(Interfaz* interfaz){
    string ej = "";
    int num = 0;
    int edad = 0;
    int precio;
    string name = "";
    string tipo = "";
    string dev="";

    while(num != 5){
        cout<<"1.- Mostrar Softwares de Produccion "<<endl;
        cout<<"2.- Add Produccion "<<endl;
        cout<<"3.- Delete Produccion "<<endl;
        cout<<"4.- Mostrar el registro de Usuarios de un software de Produccion 'X' . "<<endl;
        cout<<"5.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirProduccion();
                break;

            case 2:
                cout<<"\nIngrese nombre del Software (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"\nIngrese tipo de produccion: "<<endl;
                cin>>tipo;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;

                interfaz->agregarSoftProduccion(name,dev,edad,precio,tipo);
                break;

            case 3:
                cout<<"\nIngrese nombre del Software (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                interfaz -> eliminarProduccion(name);
                break;

            case 4:
                cout<<"\nIngrese nombre del sofware de Ofimatica "<<endl;
                cin>>name;
                interfaz->mostrarUsuariosProduccion(name);
                break;
            case 5:
                break;

            default:
                cout<<"\n Numero ingresado invalido "<<endl;
                break;
        }
        

    }
}
//Menu navegador admin
void menuNavegadorAdmin(Interfaz* interfaz){
    string ej = "";
    int num = 0;
    int edad = 0;
    int precio;
    string name = "";
    string tipo = "";
    string dev="";

    while(num != 4){
        cout<<"1.- Mostrar Navegadores "<<endl;
        cout<<"2.- Agregar Navegador "<<endl;
        cout<<"3.- Eliminar navegador "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz ->imprimirNavegador();
                break;

            case 2:
                cout<<"\nIngrese nombre del Navegador (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;
                interfaz->agregarSoftNavegador(name,dev,edad,precio);
                break;

            case 3:
                cout<<"Ingrese el nombre del navegador : "<<endl;
                cin>>name;
                interfaz->eliminarNavegador(name);
                break;

            case 4:
                break;
            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Menu Social Admin
void menuSocialAdmin(Interfaz* interfaz){ //FALTA TERMINAR
    string ej = "";
    int num = 0;
    int edad = 0;
    int precio;
    string name = "";
    string tipo = "";
    string dev="";

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Social "<<endl;
        cout<<"2.- Agregar Software social "<<endl;
        cout<<"3.- Eliminar Software social "<<endl;
        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz -> imprimirSocial();
                break;

            case 2:
                cout<<"\nIngrese nombre del Soft Social (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;
                interfaz -> agregarSoftSocial(name,dev,edad,precio);
                break;

            case 3:
                cout<<"\nIngrese nombre del Soft Social (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                interfaz -> eliminarSocial(name);
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Menu Seguridad Admin
void menuSeguridadAdmin(Interfaz* interfaz){ //FALTA TERMINAR
    string ej = "";
    int num = 0;
    int edad = 0;
    int precio;
    string name = "";
    string tipo = "";
    string dev="";

    while(num != 4){
        cout<<"1.- Mostrar Softwares de Seguidad "<<endl;
        cout<<"2.- Agregar Software de Seguridad "<<endl;
        cout<<"3.- Eliminar Software de Seguridad "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;

        cout<<"4.- Volver. "<<endl;

        cin>>num;

        switch (num){
            case 1:
                interfaz -> imprimirSocial();
                break;

            case 2:
                cout<<"\nIngrese nombre del Soft de Seguidad (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                cout<<"Ingrese la compania/dev:"<<endl;
                cin>>dev;
                cout<<"Ingrese la edad minima :"<<endl;
                cin>>edad;
                cout<<"Ingrese el precio (ej 5.99): "<<endl;
                cin>>precio;
                cout<<"Ingrese el tipo de software "<<endl;
                cin>>tipo;
                interfaz -> agregarSoftSeguridad(name,dev,edad,precio,tipo);
                break;

            case 3:
                cout<<"\nIngrese nombre del Soft de Seguridad (Reemplazar los espacios con '_' ): "<<endl;
                cin>>name;
                interfaz -> eliminarSeguridad(name);
                break;

            case 4:
                break;

            default:
                cout<<"\n Numero ingresado invalido"<<endl;
                break;
        }
        

    }
}
//Opciones del Usuario Nino
void switchNino(Interfaz* interfaz, int op,int numero){
                switch(op){
                    case 1:
                        menuJuegos(interfaz);
                        break;

                    case 2:
                        menuOfimatica(interfaz);
                        break;

                    case 3: 
                        menuNavegador(interfaz);
                        break;

                    case 4:
                        menuSocial(interfaz);
                        break;

                    case 5:
                        break;

                    default:
                        cout << "Número ingresado inválido" << endl;
                        break;
                }
}
//Opciones de crear usuario desde el interfaz
void crearUser(Interfaz *interfaz){
    int ed;string crr;
    cout<<"Ingrese edad: "<<endl;
    cin>>ed;
    while(ed<1 || ed>99){
        cout<<"Edad invalida: "<<endl;
        cin>>ed;
    }

    if(ed>17){
        cout<<"Ingrese nombre: "<<endl;
        cin>>name;
        cout<<"Ingrese correo: "<<endl;
        cin>>crr;
        cout<<"Ingrese contrasena: "<<endl;
        cin>>pass;
        interfaz->agregarUserNormal(name,pass,ed,crr);

    }else{
        cout<<"Ingrese nombre: "<<endl;
        cin>>name;
        cout<<"Ingrese contrasena: "<<endl;
        cin>>crr;
        interfaz->agregarUserNino(name,pass,ed);
    }
}
//Crea admind, desde el menu de admin
void crearAdmin(Interfaz *interfaz){
        int ed = 0;string crr;
        cout<<"Ingrese nombre: "<<endl;
        cin>>name;
        cout<<"Ingrese correo: "<<endl;
        cin>>crr;
        cout<<"Ingrese contrasena: "<<endl;
        cin>>pass;
        interfaz->agregarUserAdmin(name,pass,ed,crr);

}

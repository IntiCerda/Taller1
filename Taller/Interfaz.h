#pragma once
#include <iostream>
#include "ListaNodoSoft.h"
#include "ListaNodoUser.h"

using namespace std;

class Interfaz{
    private:
        ListaNodoSoft *todoSoft;
        ListaNodoUser *todoUser;
        string juegos[10];
        string solucion[4];
        string malware[6];
        User *usuario;
        

    public:
        Interfaz();
        void agregarUserNormal(string, string, int, string);
        void agregarUserNino(string, string, int);
        void agregarUserAdmin(string,string,int,string);
        bool login(string,string);
        
        void agregarSoftNavegador(string, string, int, float);
        void agregarSoftOfimatica(string,string,int,float);
        void agregarSoftProduccion(string,string,int,float,string);
        void agregarSoftSeguridad(string,string,int,float,string);
        void agregarSoftSocial(string,string,int,float);
        void agregarSoftJuego(string,string,int,float,string);
        int returnEdad();
        void cargarBase();
        void imprimirJuegos();
        void jugarJuego(string);

};

Interfaz :: Interfaz(){
    todoSoft = new ListaNodoSoft();
    todoUser = new ListaNodoUser();
    usuario = NULL;
    juegos[0] = "accion"; juegos[1] = "aventura" ; juegos[2] = "RPG"; juegos[3] = "estrategia"; juegos[4] = "MMO"; juegos[5] = "FPS";
    juegos[6] = "puzzle"; juegos [7] = "simulacion"; juegos[8] = "horror"; juegos[9] = "deportes";

    solucion[0] = "video"; solucion[1] = "musica"; solucion[2] = "streaming"; solucion[3] = "fotos";
    
    malware[0] ="ransomware"; malware[1] = "spyware"; malware[2] = "botnets"; malware[3] = "rootkits"; malware[4]="gusanos"; malware[5] ="troyanos";
}


void Interfaz::agregarUserNormal(string nombre, string pass, int edad, string correo) {
    User *usser = new UserNormal(nombre, pass, edad, correo);
    todoUser->agregarUser(usser);
    return;
    
}

void Interfaz :: agregarUserNino(string nombre, string pass, int edad){
    User *user = new Nino(nombre, pass, edad);
    todoUser -> agregarUser(user);
    
    return;
}

void Interfaz:: agregarUserAdmin(string nombre, string pass, int edad,string correo){
    User *user = new Admin(nombre,pass,edad,correo);
    todoUser ->agregarUser(user);
    return;
}

void Interfaz :: agregarSoftJuego(string nombre, string developer, int edad, float precio, string genero){
    for(int i = 0; i<10;i++){
        if(genero == juegos[i]){
            Software *juego = new Juego(nombre, developer, edad, precio, genero);
            todoSoft -> agregarSoft(juego);
            return;
        }
    }
     cout<< "Genero no encontrado, pruebe con uno de estos: n/"<<endl;
     string r = " ";
     for(int k =0;k<10 ;k++){
        r = r + juegos[k] +", ";
     }
     cout<< r << endl;


    return;
}   

void Interfaz :: agregarSoftNavegador(string nombre, string developer, int edad, float precio){
    Software *navegador = new Navegador(nombre,  developer,edad,precio);
    todoSoft -> agregarSoft(navegador);
    return;
}

void Interfaz :: agregarSoftOfimatica(string nombre, string developer, int edad, float precio){
    Software *ofimatica = new Ofimatica(nombre,developer,edad, precio);
    todoSoft -> agregarSoft(ofimatica);
}

void Interfaz :: agregarSoftProduccion(string nombre, string developer, int edad, float precio, string tipo){
    for(int i = 0; i<4;i++){
        if(tipo == solucion[i]){
             Software *prod = new Produccion(nombre,developer,edad,precio,tipo);
             todoSoft -> agregarSoft(prod);
             return;
        }
    }
    cout<< "Tipo de solucion no encontrado, pruebe con uno de estos: n/"<<endl;
    string r = " ";
    for(int k =0;k<4 ;k++){
        r = r + solucion[k] +", ";
    }
    cout<< r << endl;
   
}

void Interfaz :: agregarSoftSeguridad(string nombre, string developer, int edad, float precio,string tipo){
    for(int i = 0; i<6; i++){
        if(tipo == malware[i]){
            Software *malw = new Seguridad(nombre,developer,edad,precio,tipo);
            todoSoft -> agregarSoft(malw);
            return;

        }
    }
    cout<< "Tipo de Software de Seguridad no encontrado, pruebe con uno de estos: n/"<<endl;
    
    string r = " ";
    for(int k =0;k<6 ;k++){
        r = r + malware[k] +", ";
    }
    cout<< r << endl;

}

void Interfaz :: agregarSoftSocial(string nombre, string developer, int edad, float precio){
        Software *social = new Social(nombre,developer,edad,precio);
        todoSoft-> agregarSoft(social);
        return;
}

//Carga la base de datos con usuarios y softwares
void Interfaz :: cargarBase(){
    agregarUserNormal("juanlopez", "clave123", 25, "juan.lopez@example.com");
    agregarUserNormal("mariaperez", "abc456", 30, "maria.perez@example.com");
    agregarUserNormal("carlosrodriguez", "p4ssw0rd", 40, "carlos.rodriguez@example.com");
    agregarUserNormal("lauragonzalez", "securePass", 18, "laura.gonzalez@example.com");
    agregarUserNormal("pedromartinez", "mySecret123", 65, "pedro.martinez@example.com");
    agregarUserNormal("anacastro", "qwerty", 50, "ana.castro@example.com");
    agregarUserNormal("andrescortes", "adminPass", 22, "andres.cortes@example.com");
    agregarUserNormal("luisruiz", "testPassword", 75, "luis.ruiz@example.com");
    agregarUserNormal("elenagomez", "12345678", 19, "elena.gomez@example.com");
    agregarUserNormal("javierlopez", "password123", 55, "javier.lopez@example.com");
    

    agregarUserNino("lucasgonzalez", "clave456", 16);
    agregarUserNino("isabellaruiz", "abc789", 14);
    agregarUserNino("martinlopez", "p4ssw0rd2", 17);
    agregarUserNino("valentinaperez", "securePass2", 15);
    

    agregarUserAdmin("Admin", "admin123",0,"admin@example.com");
    

    
    agregarSoftJuego("The Witcher 3: Wild Hunt", "CD Projekt RED",17,29.99, "aventura");    //18+
    agregarSoftJuego("Minecraft", "Mojang",1,26.95,"aventura");

    agregarSoftJuego("Grand Theft Auto V", "Rockstar Games",1,29.99,"accion");
    agregarSoftJuego("Red Dead Redemption 2", "Rockstar Games",17,59.99,"accion");      //18+

    agregarSoftJuego("The Legend of Zelda: Breath of the Wild", "Nintendo",1,59.99,"MMO");
    agregarSoftJuego("The Division 2", "Ubisoft",1,29.99,"MMO");

    agregarSoftJuego("Animal Crossing: New Horizons", "Nintendo",1,59.99,"simulacion");
    agregarSoftJuego("Forza Horizon 4", "Playground Games",1,59.99,"simulacion");

    agregarSoftJuego("Among Us", "Innersloth",1,5.99,"horror");
    agregarSoftJuego("Resident Evil 7: Biohazard", "Capcom",17,19.99,"horror");     //18+

    agregarSoftJuego("Overwatch", "Blizzard Entertainment",1,19.99,"FPS");
    agregarSoftJuego("Cyberpunk 2077", "CD Projekt RED",17,49.99,"FPS");    //18+

    agregarSoftJuego("FIFA 22", "Electronic Arts",1,59.99,"deportes");
    agregarSoftJuego("FIFA 21", "Electronic Arts",1,39.99,"deportes");

    agregarSoftJuego("Hades", "Supergiant Games",1,24.99,"puzzle");
    agregarSoftJuego("Portal 2", "Valve Corporation",1,9.99,"puzzle");
    
    agregarSoftJuego("The Elder Scrolls V: Skyrim", "Bethesda Game Studios",1,39.99,"RPG");
    agregarSoftJuego("Dark Souls III", "FromSoftware",17,59.99,"RPG");  //18+

    agregarSoftJuego("Civilization VI", "Firaxis Games",1,59.99,"estrategia");
    agregarSoftJuego("Total War: Three Kingdoms", "Creative Assembly",1,59.99,"estrategia");

    
    
    agregarSoftOfimatica("SoftMaker Office", "SoftMaker Software GmbH",1,69.50);
    agregarSoftOfimatica("OfficeSuite", "MobiSystems",1,29.99);
    agregarSoftOfimatica("Corel WordPerfect Office", "Corel Corporation",1,149.99);
    agregarSoftOfimatica("WordPerfect Office", "Corel Corporation",1,249.99);
    agregarSoftOfimatica("Polaris Office", "Infraware Inc.",1,6.99);

    

    agregarSoftProduccion("Adobe Premiere Pro", "Adobe Inc.",17,20.99,"video");
    agregarSoftProduccion("Ableton Live", "Ableton AG",17,99.00,"musica");
    agregarSoftProduccion("OBS Studio",  "OBS Project",17,0,"streaming");
    agregarSoftProduccion("Adobe Photoshop","Adobe Inc.",17,20.99,"fotos");

    

    agregarSoftNavegador("Google Chrome","Google LLC",1,0);
    agregarSoftNavegador("Mozilla Firefox", "Mozilla Corporation",1,0);

    

    agregarSoftSeguridad("Cryptolock 2023", "Hackers Anónimos",99999,99,"ransomware");
    agregarSoftSeguridad("SpyMaster Pro","Surveillance Tech Inc.",99999,79.99,"spyware");
    agregarSoftSeguridad("BotNetBot","Cyber Criminals Ltd.",99999,99.99,"botnets");
    agregarSoftSeguridad( "StealthRoot 9000", "Underground Hackers Co.",99999,135.75,"rootkits");
    agregarSoftSeguridad("NetWorm-X","Unknown",99999,100.99,"gusanos");
    agregarSoftSeguridad("KeyloggerTroj","Malicious Softworks",99999,49.99,"troyanos");

    


    agregarSoftSocial("Facebook", "Meta Platforms, Inc.",1,0);
    agregarSoftSocial("LinkedIn","LinkedIn Corporation",17,29.99);



}

bool Interfaz :: login(string name, string pass){
    User *aux = NULL;
    aux = todoUser->buscarUserPorNombreYContrasena(name,pass);
    if(aux == NULL){
        cout<<"Usuario no encontrado"<<endl;
        return false;
    }else{
        usuario = aux;
        cout<<"Bienvenido de vuelta "<< usuario -> getNombre()<<endl;
        return true;
    }

}

int Interfaz :: returnEdad(){
    return usuario->getEdad();
};

void Interfaz :: imprimirJuegos(){
    todoSoft->imprimirJuegos();
}

void Interfaz :: jugarJuego(string name){
    Juego *game = todoSoft->retornarJuegoPorNombre(name); 
    //Aqui iba una funcion para jugar pero hacerla por juego no me dio el tiempo
    if(todoSoft->existeJuegoPorNombre(name)){
        cout<<"Jugando... o algo asi "<<endl;
    }else{
        cout<<"Juego no encontrado. "<<endl;
    };
}
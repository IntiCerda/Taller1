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
        void mostrarGeneroJuegos();
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
        void cambiarGeneroJuego(string,string);
        void imprimirOfimatica();
        void addArch(string);
        void deleteArch(string);
        void imprimirProduccion();
        void cambiarTipoProduccion(string, string);
        void mostrarTipoProd();
        void imprimirNavegador();
        void mostrarHistorial(string);
        void eliminarHistorial(string);
        void agregarPagHistorial(string,string);
        void imprimirSocial();
        void imprimirSeguridad();
        void eliminarJuego(string);
        void eliminarOfimatica(string );
        void eliminarProduccion(string );
        void eliminarNavegador(string );
        void eliminarSocial(string );
        void eliminarSeguridad(string);
        void mostrarUsuariosJuego(string);
        void mostrarUsuariosOfimatica(string);
        void mostrarUsuariosProduccion(string);
};
//Constructor
Interfaz :: Interfaz(){
    todoSoft = new ListaNodoSoft();
    todoUser = new ListaNodoUser();
    usuario = NULL;
    juegos[0] = "accion"; juegos[1] = "aventura" ; juegos[2] = "RPG"; juegos[3] = "estrategia"; juegos[4] = "MMO"; juegos[5] = "FPS";
    juegos[6] = "puzzle"; juegos [7] = "simulacion"; juegos[8] = "horror"; juegos[9] = "deportes";

    solucion[0] = "video"; solucion[1] = "musica"; solucion[2] = "streaming"; solucion[3] = "fotos";
    
    malware[0] ="ransomware"; malware[1] = "spyware"; malware[2] = "botnets"; malware[3] = "rootkits"; malware[4]="gusanos"; malware[5] ="troyanos";
}

//Agregar Usuario normal
void Interfaz::agregarUserNormal(string nombre, string pass, int edad, string correo) {
    if(edad>17){
        User *usser = new UserNormal(nombre, pass, edad, correo);
        todoUser->agregarUser(usser);
    }else{
        cout<<"Edad insuficiente para crear un usuario normal"<<endl;
    }
    return;
    
}
//Agregar Usuario nino
void Interfaz :: agregarUserNino(string nombre, string pass, int edad){
    if(edad<18){
        User *user = new Nino(nombre, pass, edad);
        todoUser -> agregarUser(user);
    }else{
        cout<<"Edad insuficiente para crear un usuario nino"<<endl;
    }

    
    return;
}
//Agregar Usuario Admin
void Interfaz:: agregarUserAdmin(string nombre, string pass, int edad,string correo){
    User *user = new Admin(nombre,pass,edad,correo);
    todoUser ->agregarUser(user);
    return;
}
//Agregar Software Juego
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
//Agregar Software Navegador
void Interfaz :: agregarSoftNavegador(string nombre, string developer, int edad, float precio){
    Software *navegador = new Navegador(nombre,  developer,edad,precio);
    todoSoft -> agregarSoft(navegador);
    return;
}
//Agregar Software Ofimatica
void Interfaz :: agregarSoftOfimatica(string nombre, string developer, int edad, float precio){
    Software *ofimatica = new Ofimatica(nombre,developer,edad, precio);
    todoSoft -> agregarSoft(ofimatica);
}
//Agregar Software Produccion
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
//Agregar Software Seguridad
void Interfaz :: agregarSoftSeguridad(string nombre, string developer, int edad, float precio,string tipo){
    for(int i = 0; i<6; i++){
        if(tipo == malware[i]){
            if(edad>17){
                Software *malw = new Seguridad(nombre,developer,edad,precio,tipo);
                todoSoft -> agregarSoft(malw);
                return;
            }else{
                cout<<"edad invalida "<<endl;
                return;
            }
        }
    }
    cout<< "Tipo de Software de Seguridad no encontrado, pruebe con uno de estos: n/"<<endl;
    
    string r = " ";
    for(int k =0;k<6 ;k++){
        r = r + malware[k] +", ";
    }
    cout<< r << endl;

}
//Agregar Software Social
void Interfaz :: agregarSoftSocial(string nombre, string developer, int edad, float precio){
        Software *social = new Social(nombre,developer,edad,precio);
        todoSoft-> agregarSoft(social);
        return;
}

//Carga la base de datos con usuarios y softwares
//Existe una reaccion extrana al momento de compilar los string de la base de datos, los nombres generaran un error en la consola(solo los nombres con espacio)
//Reemplazar espacio por "_", gracias.

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
    

    
    agregarSoftJuego("The_Witcher_3", "CD Projekt RED",17,29.99, "aventura");    //18+
    agregarSoftJuego("Minecraft", "Mojang",1,26.95,"aventura");

    agregarSoftJuego("Grand_Theft_Auto_V", "Rockstar Games",1,29.99,"accion");
    agregarSoftJuego("Red_Dead_Redemption_2", "Rockstar Games",17,59.99,"accion");      //18+

    agregarSoftJuego("The_Legend_of_Zelda", "Nintendo",1,59.99,"MMO");
    agregarSoftJuego("The_Division_2", "Ubisoft",1,29.99,"MMO");

    agregarSoftJuego("Animal_Crossing", "Nintendo",1,59.99,"simulacion");
    agregarSoftJuego("Forza_Horizon_4", "Playground Games",1,59.99,"simulacion");

    agregarSoftJuego("Among_Us", "Innersloth",1,5.99,"horror");
    agregarSoftJuego("Resident_Evil_7: Biohazard", "Capcom",17,19.99,"horror");     //18+

    agregarSoftJuego("Overwatch", "Blizzard Entertainment",1,19.99,"FPS");
    agregarSoftJuego("Cyberpunk 2077", "CD Projekt RED",17,49.99,"FPS");    //18+

    agregarSoftJuego("FIFA_22", "Electronic Arts",1,59.99,"deportes");
    agregarSoftJuego("FIFA_21", "Electronic Arts",1,39.99,"deportes");

    agregarSoftJuego("Hades", "Supergiant Games",1,24.99,"puzzle");
    agregarSoftJuego("Portal_2", "Valve Corporation",1,9.99,"puzzle");
    
    agregarSoftJuego("Skyrim", "Bethesda Game Studios",1,39.99,"RPG");
    agregarSoftJuego("Dark_Souls_III", "FromSoftware",17,59.99,"RPG");  //18+

    agregarSoftJuego("Civilization_VI", "Firaxis Games",1,59.99,"estrategia");
    agregarSoftJuego("Total_War", "Creative Assembly",1,59.99,"estrategia");

    
    
    agregarSoftOfimatica("SoftMaker_Office", "SoftMaker Software GmbH",1,69.50);
    agregarSoftOfimatica("OfficeSuite", "MobiSystems",1,29.99);
    agregarSoftOfimatica("Corel_WordPerfect_Office", "Corel Corporation",1,149.99);
    agregarSoftOfimatica("WordPerfect_Office", "Corel Corporation",1,249.99);
    agregarSoftOfimatica("Polaris_Office", "Infraware Inc.",1,6.99);

    

    agregarSoftProduccion("Adobe_Premiere_Pro","Adobe_Inc.",17,20.99,"video");
    agregarSoftProduccion("Ableton_Live","Ableton_AG",17,99.00,"musica");
    agregarSoftProduccion("OBS_Studio","OBS Project",17,0,"streaming");
    agregarSoftProduccion("Adobe_Photoshop","Adobe_Inc.",17,20.99,"fotos");

    

    agregarSoftNavegador("Google_Chrome","Google LLC",1,0);
    agregarSoftNavegador("Mozilla_Firefox", "Mozilla Corporation",1,0);

    

    agregarSoftSeguridad("Cryptolock_2023", "Hackers_Anónimos",99999,99,"ransomware");
    agregarSoftSeguridad("SpyMaster_Pro","Surveillance_Tech",99999,79.99,"spyware");
    agregarSoftSeguridad("BotNetBot","CyberCriminals_Ltd.",99999,99.99,"botnets");
    agregarSoftSeguridad( "StealthRoot_9000", "Underground Hackers Co.",99999,135.75,"rootkits");
    agregarSoftSeguridad("NetWorm-X","Unknown",99999,100.99,"gusanos");
    agregarSoftSeguridad("KeyloggerTroj","Malicious Softworks",99999,49.99,"troyanos");

    


    agregarSoftSocial("Facebook", "Meta Platforms, Inc.",1,0);
    agregarSoftSocial("LinkedIn","LinkedIn Corporation",17,29.99);



}
//Funcion login, para verificar la existencia del usuario y setearlo para trabajar con el
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
//Retorna la edad del usuario 
int Interfaz :: returnEdad(){
    return usuario->getEdad();
};
//Imprime por pantalla los Juegos segun la edad del Usuario
void Interfaz :: imprimirJuegos(){
    todoSoft->imprimirJuegos(usuario->getEdad());
}
//Juega un juego ingresado por pantalla, dependiendo de la edad correspondiente juega o no
void Interfaz :: jugarJuego(string name){
    Juego *game = todoSoft->retornarJuegoPorNombre(name); 
    //Aqui iba una funcion para jugar pero hacerla por juego no me dio el tiempo

    bool exist = todoSoft->existeJuegoPorNombre(name);
    if(exist){
        if(usuario->getEdad() > game->getEdad()){
            cout<<"Jugando.. "<< game->getNombre()<< endl;
            game->getListaUser()->agregarUser(usuario);
            return;
        }else{
            cout<<"Edad insuficiente"<<endl;
            return;
        }
    }else{
        cout<<"Juego no encontrado"<<endl;
    }
    return;
}
//Imprime los generos disponibles para los juegos
void Interfaz :: mostrarGeneroJuegos(){
    for(int i =0; i<10; i++){
        cout<<juegos[i]<<endl;
    }

}
//Cambia el genero de un juego en especifico, ingresado por pantalla
void Interfaz :: cambiarGeneroJuego(string nameJuego, string newGenero){
    bool exist = false;
    for(int i =0; i<10; i++){
        if(newGenero == juegos[i]){
            exist = true;
        }
    }
    bool juegoExist = todoSoft->existeJuegoPorNombre(nameJuego);

    if(exist == true && juegoExist == true){
        Juego* juegazo = todoSoft->retornarJuegoPorNombre(nameJuego);
        juegazo ->cambioGenero(newGenero);
        juegazo->getListaUser()->agregarUser(usuario);
        cout<<"Cambio realizado correctamente. "<<endl;
        return;
    }else if(exist == false){
        cout<<"Genero no encontrado. "<<endl;
        return;

    }else if(juegoExist == false){
        cout<<"Juego no encontrado "<<endl;
        return;
    }
    return;

}
//Imprime los softwares de Ofimatica
void Interfaz :: imprimirOfimatica(){
    todoSoft->imprimirOfimatica();
}
//Add archivo de trabajo a un software de Ofimatica
void Interfaz :: addArch(string name){
    Ofimatica* offic = todoSoft->retornarOfimaticaPorNombre(name);
    if(offic!=NULL){
        offic->addArch();
        cout<<"Archivo agregado correctamente; "<<endl;
        usuario->sumaContador();
        offic->getListaUser()->agregarUser(usuario);
        return;

    }else{
        cout<<"Programa no encontrado... "<<endl;
        usuario -> restaContador();
        usuario->getCont();
    }

}
//Delete archivo de trabajo a un software de Ofimatica
void Interfaz :: deleteArch(string name){
    Ofimatica* offic = todoSoft->retornarOfimaticaPorNombre(name);
    if(offic!=NULL){
        offic->deleteArch();
        cout<<"Archivo eliminado correctamente; "<<endl;
        offic->getListaUser()->agregarUser(usuario);
        return;

    }else{
        cout<<"Programa no encontrado... "<<endl;
    }

}
//Imprime por pantalla los softwares de Produccion
void Interfaz :: imprimirProduccion(){
    todoSoft->imprimirProduccion();
}
//Cambia el tipo de un software e produccion en especifico a otro
void  Interfaz :: cambiarTipoProduccion(string name, string tipo){
    bool exist = false;
    for(int i = 0; i<4;i++){
        if(tipo == solucion[i]){
            exist = true;
        }
    }
    bool prodExist = todoSoft->existeProduccionPorNombre(name);

    if(exist==true && prodExist==true){
        Produccion *prodd = todoSoft->retornarProduccionPorNombre(name);
        prodd-> setTipo(tipo);
        prodd->getListaUser()->agregarUser(usuario);
        return;
    }else if(exist == false){
        cout<<"Tipo no encontrado. "<<endl;
        return;

    }else if(prodExist == false){
        cout<<"Produccion no encontrado "<<endl;
        return;
    }
    return;

}
//Muestra los tipos de Softwares de produccion existentes
void Interfaz :: mostrarTipoProd(){
    for(int i =0; i<4; i++){
        cout<<solucion[i]<<endl;
    }
}
//Imprime por pantalla los Softwares de Navegador
void Interfaz :: imprimirNavegador(){
    todoSoft->imprimirNavegador();

}
//Muestra el historial de un navegador en especifico
void Interfaz :: mostrarHistorial(string navegador){
    Navegador *aux = todoSoft->retornarNavegadorPorNombre(navegador);
    if(aux != NULL){
        aux->imprimirHistorial();
        aux->getListaUser()->agregarUser(usuario);
    } else{
        cout<<"nAVEGADOR NO ECONTRADO"<<endl;
    }
    return;
}
//Eliminna el historial de un navegador en especifico
void Interfaz :: eliminarHistorial(string navegador){
    Navegador *aux = todoSoft->retornarNavegadorPorNombre(navegador);
    if(aux!=NULL){
        aux -> limpiarHistorial();
        aux->getListaUser()->agregarUser(usuario);
    }else{
        cout<<"NAVEGADOR NO ECONTRADO"<<endl;
    }
    return;
}
//Agrega una pagina al historial de un Software en especifico
void Interfaz :: agregarPagHistorial(string nav, string url){
    Navegador *aux = todoSoft->retornarNavegadorPorNombre(nav);
    if(aux!=NULL){
        aux->agregarPag(url);
        cout<<"Pag agregada correctamente "<<endl;
        aux->getListaUser()->agregarUser(usuario);
    }else{
        cout<<"NAVEGADOR NO ECONTRADO"<<endl;
    }
    return;
}
//Elimina un juego de la base de datos
void Interfaz :: eliminarJuego(string name){
    Juego* juego = todoSoft->retornarJuegoPorNombre(name);
    if(juego != NULL){
        todoSoft->eliminarSoft(juego);
        
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Juego no encontrado. "<<endl;
    }
    
}
//Elimina un software de Ofimatica de la base
void Interfaz :: eliminarOfimatica(string name){
        Ofimatica* off = todoSoft->retornarOfimaticaPorNombre(name);
    if(off != NULL){
        todoSoft->eliminarSoft(off);
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Ofimatica no encontrado. "<<endl;
    }
}
//Elimina un software de Produccion de la base
void Interfaz :: eliminarProduccion(string name){
        Produccion* prod = todoSoft->retornarProduccionPorNombre(name);
    if(prod != NULL){
        todoSoft->eliminarSoft(prod);
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Produccion no encontrado no encontrado. "<<endl;
    }
}
//Elimina un navegador de la base de datos
void Interfaz :: eliminarNavegador(string name){
        Navegador* nav = todoSoft->retornarNavegadorPorNombre(name);
    if(nav != NULL){
        todoSoft->eliminarSoft(nav);
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Produccion no encontrado no encontrado. "<<endl;
    }
}
//Imprime los softwares Social disponibles
void Interfaz :: imprimirSocial(){
    todoSoft->imprimirSocial();

}
//Elimina un software Social de la base de datos
void Interfaz :: eliminarSocial(string name){
        Social* soc = todoSoft->retornarSocialPorNombre(name);
    if(soc != NULL){
        todoSoft->eliminarSoft(soc);
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Produccion no encontrado no encontrado. "<<endl;
    }
}
//Elimina un software de Seguridad de la base de dadots
void Interfaz :: eliminarSeguridad(string name){
        Seguridad* seg = todoSoft->retornarSeguridadPorNombre(name);
    if(seg != NULL){
        todoSoft->eliminarSoft(seg);
        cout<<"Eliminado correctamente "<<endl;
    }else{
        cout<<"Produccion no encontrado no encontrado. "<<endl;
    }
}
//Imprime por pantalla los softwares de seguridad  disponibles en la base
void Interfaz :: imprimirSeguridad(){
    todoSoft->imprimirSeguridad();
}
//Muestra los usuarios que han juegado un juego en especifico
void Interfaz :: mostrarUsuariosJuego(string name){
    Juego* juego = todoSoft->retornarJuegoPorNombre(name);
    if(juego != NULL){
        juego->getListaUser()->imprimirLista();
    }else{
        cout<<"Juego no encontrado. "<<endl;
    }
}
//Muestra los usuarios que han interactuado con un softare de Ofimatica en especifico
void Interfaz :: mostrarUsuariosOfimatica(string name){
    Ofimatica* off = todoSoft->retornarOfimaticaPorNombre(name);
    if(off != NULL){
        off->getListaUser()->imprimirLista();
    }else{
        cout<<"Juego no encontrado. "<<endl;
    }
}
//Muestra los usuarios que han interactuado con un software de Produccion en especifico
void Interfaz :: mostrarUsuariosProduccion(string name){
    Produccion* prod = todoSoft->retornarProduccionPorNombre(name);
    if(prod != NULL){
        prod->getListaUser()->imprimirLista();
    }else{
        cout<<"Juego no encontrado. "<<endl;
    }
}






#pragma once
#include<iostream>

using namespace std;

class User{
    
    private:
        string nombre;
        string pass;
        int edad;
        string correo;
        bool access;
        string amigos[30];
        int contAmigos;
        int cont; //cantArchivos
        int cantPag;
    
    public:
        User(string,string,int);
        ~User();
        
        string getNombre();
        string getPass();
        int getEdad();
        bool getAccess();
        string* getAmigos();
        string getCont();

        void agregarAmigo(string); 
        void setAccess(bool);
        void setEdad(int);
        void setNombre(string);
        void setPass(string);
        virtual string tipoUser() = 0; //Implementar en clases hijas
        virtual string toString() =0;
        void sumaContador();
        void restaContador();
    
};
//Constructor padre
User::User(string nombre, string pass, int edad){
    this -> nombre = nombre;
    this -> pass = pass;
    this -> edad = edad;
    this -> access = false;
    this -> cont = 0;
    this -> contAmigos =0;
    this -> cantPag=0;

    for (int i = 0; i < 30; i++) {
        amigos[i] = "";
    }


}
//Destructor
User::~User(){};
//Getter and setter
string User::getNombre(){
    return this -> nombre;
}
//Getter and setter
string User::getPass(){
    return this -> pass;
}
//Getter and setter
int User::getEdad(){
    return this -> edad;
}
//Getter and setter
bool User::getAccess(){
    return this -> access;
}
//Getter and setter
string* User::getAmigos() {
    return this->amigos;
}
//Retorna el contador de archivos creados por el usuario
string User:: getCont(){
    return "El numero de archivos creados por el usuario es: " + to_string(cont);
}

//Agrega a un amigo 
void User:: agregarAmigo(string nombreAmigo){
    this -> amigos[contAmigos] = nombreAmigo;
    contAmigos++;
}
//Quita uno de los archivos creados
void User:: restaContador(){
    this -> cont--;
}
//Agrega uno de los usuarios creados al contador
void User:: sumaContador(){
    this -> cont++;
}
//Getter and setter
void User::setAccess(bool access){
    this -> access = access;
}
//Getter and setter
void User::setNombre(string nombre){
    this -> nombre = nombre;
}
//Getter and setter
void User::setPass(string pass){
    this -> pass = pass;
}
//Getter and setter
void User::setEdad(int edad){
    this -> edad = edad;
}



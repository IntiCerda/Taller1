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
    
};

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

User::~User(){};

string User::getNombre(){
    return this -> nombre;
}
string User::getPass(){
    return this -> pass;
}
int User::getEdad(){
    return this -> edad;
}
bool User::getAccess(){
    return this -> access;
}
string* User::getAmigos() {
    return this->amigos;
}
string User:: getCont(){
    return "El numero de archivos creados por el usuario es: " + to_string(cont);
}


void User:: agregarAmigo(string nombreAmigo){
    this -> amigos[contAmigos] = nombreAmigo;
    contAmigos++;
}

void User:: sumaContador(){
    this -> cont = cont++;
}
void User::setAccess(bool access){
    this -> access = access;
}
void User::setNombre(string nombre){
    this -> nombre = nombre;
}
void User::setPass(string pass){
    this -> pass = pass;
}
void User::setEdad(int edad){
    this -> edad = edad;
}


#pragma once
#include<iostream>
#include "User.h"
using namespace std;

class UserNormal :public User{
    private:    
        string correo;
        bool log;
        
    public:
        UserNormal(string,string,int,string);
        ~UserNormal();
        void setCorreo(string);
        string getCorreo();
        string tipoUser();
        string toString();
};
//Constructor
UserNormal:: UserNormal (string nombre, string pass, int edad,string correo) :User(nombre, pass, edad){
    this -> correo = correo;
    log = false;
};
//Destructor
UserNormal:: ~UserNormal(){};

//Retorna el correo del usuario
string UserNormal:: getCorreo(){
    return this -> correo;
}
//setea el correo   
void UserNormal :: setCorreo(string correo){
    this -> correo = correo;
}
//Retorna el tipo de usuario al cual pertenece
string UserNormal :: tipoUser(){
    return "normal";
}
//ToString
string UserNormal:: toString(){
    string r = "";
    r = "Nombre: " + this->getNombre()+ " Edad: " + to_string(this->getEdad()) + " Correo: " + correo + " Tipo:" + this-> tipoUser();
    return r;
}
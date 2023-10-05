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

UserNormal:: UserNormal (string nombre, string pass, int edad,string correo) :User(nombre, pass, edad){
    this -> correo = correo;
    log = false;
};
UserNormal:: ~UserNormal(){};


string UserNormal:: getCorreo(){
    return this -> correo;
}

void UserNormal :: setCorreo(string correo){
    this -> correo = correo;
}

string UserNormal :: tipoUser(){
    return "normal";
}

string UserNormal:: toString(){
    string r = "";
    r = "Nombre: " + this->getNombre()+ " Edad: " + to_string(this->getEdad()) + " Correo: " + correo + " Tipo:" + this-> tipoUser();
    return r;
}
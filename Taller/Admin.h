#pragma once
#include<iostream>
#include "User.h"
using namespace std;

class Admin :public User{
    private:
        string correo;
        
    public:
    Admin(string,string,int,string);
    ~Admin();
    void setCorreo(string);
    string getCorreo();
    string tipoUser();
    string toString();
};

Admin:: Admin (string nombre, string pass, int edad,string correo) :User(nombre, pass, edad){
    this -> setEdad(99999);
    this -> setAccess(true);
    this -> correo = correo;
};
Admin :: ~Admin(){};

void Admin:: setCorreo(string correo){
    this ->correo = correo;
}

string Admin:: getCorreo(){
    return this ->correo;
}

string Admin :: tipoUser(){
    return "admin";
}

string Admin :: toString(){
    string r = "";
    r = "Nombre: " + this->getNombre()+ " Edad: " + to_string(this->getEdad()) + " Correo: " + correo + " Tipo:" + this-> tipoUser();
    return r;
}
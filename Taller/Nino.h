#pragma once
#include<iostream>
#include "User.h"
using namespace std;

class Nino :public User{
    private:
    
    public:
    Nino(string,string,int);
    ~Nino();
    string tipoUser();
    string toString();
};

Nino:: Nino (string nombre, string pass, int edad) :User(nombre, pass, edad){
        
};
Nino :: ~Nino(){};

string Nino :: tipoUser(){
    return "nino";
}

string Nino :: toString(){
    string r = "";
    r = "Nombre: " + this->getNombre()+ " Edad: " + to_string(this->getEdad()) +" Tipo:" + this-> tipoUser();
    return r;
}
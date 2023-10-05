#pragma once
#include<iostream>
#include "Software.h"
using namespace std;

class Seguridad : public Software{
    private:
        string tipo;
    public:
    Seguridad(string,string,int,float,string);
    ~Seguridad();
    string getTipo();
    void setTipo(string);
    string tipoSoft();

};

Seguridad:: Seguridad(string nombre, string developer, int edad, float precio,string tipo):Software(nombre,developer,edad,precio){
    this -> tipo = tipo;
};
Seguridad:: ~Seguridad(){};

string Seguridad :: getTipo(){
    return this -> tipo;
}

void Seguridad:: setTipo(string tipo){
    this -> tipo = tipo;
}

string Seguridad :: tipoSoft(){
    return  "seguridad";
}

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
//Constructor
Seguridad:: Seguridad(string nombre, string developer, int edad, float precio,string tipo):Software(nombre,developer,edad,precio){
    this -> tipo = tipo;
};
//Destructor
Seguridad:: ~Seguridad(){};
//retorna el tipo de software de seguridad
string Seguridad :: getTipo(){
    return this -> tipo;
}
//Setea el tipo de software de seguridad
void Seguridad:: setTipo(string tipo){
    this -> tipo = tipo;
}
//Retorna el tipo de software
string Seguridad :: tipoSoft(){
    return  "seguridad";
}

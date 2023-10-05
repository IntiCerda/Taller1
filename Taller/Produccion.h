#pragma once
#include<iostream>
#include "Software.h"
using namespace std;

class Produccion : public Software{
    private:
        string tipo;
    public:
    Produccion(string,string,int,float,string);
    ~Produccion();
    string getTipo();
    void setTipo(string);
    string tipoSoft();

};

Produccion:: Produccion(string nombre, string developer, int edad, float precio, string tipo):Software(nombre,developer,edad,precio){
    this -> tipo = tipo;
};
Produccion:: ~Produccion(){};

string Produccion :: getTipo(){
    return this-> tipo;
}

void Produccion :: setTipo(string tipo){
    this -> tipo = tipo;
}

string Produccion :: tipoSoft(){
    return  "produccion";
}

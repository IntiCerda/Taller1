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
//Constructor
Produccion:: Produccion(string nombre, string developer, int edad, float precio, string tipo):Software(nombre,developer,edad,precio){
    this -> tipo = tipo;
};
//Elimina el objeto
Produccion:: ~Produccion(){};
//Retorna el tipo de Produccion
string Produccion :: getTipo(){
    return this-> tipo;
}
//Setea el tipo de produccion por uno nuevo ingresado anteriorimente
void Produccion :: setTipo(string tipo){
    this -> tipo = tipo;
}
//Retorna el tipo de Produccion
string Produccion :: tipoSoft(){
    return  "produccion";
}

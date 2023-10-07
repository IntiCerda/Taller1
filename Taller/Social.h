#pragma once
#include<iostream>
#include "Software.h"
using namespace std;

class Social : public Software{
    private:
        ListaNodoUser* usuariosIn;
    public:
    Social(string,string,int,float);
    ~Social();
    string tipoSoft();
    ListaNodoUser* getUsuariosIn();
};
//Constructor software social
Social:: Social(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> usuariosIn = new ListaNodoUser();
};
//Destructor
Social:: ~Social(){};
//Retorna el tipo de social
string Social :: tipoSoft(){
    return  "social";
}
//Retorna la lista de usuario en el software
ListaNodoUser* Social :: getUsuariosIn(){
    return  usuariosIn;
}

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

Social:: Social(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> usuariosIn = new ListaNodoUser();
};
Social:: ~Social(){};

string Social :: tipoSoft(){
    return  "social";
}

ListaNodoUser* Social :: getUsuariosIn(){
    return  usuariosIn;
}

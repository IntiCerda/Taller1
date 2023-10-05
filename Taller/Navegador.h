#pragma once
#include<iostream>
#include "Software.h"
#include "ListaNodoUser.h"
using namespace std;

class Navegador : public Software{
    private:
        ListaNodoUser *historial;
    public:
    Navegador(string,string,int,float);
    ~Navegador();
    string tipoSoft();
    ListaNodoUser* getHistorial();
    void limpiarHistorial();
};

Navegador:: Navegador(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> historial = new ListaNodoUser();
};
Navegador:: ~Navegador(){};

string Navegador :: tipoSoft(){
    return "navegador";
}

ListaNodoUser* Navegador :: getHistorial(){
    return historial;
}

void Navegador :: limpiarHistorial(){
    
}
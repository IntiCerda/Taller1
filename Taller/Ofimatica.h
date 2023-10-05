#pragma once
#include<iostream>
#include "Software.h"
using namespace std;

class Ofimatica : public Software{
    private:
        int cont;
    public:
    Ofimatica(string,string,int,float);
    ~Ofimatica();
    string tipoSoft();
    void addArch();
    void deleteArch();
    int cantArch();
};

Ofimatica:: Ofimatica(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> cont = 0;
};
Ofimatica:: ~Ofimatica(){};

string Ofimatica :: tipoSoft(){
    return "ofimatica";
}

void Ofimatica :: addArch(){
    cont++;
}

void Ofimatica :: deleteArch(){
    cont--;
}

int Ofimatica :: cantArch(){
    return cont;
}

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
//Constructor
Ofimatica:: Ofimatica(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> cont = 0;
};
//Elimina el objeto
Ofimatica:: ~Ofimatica(){};
//Retorna el tipo de Software al que pertenece
string Ofimatica :: tipoSoft(){
    return "ofimatica";
}
//Add un nuevo archivo al contador de archivos
void Ofimatica :: addArch(){
    cont++;
}
//Delete un  archivo al contador de archivos
void Ofimatica :: deleteArch(){
    cont--;
}
//Retorna un numero con la cantidad de archivos c
int Ofimatica :: cantArch(){
    return cont;
}

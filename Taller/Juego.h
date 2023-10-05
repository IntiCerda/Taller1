#pragma once
#include<iostream>
#include "Software.h"
using namespace std;

class Juego : public Software{
    private:
        string genero;
    public:
        Juego(string,string,int,float,string);
        ~Juego();
        void setGenero(string);
        string getGenero();
        string tipoSoft();
        void cambioGenero(string);
};

Juego:: Juego(string nombre, string developer, int edad, float precio, string genero): Software(nombre,developer,edad,precio){
    this -> genero = genero;
};
Juego:: ~Juego(){};


string Juego :: getGenero(){
    return this -> genero;
}

string Juego :: tipoSoft(){
    return "juego";
}

void Juego :: cambioGenero(string gen){
    this -> genero = gen;
}


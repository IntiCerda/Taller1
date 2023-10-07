#pragma once
#include<iostream>
#include"ListaNodoUser.h"
using namespace std;

class Software{
    
    private:
        string nombre;
        string developer;
        int edad;
        int precio;
        ListaNodoUser *registroUser;
    
    public:
        Software(string,string,int,float);
        ~Software();
        string getNombre();
        string getDev();
        int getEdad();
        float getPrecio();

        void setPrecio(float);
        void setEdad(int);
        void setNombre(string);
        void setDev(string);
        virtual string tipoSoft() = 0; //Implementar en clases hijas
        ListaNodoUser* getListaUser();
       
    
};
//Constructor padre de Softwares
Software::Software(string nombre, string developer, int edad, float precio){
    this -> nombre = nombre;
    this -> developer = developer;
    this -> edad = edad;
    this -> precio = precio;
    registroUser = new ListaNodoUser();
}
//Destructor
Software::~Software(){};
//Getter and setter
string Software:: getNombre(){
    return this -> nombre;
};
//Getter and setter
string Software:: getDev(){
    return this -> developer;
};
//Getter and setter
int Software:: getEdad(){
    return this -> edad;
}
//Getter and setter
float Software:: getPrecio(){
    return this -> precio;
}
//Retorna la lista de usuarios en el Software
ListaNodoUser* Software :: getListaUser(){
    return this -> registroUser;

}
//Getter and setter
void Software:: setNombre(string nombre){
    this -> nombre = nombre;
};
//Getter and setter
void Software:: setDev(string Developer){
    this -> developer = developer;
};
//Getter and setter
void Software:: setEdad(int edad){
    this -> edad = edad;
}
//Getter and setter
void Software:: setPrecio(float precio){
    this -> precio = precio;
}

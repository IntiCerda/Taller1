#pragma once
#include<iostream>
using namespace std;

class Software{
    
    private:
        string nombre;
        string developer;
        int edad;
        int precio;
        
    
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
    
    
};

Software::Software(string nombre, string developer, int edad, float precio){
    this -> nombre = nombre;
    this -> developer = developer;
    this -> edad = edad;
    this -> precio = precio;
}

Software::~Software(){};

string Software:: getNombre(){
    return this -> nombre;
};
string Software:: getDev(){
    return this -> developer;
};
int Software:: getEdad(){
    return this -> edad;
}
float Software:: getPrecio(){
    return this -> precio;
}


void Software:: setNombre(string nombre){
    this -> nombre = nombre;
};
void Software:: setDev(string Developer){
    this -> developer = developer;
};
void Software:: setEdad(int edad){
    this -> edad = edad;
}
void Software:: setPrecio(float precio){
    this -> precio = precio;
}

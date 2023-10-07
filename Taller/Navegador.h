#pragma once
#include<iostream>
#include "Software.h"
#include "ListaNodoUser.h"
using namespace std;

class Navegador : public Software{
    private:
        ListaNodoUser *historial;//al final no se uso, ya que no quedo claro en el enunciado la manera en que se implementaria el historial.
        string registroHistorial[30];
        int contHist;
    public:
    Navegador(string,string,int,float);
    ~Navegador();
    string tipoSoft();
    ListaNodoUser* getHistorial();
    void limpiarHistorial();
    void imprimirHistorial();
    void agregarPag(string);
};
//Constructor
Navegador:: Navegador(string nombre, string developer, int edad, float precio):Software(nombre,developer,edad,precio){
    this -> historial = new ListaNodoUser();
    for (int i = 0; i < 30; i++) {
        registroHistorial[i] = "";
    }
    this -> contHist=0;
};
//Destructor
Navegador:: ~Navegador(){};
//Retorna el tipo de Software al que pertenece
string Navegador :: tipoSoft(){
    return "navegador";
}
//Retorna historial que no se uso
ListaNodoUser* Navegador :: getHistorial(){
    return historial;
}
//Elimina todos las paginas del historial
void Navegador :: limpiarHistorial(){
    for (int i = 0; i < 30; i++) {
        registroHistorial[i] = "";
    }
    cout<<"Historial limpiado... "<<endl;
}
//Imprime todos las paginas del historial
void Navegador :: imprimirHistorial(){
    for (int i = 0; i < 10; i++) {
        cout<<registroHistorial[i]<<endl;
    }

}
//Agrega todos las paginas del historial
void Navegador :: agregarPag(string url){
    registroHistorial[contHist] = url;
}
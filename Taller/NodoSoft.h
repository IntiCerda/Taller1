#pragma once
#include <iostream>
#include "Software.h"
#include "Juego.h"
#include "Navegador.h"
#include "Ofimatica.h"
#include "Produccion.h"
#include "Seguridad.h"
#include "Social.h"

class NodoSoft{
    private:
        Software *soft;
        NodoSoft *sig;
    
    public:
        NodoSoft(Software*);
        ~NodoSoft();
        Software *getSoft();
        void setSoft(Software* );
        NodoSoft *getSig();
        void setSig(NodoSoft*);
    
};
//Constructor del Nodo
NodoSoft :: NodoSoft(Software* soft){
    this -> soft = soft;
    this -> sig = NULL;
    
}
//Destructor
NodoSoft :: ~NodoSoft(){
    this -> soft -> ~Software();
}
//Retorna el Software 
Software *NodoSoft :: getSoft(){
    return this -> soft;
}
//Retorna el Nodo Siguiente
NodoSoft *NodoSoft :: getSig(){
    return this -> sig;
}
//Setea el software en el nodo
void NodoSoft :: setSoft(Software *soft){
    this -> soft = soft;
}
//Setea el nodo siguiente, para enlazarlos
void NodoSoft:: setSig(NodoSoft *nodoSiguiente){
    this -> sig = nodoSiguiente;
}
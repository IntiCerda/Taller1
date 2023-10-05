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

NodoSoft :: NodoSoft(Software* soft){
    this -> soft = soft;
    this -> sig = NULL;
    
}

NodoSoft :: ~NodoSoft(){
    this -> soft -> ~Software();
}

Software *NodoSoft :: getSoft(){
    return this -> soft;
}
NodoSoft *NodoSoft :: getSig(){
    return this -> sig;
}

void NodoSoft :: setSoft(Software *soft){
    this -> soft = soft;
}

void NodoSoft:: setSig(NodoSoft *nodoSiguiente){
    this -> sig = nodoSiguiente;
}
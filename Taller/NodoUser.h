#pragma once
#include <iostream>
#include "User.h"
#include "UserNormal.h"
#include "Nino.h"
#include "Admin.h"
using namespace std;

class NodoUser{
    private:
        User *user;
        NodoUser *sig;
    
    public:
        NodoUser(User*);
        ~NodoUser();
        User *getUser();
        void setUser(User* );
        NodoUser *getSig();
        void setSig(NodoUser*);
    
};
//Constructor del Nodo
NodoUser :: NodoUser(User* user){
    this -> user = user;
    this -> sig = NULL;
    
}
//Destructor
NodoUser :: ~NodoUser(){
    this -> user -> ~User();
}
//Retorna el usuario contenido en el nodo
User *NodoUser :: getUser(){
    return this -> user;
}
//Retorna el nodo siguiente
NodoUser *NodoUser :: getSig(){
    return this -> sig;
}
//Setea el Usuario en el Nodo
void NodoUser :: setUser(User *user){
    this -> user = user;
}
//Setea el Nodo siguiente, dado un nodo
void NodoUser:: setSig(NodoUser *nodoSiguiente){
    this -> sig = nodoSiguiente;
}
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

NodoUser :: NodoUser(User* user){
    this -> user = user;
    this -> sig = NULL;
    
}

NodoUser :: ~NodoUser(){
    this -> user -> ~User();
}

User *NodoUser :: getUser(){
    return this -> user;
}
NodoUser *NodoUser :: getSig(){
    return this -> sig;
}

void NodoUser :: setUser(User *user){
    this -> user = user;
}

void NodoUser:: setSig(NodoUser *nodoSiguiente){
    this -> sig = nodoSiguiente;
}
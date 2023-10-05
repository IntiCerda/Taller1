#pragma once
#include "NodoUser.h"
using namespace std;

class ListaNodoUser{
    private:
     NodoUser* primero;
     int largo;
    
    public:
     ListaNodoUser();
     void agregarUser(User*);
     void eliminarUser(User*);
     void imprimirLista();
     int getLargo();
     User* buscarUserPorNombre(string);
     User* buscarUserPorNombreYContrasena(string, string);
};
//Constructor
ListaNodoUser::ListaNodoUser() {
    primero = NULL;
    largo = 0;
}

//Crea un Nodo dado un usuario creado anteriormente, para agregarlo a la ListaNodoUser
void ListaNodoUser::agregarUser(User* user) {
    NodoUser* nuevo = new NodoUser(user);
    if (primero == NULL) {
        primero = nuevo;
        return;
    } else {
        NodoUser* aux = primero;
        while (aux->getSig() != NULL) {
            aux = aux->getSig();
        }
        aux->setSig(nuevo);
    }
    largo++;
    
}

//Elimina un usuari de la lista enlazada, segun el nombre.
void ListaNodoUser::eliminarUser(User* user) {
    NodoUser* aux = primero;
    NodoUser* anterior = NULL;
    while (aux != NULL) {
        if (aux->getUser()->getNombre() == user->getNombre()) {
            if (anterior == NULL) {
                primero = aux->getSig();
            } else {
                anterior->setSig(aux->getSig());
            }
            delete aux;
            largo--;
            break;
        }
        anterior = aux;
        aux = aux->getSig();
    }
}

//Imprime los nombres de los usuarios en la lista enlazada
void ListaNodoUser::imprimirLista() {
    NodoUser* aux = primero;
    while (aux != NULL) {
        cout << aux->getUser()->getNombre() << endl;
        aux = aux->getSig();
    }
}

//Retorna el largo de la lista enlazda
int ListaNodoUser::getLargo() {
    return largo;
}

//Busca usuario por nombre
User* ListaNodoUser::buscarUserPorNombre(string nombre) {
    NodoUser* aux = primero;
    while (aux != NULL) {
        if (aux->getUser()->getNombre() == nombre) {
            return aux->getUser();
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró el usuario
}


// Busca un usuario por nombre y contraseña y retorna el primer usuario encontrado (o NULL si no se encuentra)
User* ListaNodoUser::buscarUserPorNombreYContrasena(string nombre, string contrasena) {
    NodoUser* aux = primero;
    while (aux != NULL) {
        User* usuario = aux->getUser();
        if (usuario->getNombre() == nombre && usuario->getPass() == contrasena) {
            return usuario;
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró el usuario
}

#pragma once
#include "NodoSoft.h"

using namespace std;

class ListaNodoSoft{
    private:
     NodoSoft* primero;
     int largo;
    
    public:
     ListaNodoSoft();
     void agregarSoft(Software*);
     void eliminarSoft(Software*);
     void imprimirLista();
     int getLargo();
};

ListaNodoSoft::ListaNodoSoft() {
    primero = NULL;
    largo = 0;
}
void ListaNodoSoft::agregarSoft(Software* soft) {
    NodoSoft *nuevo = new NodoSoft(soft);
    if (primero == NULL) {
        primero = nuevo;
    } else {
        NodoSoft* aux = primero;
        while (aux->getSig() != NULL) {
            aux = aux->getSig();
        }
        aux->setSig(nuevo);
    }
    largo++;
}
void ListaNodoSoft::eliminarSoft(Software* soft) {
    NodoSoft* aux = primero;
    NodoSoft* anterior = NULL;
    while (aux != NULL) {
        if (aux->getSoft()->getNombre() == soft->getNombre()) {
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
void ListaNodoSoft::imprimirLista() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        cout << aux->getSoft()->getNombre() << endl;
        aux = aux->getSig();
    }
}
int ListaNodoSoft::getLargo() {
    return largo;
}
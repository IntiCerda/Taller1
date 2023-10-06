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
     void imprimirJuegos(int);
     Juego* retornarJuegoPorNombre(string);
     bool existeJuegoPorNombre(string);
     void imprimirOfimatica();
     Ofimatica* retornarOfimaticaPorNombre(string);
     void imprimirProduccion();
     bool existeProduccionPorNombre(string);
     Produccion* retornarProduccionPorNombre(string);
     void imprimirNavegador();
     Navegador* retornarNavegadorPorNombre(string );
     void agregarRegistroUser(User *user);
     void imprimirSocial();
     Social* retornarSocialPorNombre(string );
     Seguridad* retornarSeguridadPorNombre(string);
     void imprimirSeguridad();
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

void ListaNodoSoft::imprimirJuegos(int edadUsuario) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "juego") {
            // Realiza el cast de 'soft' a un objeto de tipo 'Juego'
            Juego* juego = static_cast<Juego*>(soft);
            
            // Compara la edad del usuario con la edad requerida para el juego
            if (edadUsuario >= juego->getEdad()) {
                cout << juego->getNombre() << " " << juego->getDev() << " " << juego->getGenero() << endl;
            }
        }
        aux = aux->getSig();
    }
}


// Retorna un puntero al juego con el nombre especificado o NULL si no se encuentra
Juego* ListaNodoSoft::retornarJuegoPorNombre(string nombreJuego) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "juego") {
            Juego* juego = static_cast<Juego*>(soft);
            if (juego->getNombre() == nombreJuego) {
                return juego;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró el juego con el nombre especificado
}

// Verifica si existe un juego con el nombre especificado en la lista
bool ListaNodoSoft::existeJuegoPorNombre(string nombreJuego) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "juego") {
            Juego* juego = static_cast<Juego*>(soft);
            if (juego->getNombre() == nombreJuego) {
                return true; // El juego existe 
            }
        }
        aux = aux->getSig();
    }
    return false; // El juego no se encuentra 
}

void ListaNodoSoft::imprimirOfimatica() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "ofimatica") {
            Ofimatica* offic = static_cast<Ofimatica*>(soft);
            cout<<offic ->getNombre() << ", " << offic->getDev() << ", cantidad de archivos: "<< offic->cantArch()<<endl;
        }
        aux = aux->getSig();
    }
}

void ListaNodoSoft::imprimirProduccion() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "produccion") {
            Produccion* prod = static_cast<Produccion*>(soft);
            cout<<prod ->getNombre() << ", " << prod->getDev() << ", cantidad de archivos: "<< prod->getTipo()<<endl;
        }
        aux = aux->getSig();
    }
}

Ofimatica* ListaNodoSoft::retornarOfimaticaPorNombre(string nombreOfimatica) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "ofimatica") {
            Ofimatica* ofimatica = static_cast<Ofimatica*>(soft);
            if (ofimatica->getNombre() == nombreOfimatica) {
                return ofimatica;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró la ofimática con el nombre especificado
}

bool ListaNodoSoft::existeProduccionPorNombre(string nombreProduccion) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "produccion") {
            Produccion* produccion = static_cast<Produccion*>(soft);
            if (produccion->getNombre() == nombreProduccion) {
                return true; // La producción existe
            }
        }
        aux = aux->getSig();
    }
    return false; // La producción no se encuentra
}

Produccion* ListaNodoSoft::retornarProduccionPorNombre(string nombreProduccion) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "produccion") {
            Produccion* produccion = static_cast<Produccion*>(soft);
            if (produccion->getNombre() == nombreProduccion) {
                return produccion;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró la producción con el nombre especificado
}

void ListaNodoSoft::imprimirNavegador() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "navegador") {
            Navegador* nav = static_cast<Navegador*>(soft);
            cout<<nav ->getNombre() << ", " << nav->getDev() <<endl;
        }
        aux = aux->getSig();
    }
}

Navegador* ListaNodoSoft::retornarNavegadorPorNombre(string name) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "navegador") {
            Navegador* nav = static_cast<Navegador*>(soft);
            if (nav->getNombre() == name) {
                return nav;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró la producción con el nombre especificado
}

void ListaNodoSoft::imprimirSocial() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "social") {
            Social* soc = static_cast<Social*>(soft);
            cout<<soc ->getNombre() << ", " << soc->getDev() <<endl;
        }
        aux = aux->getSig();
    }
}

Social* ListaNodoSoft::retornarSocialPorNombre(string name) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "social") {
            Social* soc = static_cast<Social*>(soft);
            if (soc->getNombre() == name) {
                return soc;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró la producción con el nombre especificado
}

Seguridad* ListaNodoSoft::retornarSeguridadPorNombre(string name) {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "seguridad") {
            Seguridad* seg = static_cast<Seguridad*>(soft);
            if (seg->getNombre() == name) {
                return seg;
            }
        }
        aux = aux->getSig();
    }
    return NULL; // Si no se encontró la producción con el nombre especificado
}

void ListaNodoSoft::imprimirSeguridad() {
    NodoSoft* aux = primero;
    while (aux != NULL) {
        Software* soft = aux->getSoft();
        if (soft->tipoSoft() == "seguridad") {
            Seguridad* seg = static_cast<Seguridad*>(soft);
            cout<<seg ->getNombre() << ", " << seg->getDev() <<endl;
        }
        aux = aux->getSig();
    }
}

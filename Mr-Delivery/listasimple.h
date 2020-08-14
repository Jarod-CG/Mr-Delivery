#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "arista.h"

class Arista;

class ListaSimple
{
private:
    Arista * primero, *ultimo;
public:
    ListaSimple();
    void insertarAlFinal (Arista * arista);
    void imprimir();


    Arista *getPrimero() const;
    void setPrimero(Arista *value);
    Arista *getUltimo() const;
    void setUltimo(Arista *value);
};

#endif // LISTASIMPLE_H

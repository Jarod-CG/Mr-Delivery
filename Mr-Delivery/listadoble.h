#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "vertice.h"

class Nodo;

class ListaDoble
{
private:
    Vertice * primer;
    Vertice * ultimo;
public:
    ListaDoble();
    void insertarAlFinal(QString nombre);
    void imprimir();
    Vertice * buscar (QString nombre);

    Vertice *getPrimer() const;
    void setPrimer(Vertice *value);
    Vertice *getUltimo() const;
    void setUltimo(Vertice *value);
};

#endif // LISTADOBLE_H

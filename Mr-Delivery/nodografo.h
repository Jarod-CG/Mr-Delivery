#ifndef NODOGRAFO_H
#define NODOGRAFO_H
#include "grafo.h"

class NodoGrafo
{
private:
    Grafo * grafo;
    NodoGrafo * siguiente;
public:
    NodoGrafo(Grafo * grafo);
    void imprimir();
    Grafo *getGrafo() const;
    void setGrafo(Grafo *value);
    NodoGrafo *getSiguiente() const;
    void setSiguiente(NodoGrafo *value);
};

#endif // NODOGRAFO_H

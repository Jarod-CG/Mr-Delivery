#include "nodografo.h"

NodoGrafo::NodoGrafo(Grafo * grafo)
{
    this->grafo = grafo;
    this->siguiente = nullptr;
}

void NodoGrafo::imprimir(){
    grafo->imprimir();
}

#include "grafo.h"

Grafo::Grafo()
{
    this->listaAdyacencia = nullptr;
    this->matrizKm = {};
    this->matrizCosto = {};
    this->matrizMinutos = {};
}

void Grafo::imprimir(){
    listaAdyacencia->imprimir();
}

void Grafo::insertarVertice(QString nombre){
    Vertice * tmp = listaAdyacencia->buscar (nombre);
}

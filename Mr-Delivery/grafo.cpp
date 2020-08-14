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

bool Grafo::insertarVertice(QString nombre){
    Vertice * tmp = listaAdyacencia->buscar (nombre);
    //null no existe
    if (tmp==nullptr){
        listaAdyacencia->insertarAlFinal(nombre);
        return true;
    }
    return false;
}

bool Grafo::insertarArista(Arista *arista){
    Vertice * tmpOrigen = listaAdyacencia->buscar(arista->getNombreOrigen());
    Vertice * tmpDestino = listaAdyacencia->buscar(arista->getNombreDestino());
    //deben exitir origen y destino
    if (tmpOrigen!=nullptr & tmpDestino!=nullptr){
        arista->setOrigen(tmpOrigen);
        arista->setDestino(tmpDestino);
        tmpOrigen->getAristas()->insertarAlFinal(arista);
        return true;
    }
    return false;


}

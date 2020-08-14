#include "listadoble.h"
#include <QDebug>

void ListaDoble::insertarAlFinal(QString nombre) {
    if (primer == nullptr) {
        primer = new Vertice (nombre);
        ultimo = primer;
    }
    else {
        Vertice * nuevo = new Vertice(nombre);
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

void ListaDoble::imprimir(){
    Vertice * tmp = primer;
    while (tmp!=nullptr){
        tmp->imprimir();
        tmp= tmp->getSiguiente();
    }
}

Vertice * ListaDoble::buscar(QString nombre){

}

Vertice *ListaDoble::getPrimer() const
{
    return primer;
}

void ListaDoble::setPrimer(Vertice *value)
{
    primer = value;
}

Vertice *ListaDoble::getUltimo() const
{
    return ultimo;
}

void ListaDoble::setUltimo(Vertice *value)
{
    ultimo = value;
}

ListaDoble::ListaDoble()
{
    this->primer = this->ultimo = nullptr;
}



#include "vertice.h"
#include <QtDebug>

Vertice::Vertice()
{
    this->nombre = nullptr;
    this->siguiente = this->anterior = nullptr;
    this->aristas = nullptr;
}

Vertice::Vertice(QString nombre) {
    this->nombre=nombre;
    this->siguiente = this->anterior = nullptr;
    this->aristas = nullptr;
}

void Vertice::imprimir(){
    qDebug() << "Vertice : "<<nombre;
    if (aristas!=nullptr){
        aristas->imprimir();
    }
}


QString Vertice::getNombre() const
{
    return nombre;
}

void Vertice::setNombre(const QString &value)
{
    nombre = value;
}

ListaSimple *Vertice::getAristas() const
{
    return aristas;
}

void Vertice::setAristas(ListaSimple *value)
{
    aristas = value;
}

Vertice *Vertice::getSiguiente() const
{
    return siguiente;
}

void Vertice::setSiguiente(Vertice *value)
{
    siguiente = value;
}

Vertice *Vertice::getAnterior() const
{
    return anterior;
}

void Vertice::setAnterior(Vertice *value)
{
    anterior = value;
}



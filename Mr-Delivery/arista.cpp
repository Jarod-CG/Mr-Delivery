#include "arista.h"
#include <QDebug>

Arista::Arista()
{
    this->origen = this->destino = nullptr;
    this->status = false;
    this->costo = INT_MIN;
    this->km = LONG_MIN;
    this->minutos = LONG_MIN;
    this->siguiente = nullptr;
}

void Arista::imprimir(){
    qDebug () << "Origen : " << nombreOrigen;
    qDebug () << "Destino : " << nombreDestino;
    qDebug () << status << costo << km << minutos;
}

QString Arista::getNombreOrigen() const
{
    return nombreOrigen;
}

void Arista::setNombreOrigen(const QString &value)
{
    nombreOrigen = value;
}

QString Arista::getNombreDestino() const
{
    return nombreDestino;
}

void Arista::setNombreDestino(const QString &value)
{
    nombreDestino = value;
}

Vertice *Arista::getOrigen() const
{
    return origen;
}

void Arista::setOrigen(Vertice *value)
{
    origen = value;
}

Vertice *Arista::getDestino() const
{
    return destino;
}

void Arista::setDestino(Vertice *value)
{
    destino = value;
}

bool Arista::getStatus() const
{
    return status;
}

void Arista::setStatus(bool value)
{
    status = value;
}

int Arista::getCosto() const
{
    return costo;
}

void Arista::setCosto(int value)
{
    costo = value;
}

double Arista::getKm() const
{
    return km;
}

void Arista::setKm(double value)
{
    km = value;
}

double Arista::getMinutos() const
{
    return minutos;
}

void Arista::setMinutos(double value)
{
    minutos = value;
}

Arista *Arista::getSiguiente() const
{
    return siguiente;
}

void Arista::setSiguiente(Arista *value)
{
    siguiente = value;
}



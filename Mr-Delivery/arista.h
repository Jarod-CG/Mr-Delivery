#ifndef ARISTA_H
#define ARISTA_H
#include "vertice.h"

class Vertice;

class Arista
{
private:
    Vertice * origen;
    Vertice * destino;
    //bien campbiarlo por un string con nombre del vertice
    QString nombreOrigen;
    QString nombreDestino;
    bool status;
    int costo;
    double km;
    double minutos;
    Arista * siguiente;



public:
    Arista();
    void imprimir();

    Arista *getSiguiente() const;
    void setSiguiente(Arista *value);
    Vertice *getOrigen() const;
    void setOrigen(Vertice *value);
    Vertice *getDestino() const;
    void setDestino(Vertice *value);
    bool getStatus() const;
    void setStatus(bool value);
    int getCosto() const;
    void setCosto(int value);
    double getKm() const;
    void setKm(double value);
    double getMinutos() const;
    void setMinutos(double value);
    QString getNombreOrigen() const;
    void setNombreOrigen(const QString &value);
    QString getNombreDestino() const;
    void setNombreDestino(const QString &value);
};

#endif // ARISTA_H

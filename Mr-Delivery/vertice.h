#ifndef VERTICE_H
#define VERTICE_H
#include <QString>
#include "listasimple.h"

class ListaSimple;

class Vertice
{
private:
    Vertice * siguiente, * anterior;
    QString nombre;
    ListaSimple * aristas;
public:
    Vertice();
    Vertice(QString nombre);
    void imprimir();

    Vertice *getSiguiente() const;
    void setSiguiente(Vertice *value);
    Vertice *getAnterior() const;
    void setAnterior(Vertice *value);
    QString getNombre() const;
    void setNombre(const QString &value);
    ListaSimple *getAristas() const;
    void setAristas(ListaSimple *value);
};

#endif // VERTICE_H

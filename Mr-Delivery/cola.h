#ifndef COLA_H
#define COLA_H

#include <QMutex>
#include "nodografo.h"
#include "grafo.h"

//es una cola de grafos
class Cola
{
private:
    QMutex * mutex;
    NodoGrafo * frente;
public:
    Cola();
    NodoGrafo * encolar (Grafo*);
    NodoGrafo * desencolar (void);
    NodoGrafo *verFrente (void);
    bool vacia (void);
    void imprimir();

    QMutex *getMutex() const;
    void setMutex(QMutex *value);
    NodoGrafo *getFrente() const;
    void setFrente(NodoGrafo *value);
};

#endif // COLA_H

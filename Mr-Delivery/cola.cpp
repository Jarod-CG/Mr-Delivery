#include "cola.h"

QMutex *Cola::getMutex() const
{
    return mutex;
}

void Cola::setMutex(QMutex *value)
{
    mutex = value;
}

NodoGrafo *Cola::getFrente() const
{
    return frente;
}

void Cola::setFrente(NodoGrafo *value)
{
    frente = value;
}

Cola::Cola()
{

}

#include "cola.h"

QMutex *Cola::getMutex() const
{
    return mutex;
}

bool Cola::vacia() {
    if (frente==nullptr) return true;
    return false;
}

void Cola::imprimir() {
    if (!vacia()) {
        NodoGrafo * tmp = frente;

        while (tmp!=nullptr) {

            tmp->imprimir();
            tmp=tmp->getSiguiente();
        }
    }
}

NodoGrafo * Cola::encolar (Grafo* grafo) {
    NodoGrafo * nuevo;
    if (vacia()) {
        frente = new NodoGrafo (grafo);
        nuevo = frente;
    }
    else {
        NodoGrafo* actual = frente;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        nuevo = new NodoGrafo (grafo);
        actual->getSiguiente()->setSiguiente(nuevo);
    }

    return nuevo;
}

NodoGrafo * Cola::desencolar (void){
    if (vacia())
        return nullptr;
    else {
        NodoGrafo* borrado = frente;
        frente = frente->getSiguiente();
        borrado->setSiguiente( nullptr);
        return borrado;
    }
}

NodoGrafo * Cola::verFrente (){
    return frente;
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

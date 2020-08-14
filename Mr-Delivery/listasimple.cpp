#include "listasimple.h"
ListaSimple::ListaSimple()
{
    this->ultimo = this->primero = nullptr;
}

void ListaSimple::insertarAlFinal(Arista * arista){
    if (primero == nullptr){
        ultimo = primero = arista;
    }
    else {
        ultimo->setSiguiente(arista);
        ultimo = ultimo->getSiguiente();
    }

}

void ListaSimple::imprimir(){
    Arista * tmp = primero;
    while (tmp!=nullptr) {
        tmp->imprimir();
        tmp = tmp->getSiguiente();
    }


}

Arista *ListaSimple::getPrimero() const
{
    return primero;
}

void ListaSimple::setPrimero(Arista *value)
{
    primero = value;
}

Arista *ListaSimple::getUltimo() const
{
    return ultimo;
}

void ListaSimple::setUltimo(Arista *value)
{
    ultimo = value;
}





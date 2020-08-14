#ifndef GRAFO_H
#define GRAFO_H

#include "listadoble.h"
#include <QVector>

class ListaDoble;

class Grafo
{
private:
    ListaDoble * listaAdyacencia;
    QVector<QVector<int>> matrizCosto;
    QVector<QVector<int>> matrizKm;
    QVector<QVector<int>> matrizMinutos;
    //matrices de adyacencia x3 cada uno por cada ponderacion;

public:
    Grafo();
    void imprimir();
    void insertarVertice (QString nombre);
    //Svoid insertarArista (QString origen, QString arista,)
};

#endif // GRAFO_H

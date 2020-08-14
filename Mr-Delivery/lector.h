#ifndef LECTOR_H
#define LECTOR_H

#include <QThread>
#include "grafo.h"
#include "cola.h"

class Grafo;
class Cola;


class Lector : public QThread
{
private:
    bool detenido;
    bool pausado;
    QString path;//es el path general
    Grafo * grafo;
    Cola * cola;
public:
    Lector();
    void __init__(QString path, Cola * cola);//es para inicializar todos los atributos
    void run () override;
    void detener();
    void pausar ();
    void resume ();
    void procesar();
    QString cargar ();
    void abrirJson(QString strJson);
    void construirGrafo(QString vertices, QJsonArray aristas);
    void mover();

};

#endif // LECTOR_H

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
    bool correcto;
    QString jsonFile;
public:
    Lector();
    void __init__(QString path, Cola * cola);//es para inicializar todos los atributos
    void run () override;
    void detener();
    void pausar ();
    void resume ();
    void procesar();
    QString cargar ();
    bool abrirJson(QString strJson);
    bool construirGrafo(QStringList vertices, QJsonArray aristas);
    void mover();
    Arista * crearArista (QJsonObject jsonArista);

};

#endif // LECTOR_H

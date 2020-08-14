#include "lector.h"
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

Lector::Lector()
{

}

void Lector::__init__(QString path, Cola * cola){

    this->cola = cola;

    this->path = path;

    this->grafo = nullptr;
    this->pausado = false;
    this->pausado = false;

}

//otra que lo mueva ya sea a procesado o a errores

void Lector::mover(){

}

void Lector::construirGrafo(QStringList vertices, QJsonArray aristas){
    ListaDoble * lDoble = new ListaDoble();
    //validat que los vertices no esten reptidos

}

//otra funcion que lo valide y lo cargue en this->grafo
void Lector::abrirJson(QString strJson){
    //convertimos el string para empezar a procesarlo
    QJsonDocument jsonDoc = QJsonDocument::fromJson(strJson.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    QJsonValue jsonVert = jsonObj.value(QString("vertices"));
    QJsonArray jsonArrV = jsonVert.toArray();
    QList <QVariant> listVar = jsonArrV.toVariantList();
    QStringList strVertices;
    for (int i = 0; i <listVar.size();i++){
        strVertices.append(listVar.at(i).toString());
    }
    //hasta aca tengo los vertices en strVertices
    QJsonValue jsonArist = jsonObj.value(QString("vertices"));
    QJsonArray jsonArrA = jsonArist.toArray();
    construirGrafo(strVertices,jsonArrA);
}
//funcion que busque en carpeta y cargue el primero
//si retorn "" es que no cargo
QString Lector::cargar(){
    QString nuevo = path+ "Nuevo\\";
    QDir dir (nuevo);
    dir.setSorting(QDir::Time);
    QStringList archivos = dir.entryList();
    archivos.removeAt(archivos.indexOf("."));
    archivos.removeAt(archivos.indexOf(".."));
    if (archivos.size()==0){
        //mover el archivo a errores
        return "";
    }
    else {
        QString nombreArchivo = archivos.at(archivos.size()-1);
        //VALIDAR QUE SEA JSON
        QString pathArchivo = nuevo + nombreArchivo;
        QFile file (pathArchivo);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QString val = file.readAll();
        file.close();

        return val;
    }

}

void Lector::procesar(){
    QString strJson = cargar();
    if (strJson!=""){
        construir(strJson);
    }

}

void Lector::run() {
    while(!this->detenido) {


        if (this->grafo==nullptr){
            procesar();
        }
        else {
            if (cola->getMutex()->tryLock()) {
                //aca encola el grafo en el pedido
                //acapone el grafo en null
                cola->getMutex()->unlock();
            }
        }

        //codigo para leer

        sleep(2);//lee cada minuto
        while(pausado) {
            qDebug () << "lector dormido";
            sleep(1);
        }
    }
}

void Lector::detener() {
    this->detenido = true;
}

/*
E:
S:
D:
*/
void Lector::pausar() {
    this->pausado = true;
}

/*
E:
S:
D:
*/
void Lector::resume() {
    this->pausado = false;
}

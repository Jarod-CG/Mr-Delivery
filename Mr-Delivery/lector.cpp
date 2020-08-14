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


    this->pausado = false;
    this->pausado = false;
    this->grafo = nullptr;
    this->jsonFile = "";
    this->correcto = true;


}

//otra que lo mueva ya sea a procesado o a errores

void Lector::mover(){

}

Arista * Lector::crearArista (QJsonObject jsonArista) {
    Arista * tmp = new Arista();
    QString str;
    bool status;
    int num;
    double flo;

    str = jsonArista["origen"].toString();
    if (str.isNull()) {
        return nullptr;
    }
    tmp->setNombreDestino(str);
    str.clear();

    str = jsonArista["destino"].toString();
    if (str.isNull()) {
        return nullptr;
    }
    tmp->setNombreOrigen(str);

    status = jsonArista["activo"].toBool();
    /*if (str.isNull()) {
        return nullptr;
    }*/
    tmp->setStatus(status);

    num = jsonArista["costo"].toInt(INT_MAX);
    if (num==INT_MAX) {
        return nullptr;
    }
    tmp->setCosto(num);

    flo = jsonArista["km"].toDouble(__DBL_MAX__);
    if (flo==__DBL_MAX__) {
        return nullptr;
    }
    tmp->setKm(flo);

    flo = jsonArista["minutos"].toDouble(__DBL_MAX__);
    if (flo==__DBL_MAX__) {
        return nullptr;
    }
    tmp->setMinutos(flo);


    return tmp;
}

bool Lector::construirGrafo(QStringList vertices, QJsonArray aristas){
    grafo = new Grafo();
    //validat que los vertices no esten reptidos
    for (int i = 0; i<vertices.size();i++){
        if(!grafo->insertarVertice(vertices.at(i))){
            //si entra aqui el grafo esta mal
            //esto valida vertices distintos
            correcto = false;
            return false;
        }
        else {
            correcto = true;
        }
    }
    if (correcto) {
        for (int i = 0; i<aristas.size(); i++){
            QJsonObject jsonArista = aristas.at(i).toObject();
            Arista * tmp = crearArista(jsonArista);
            if (tmp!=nullptr|!grafo->insertarArista(tmp)){
                correcto = false;
                return false;
            }
            /*
            if (tmp!=nullptr) {
                if (!grafo->insertarArista(tmp)) {
                    //no se inserto
                    correcto = false;
                    return false;
                }
            }
            else {
                //no se construyo esta mal
                correcto = false;
                return false;
            }*/
        }
    }
    //crear la arista e insertarsela al grafo

    correcto = true;
    return true;

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
    /*if (construirGrafo(strVertices,jsonArrA)){
        //si se creo el grafo
        return true;
    }
    else {
        //no se construyo el grafo
        return false;
    }*/
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
        jsonFile = pathArchivo;
        QFile file (pathArchivo);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QString val = file.readAll();
        file.close();

        return val;
    }

}

void Lector::procesar(){
    QString strJson = cargar();
    QString nuevo = path;
    if (strJson!=""){
        abrirJson(strJson);
    }
    QFile file(path+"Nuevo\\"+jsonFile);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if (correcto) {
        //mover a procesado
        nuevo.append("Procesado\\"+jsonFile);

    }
    else {
        //mover a errores;
        nuevo.append("Errores\\"+jsonFile);
        grafo = nullptr;
        jsonFile = "";
        correcto = true;

    }
    file.rename(nuevo);
    file.close();

}

void Lector::run() {
    while(!this->detenido) {


        if (this->grafo==nullptr){
            procesar();
        }
        if (grafo!=nullptr) {
            if (cola->getMutex()->tryLock()) {
                //aca encola el grafo en el pedido
                //cola->encolar(grafo);
                //acapone el grafo en null
                cola->getMutex()->unlock();
                grafo = nullptr;
                jsonFile = "";
                correcto = true;
            }
        }

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

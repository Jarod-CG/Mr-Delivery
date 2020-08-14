#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    //es el path default
    QString path = "C:\\Users\\Jarod\\Documents\\Universidades\\TEC\\Estructura de Datos\\Proyecto\\Mr. Delivery\\Mr-Delivery\\";
    //es la añadidura para leer
    QString nuevo = path+ "Nuevos\\";
    QDir dir (nuevo);
    //los ordena
    dir.setSorting(QDir::Time);
    //los convierte a string
    QStringList archivos = dir.entryList();
    //elimina lo innecesario
    archivos.removeAt(archivos.indexOf("."));
    archivos.removeAt(archivos.indexOf(".."));
    //imprime el tamaño
    qDebug () << archivos.size();
    //si es cero mamamos
    for (int i = 0; i< archivos.size();i++){
        qDebug () << "archivo " << i << ":";
        qDebug () << archivos.at(i);
    }
    //toma el nombre del archivo
    QString nombreArchivo = archivos.at(archivos.size()-1);
    //agrega el path y el nombre del archivo
    QString pathArchivo = nuevo + nombreArchivo;
    QFile file (pathArchivo);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString val;
    //todo los datos del archivo lo pasamos a un string
    val = file.readAll();
    qDebug () << "contenido"<<val;
    //cerramos el file
    file.close();



    //convertimos el string , para empezar a procesarlo
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    qDebug () << d;
    //¿lo convertimos a un objeto para procesarlo?
    QJsonObject obj = d.object();
    qDebug () <<"objeto " << obj;
    //obtenemos el valor de la llave "vertices
    QJsonValue value = obj.value(QString("vertices"));
    qDebug () << value;
    //lo convertimos a un array
    QJsonArray arr = value.toArray();
    //lo paso a una lista
    QList <QVariant> strVar = arr.toVariantList();

    QStringList strVertices;
    //los agrega
    for (int i = 0; i <strVar.size();i++){
        strVertices.append(strVar.at(i).toString());

    }
    qDebug () << "Lista de vertices";
    for (int i = 0; i<strVertices.size();i++){
        qDebug () << strVertices.at(i);
    }
    qDebug () << "====================================";
    //aca tomo las aristas
    QJsonValue value2 = obj.value(QString("aristas"));
    //lo convierto en un arrgle
    QJsonArray arr2 = value2.toArray();
    qDebug () << arr2.at(0);
    qDebug () << arr2.at(1);
    //debo tomar de cada posicion
    QJsonObject item2 = arr2.at(0).toObject();
    //obtengo cada objeto
    QJsonValue destino = item2["destino"];
    qDebug () << destino;
    qDebug () << destino.toString();
    QJsonValue origen = item2["origen"];
    qDebug () << origen;
    qDebug () << origen.toString();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

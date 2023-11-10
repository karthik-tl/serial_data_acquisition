#ifndef SERIALDATAAQUISITION_H
#define SERIALDATAAQUISITION_H

#include <QObject>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>

class SerialDataAquisition : public QObject
{
    Q_OBJECT
private:
    QSerialPort serial;
    QStringList recievedData;
    //QStringList m_dropdownElements;
    //Q_PROPERTY(QStringList d READ dropdownElements NOTIFY newDataRecieved)
//    QStringList dropdownElements() const {
//        return m_dropdownElements;
//    }
public:
    explicit SerialDataAquisition(QObject *parent = nullptr);
    Q_PROPERTY(QStringList listviewElements READ recievedData NOTIFY newDataRecieved)
signals:
    void  newDataRecieved();
public slots:
    QStringList availablePorts();
    void connectPort();
    void handleComboBoxSelection(const QString &selectedPort);
    void serialReceive();
};

#endif // SERIALDATAAQUISITION_H

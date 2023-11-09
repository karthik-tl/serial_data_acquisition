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
public:
    explicit SerialDataAquisition(QObject *parent = nullptr);
    Q_INVOKABLE QStringList availablePorts();
    void connectPort();
signals:
public slots:

};

#endif // SERIALDATAAQUISITION_H

#include "serialdataaquisition.h"
#include <QDebug>
QString port;
QString res;
SerialDataAquisition::SerialDataAquisition(QObject *parent)
    : QObject{parent}
{


}

QStringList SerialDataAquisition::availablePorts()
{
    QStringList ports;

    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
    {
        ports.append(info.portName());
    }

    return ports;
}

void SerialDataAquisition::handleComboBoxSelection(const QString &selectedPort)
{
    qDebug() << "Selected Item: " << selectedPort;
    port = selectedPort;
}

void SerialDataAquisition::connectPort()
{
    serial.setPortName(port);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    // We will chose the parity bits
    serial.setParity(QSerialPort::NoParity);
    // We will chose the stop bits
    serial.setStopBits(QSerialPort::OneStop);
    // We will chose the Flow controls
    serial.setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "helo";
    if (serial.open(QIODevice::ReadWrite))
    {

        qDebug() << "port opened";
    }
    else
    {
        qDebug() << "port opening failed" << serial.errorString();
    }
}

void SerialDataAquisition::serialReceive() {
    QByteArray readData;

    while (true) {
        if (serial.waitForReadyRead(1000)) { // Lower waiting time
            readData.append(serial.readAll());
            recievedData.append(readData);
            emit newDataRecieved();
            if (readData.contains('\n')) {
                break;
            }
        } else {
            break;
        }
    }

    if (!readData.isEmpty()) {
        QString result(readData);
        qDebug() << "Received: " << result;

       // signalCall(result);
    }
}

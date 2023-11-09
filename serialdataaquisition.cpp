#include "serialdataaquisition.h"

SerialDataAquisition::SerialDataAquisition(QObject *parent)
    : QObject{parent}
{

}
QStringList SerialDataAquisition::availablePorts()
{
    QStringList ports;
    QList<QSerialPortInfo> portInfoList = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &info : portInfoList)
    {
        ports.append(info.portName());
    }

    return ports;
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

#include "serialdataaqui.h"

SerialDataAqui::SerialDataAqui(QObject *parent)
    : QObject{parent}
{

}


QStringList SerialDataAqui::availablePorts()
{
    QStringList ports;
    QList<QSerialPortInfo> portInfoList = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &info : portInfoList)
    {
        ports.append(info.portName());
    }

    return ports;
}

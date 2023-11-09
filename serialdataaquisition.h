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
    //QStringList m_dropdownElements;
   // Q_PROPERTY(QStringList dropdownElements READ dropdownElements NOTIFY dropdownElementsChanged)
//    QStringList dropdownElements() const {
//        return m_dropdownElements;
//    }
public:
    explicit SerialDataAquisition(QObject *parent = nullptr);
signals:
public slots:
    QStringList availablePorts();
    void connectPort();
    void handleComboBoxSelection(const QString &selectedPort);

};

#endif // SERIALDATAAQUISITION_H

#ifndef SERIALDATAAQUI_H
#define SERIALDATAAQUI_H

#include <QObject>

class SerialDataAqui : public QObject
{
    Q_OBJECT
public:
    explicit SerialDataAqui(QObject *parent = nullptr);

signals:

};

#endif // SERIALDATAAQUI_H

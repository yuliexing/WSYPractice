#ifndef WSYLIST_H
#define WSYLIST_H

#include "wsy.h"
#include <QVector>
#include <QDebug>

class WSYList
{
public:
    WSYList();
    void makeWSYList(bool isQingEnable = true, bool isZuoEnable = true, bool isAoEnable = false);
    QVector<WSY> getWSYList();
    WSY randomChoose();
    int length() {return this->wsyList.size();}
private:
    QVector<WSY> wsyList;
};

#endif // WSYLIST_H

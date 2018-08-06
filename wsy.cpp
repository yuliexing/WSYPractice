#include "wsy.h"

WSY::WSY()
{

}

WSY::WSY(QString lmy, QString pingJm, QString pianJm, bool selectable)
{
    this->lmy = lmy;
    this->pingJm = pingJm;
    this->pianJm = pianJm;
    this->selectable = selectable;
}

QString WSY::toString()
{
//    QString retStr = "";
//    retStr += this->lmy + " ";
//    retStr += this->pingJm + " ";
//    retStr += this->pianJm + " ";
//    retStr += (this->selectable ? "True" : "False");
//    return retStr;
    return lmy + " " + pingJm + " " + pianJm;
}

bool WSY::isLmyRight(QString lmy)
{
    return this->lmy == lmy;
}

QString WSY::randomChoose(bool isPingEnable, bool isPianEnable)
{
    if (isPingEnable && isPianEnable)
    {
        return qrand() % 2 == 0 ? this->pingJm : this->pianJm;
    }
    if (isPianEnable)
    {
        return this->pianJm;
    }
    return this->pingJm;
}

QString WSY::getLmy()
{
    return this->lmy;
}

QString WSY::getPing()
{
    return this->pingJm;
}

QString WSY::getPian()
{
    return this->pianJm;
}

QString WSY::isPingOrPian(QString jm)
{
    if (pingJm == jm)
        return "平";
    return "片";
}

bool WSY::isSelectable()
{
    return this->selectable;
}

#ifndef WSY_H
#define WSY_H

#include <QString>

class WSY
{
public:
    WSY();
    WSY(QString lmy, QString pingJm, QString pianJm, bool selectable = true);
    QString randomChoose(bool isPingEnable = true, bool isPianEnable = true);
    bool isLmyRight(QString lmy);
    QString toString();
    QString getLmy();
    QString isPingOrPian(QString jm);
    bool isSelectable();
    QString getPing();
    QString getPian();
private:
    QString lmy;
    QString pingJm;
    QString pianJm;
    bool selectable;
};

#endif // WSY_H

#ifndef RESULTCOUNT_H
#define RESULTCOUNT_H

#include <wsy.h>
#include <QMap>

class ResultCount
{
public:
    ResultCount();
    void dealWithResult(QString jm, bool result);
    void dealWithSpecial(QString jm, WSY wsy);
    void dealWithCombo(int combo);
    void clear();
    QString getResult();
    int getTotal(){return totalCount;}
    int getCorrect(){return correctCount;}
    int getError(){return errorCount;}

private:
    int totalCount;
    int correctCount;
    int errorCount;
    int specialCount;
    int maxCombo;

    QMap<QString, int> correctMap;
    QMap<QString, int> errorMap;
    QMap<QString, WSY> specialMap;
};

#endif // RESULTCOUNT_H

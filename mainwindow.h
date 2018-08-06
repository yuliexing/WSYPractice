#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wsylist.h"
#include "resultcount.h"
#include <QHash>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void getNext();

    void dealWithStart();
    void dealWithEnd();
public slots:
    void dealWithStartClicked();
    void dealWithSubmitClicked();
    void dealWithHelpClicked();
    void dealWithZiClicked();
    void dealWithLmyChanged(QString str);
    void dealWithTimeOut();
    void showAllWSY();
private:
    Ui::MainWindow *ui;

    WSYList wsyList;
    QHash<QString, WSY> practiceMap;
    ResultCount resultCount;
    QString curLmy, nextLmy;
    QString curJm, nextJm;
    WSY curWSY, nextWSY;
    int inputCount;
    int mapSize;
    bool isStart;

    bool isQing, isZhuo, isAo;
    bool isPing, isPian;

    QTime startTime;
    QTimer timeout;
    const int TimeLimited = 4000;
    int combo;
    int maxCombo;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(Qt::WindowCloseButtonHint);
    setWindowIcon(QIcon(":/WSY/ico.ico"));
    setWindowTitle("音!");
    this->isStart = false;
    ui->countBox->setVisible(this->isStart);
    ui->isLmyRadio->setVisible(false);

    this->setFixedHeight(230);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::dealWithStartClicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::dealWithSubmitClicked);
    connect(ui->lmyEdit, &QLineEdit::textChanged, this, &MainWindow::dealWithLmyChanged);
    connect(ui->helpButton, &QPushButton::clicked, this, &MainWindow::dealWithHelpClicked);
    connect(ui->ziButton, &QPushButton::clicked, this, &MainWindow::showAllWSY);
//    timeout.singleShot(5000, Qt::CoarseTimer, this, SLOT(dealWithTimeOut()));
    connect(&timeout, &QTimer::timeout, this, &MainWindow::dealWithTimeOut);

    ui->label_5->setVisible(false);
    ui->correctLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNext()
{
    while (practiceMap.size() < mapSize)
    {
        WSY wsy = wsyList.randomChoose();
        QString jm = wsy.randomChoose(isPing, isPian);
        if (practiceMap.contains(jm))
            continue;
        practiceMap.insert(jm, wsy);
    }
    do{
        curJm = nextJm;
        curWSY = nextWSY;
        curLmy = curWSY.getLmy();
        do{
            int i = qrand() % practiceMap.size();
            nextJm = practiceMap.uniqueKeys().at(i);
            nextWSY = practiceMap[nextJm];
            nextLmy = nextWSY.getLmy();
            practiceMap.remove(nextJm);
        }while(curJm == nextJm);
    }while(curJm == "");

    if (ui->isJmRadio->isChecked())
    {
        ui->currentLabel->setText(curJm);
        ui->nextLabel->setText(nextJm);
    }

    if (ui->isLmyRadio->isChecked())
    {
        ui->currentLabel->setText(curLmy + " " + curWSY.isPingOrPian(curJm));
        ui->nextLabel->setText(nextLmy);
    }
    startTime = QTime::currentTime();
    if (ui->timeLimit->isChecked())
    {
        timeout.start(TimeLimited);
    }
}

void MainWindow::dealWithStartClicked()
{
    isStart = !isStart;
    if (isStart)
        dealWithStart();
    else
        dealWithEnd();

    ui->countBox->setVisible(isStart);
    ui->optionBox->setVisible(!isStart);
    ui->helpButton->setEnabled(isStart);
    ui->ziButton->setEnabled(isStart);
    ui->submitButton->setEnabled(isStart);
    ui->startButton->setText(isStart ? "关" : "开");
}

void MainWindow::dealWithStart()
{
    isQing = ui->qingCheck->isChecked();
    isZhuo = ui->zhuoCheck->isChecked();
    isAo   = ui->aoCheck->isChecked();
    isPing = ui->pingCheck->isChecked();
    isPian = ui->pianCheck->isChecked();
    if (!(isQing || isZhuo || isAo))
    {
        ui->qingCheck->setChecked(true);
        isQing = true;
    }
    if (!(isPing || isPian))
    {
        ui->pingCheck->setChecked(true);
        isPing = true;
    }
    wsyList.makeWSYList(isQing, isZhuo, isAo);
    mapSize = wsyList.length();
    if (! (isPing && isPian))
        mapSize *= 0.7;
    nextJm = "";
    practiceMap.clear();
    getNext();
    inputCount = 0;
    combo = 0;
    maxCombo = 0;

    resultCount.clear();
    ui->totalLabel->setText("0");
    ui->correctLabel->setText("0");
    ui->errorLabel->setText("0");
    ui->infoLabel->setText("");
    ui->lmyEdit->setFocus();
    this->setFixedHeight(120);
}

void MainWindow::dealWithEnd()
{
    timeout.stop();
    if (resultCount.getTotal() != 0)
    {
        QMessageBox::information(this, "结果", resultCount.getResult());
    }
    ui->currentLabel->setText("");
    ui->nextLabel->setText("");
    ui->infoLabel->setText("");
    ui->totalLabel->setText("");
    ui->correctLabel->setText("");
    ui->errorLabel->setText("");
    ui->lmyEdit->setText("");
    ui->beforeLabel->setText("");
    this->setFixedHeight(230);
}

void MainWindow::dealWithSubmitClicked()
{
    timeout.stop();
    QString inforStr = "";
    inputCount++;
    QString input = ui->lmyEdit->text().trimmed().toLower();
    bool isRight = false;
    if (ui->isJmRadio->isChecked())
    {
        isRight = (input == curLmy);
    }
    if (ui->isLmyRadio->isChecked())
    {
        isRight = (input == curJm);
    }
    inforStr += isRight ? "正确" : "错误";
    resultCount.dealWithResult(curJm, isRight);
    if (inputCount >= 3 || isRight)
    {
        if (inputCount >= 3)
        {
            resultCount.dealWithSpecial(curJm, curWSY);
        }
        inputCount = 0;
        double coustTime = (double)startTime.msecsTo(QTime::currentTime()) / 1000;
        if (isRight && (coustTime < 1.5))
        {
            combo++;
            resultCount.dealWithCombo(combo);
            if (combo > 2)
            {
                inforStr = "COMBO " + QString::number(combo);
            }
            else
            {
                inforStr += " " + QString::number(coustTime);
            }
        }
        else
        {
            combo = 0;
            inforStr += " " + QString::number(coustTime);
        }
        ui->beforeLabel->setText(curWSY.toString());
        getNext();
    }
    else
    {
        if (!isRight)
        {
            combo = 0;
        }
        if (ui->timeLimit->isChecked())
        {
            timeout.start(TimeLimited);
        }
    }
    ui->lmyEdit->setText("");
    ui->totalLabel->setText(QString::number(resultCount.getTotal()));
    ui->correctLabel->setText(QString::number(resultCount.getCorrect()));
    ui->errorLabel->setText(QString::number(resultCount.getError()));
    ui->infoLabel->setText(inforStr);
}

void MainWindow::dealWithHelpClicked()
{
//    ui->lmyEdit->setText(curWSY.getLmy());
    QToolTip::showText(mapToGlobal(ui->lmyEdit->pos() -= QPoint(0, 40)), curWSY.toString(), this, QRect(), 500);
}

void MainWindow::dealWithZiClicked()
{

}

void MainWindow::dealWithLmyChanged(QString str)
{
    ui->infoLabel->setText("");
    if (!str.isEmpty() && !str.trimmed().isEmpty() && str.endsWith(" "))
    {
        dealWithSubmitClicked();
    }
}

void MainWindow::dealWithTimeOut()
{
    ui->beforeLabel->setText(curWSY.toString());
    timeout.stop();
    resultCount.dealWithResult(curJm, false);
    inputCount = 0;
    getNext();
    ui->lmyEdit->setText("");
    ui->totalLabel->setText(QString::number(resultCount.getTotal()));
    ui->correctLabel->setText(QString::number(resultCount.getCorrect()));
    ui->errorLabel->setText(QString::number(resultCount.getError()));
    ui->infoLabel->setText("时间到!");
}

void MainWindow::showAllWSY()
{
    QVector<WSY> wsyList = this->wsyList.getWSYList();
    QString output = "";
    int i = 0;
    foreach (WSY wsy, wsyList) {
        output.append(wsy.getLmy());
        if (ui->pingCheck->isChecked())
        {
            output.append(wsy.getPing());
        }
        if (ui->pianCheck->isChecked())
        {
            output.append(wsy.getPian());
        }
        if (i++ == 4)
        {
            i = 0;
            output.append("\r\n");
            continue;
        }
        if (wsy.getLmy() != "")
            output.append(" | ");
    }
    QMessageBox::information(this, "", output);
}

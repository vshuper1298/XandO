#ifndef XANDO_H
#define XANDO_H

#include <QWidget>
#include <QString>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

class QPushButton;
class XandO : public QWidget
{
Q_OBJECT
public:
explicit XandO(QWidget *parent = 0);
~XandO();

public:
void setSide(QString value);
QPushButton *pushButtonYes;

private:
bool isAllButtonClicked();
bool isButtonEmpty(int value);
bool isAllButtonEmpty();
bool isCombinationActive(int value1, int value2, int value3);

void isGameOver();
void createWidgets();
void waitForMove();
void disableAllButtons(bool value);
void enemyMove(int value);
void buttonDisconnect(int value);
void buttonClicked(QPushButton *button);
bool endOfGameCombinaton(int value1, int value2, int value3);
void gameOver();

private:
QGridLayout *windowLayout;
QString side;
QString enemy;
QComboBox *comboBox;
QLabel *label;
QPushButton *pushButton;
QPushButton *pushButton_2;
QPushButton *pushButton_3;
QPushButton *pushButton_4;
QPushButton *pushButton_5;
QPushButton *pushButton_6;
QPushButton *pushButton_7;
QPushButton *pushButton_8;
QPushButton *pushButton_9;
QPushButton *pushButtonNo;
QList<QPushButton*> list;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
};

#endif // XANDO_H

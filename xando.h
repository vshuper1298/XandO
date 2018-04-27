#ifndef XANDO_H
#define XANDO_H

#include <QWidget>
#include <QString>
#include <QComboBox>
#include <QLabel>

class QPushButton;
class XandO : public QWidget
{
Q_OBJECT
public:
explicit XandO(QWidget *parent = 0);
~XandO();

signals:
    void allButtonUsed();
private:
// Окремий метод для створення інтерфейсу програми
void createWidgets();
bool isAllButtonClicked();
void isAllButtonUsed();
void waitForMove();
void disableButtons(bool value);
void enemyMove(int value);
bool isButtonEmpty(int value);
bool isAllButtonEmpty();

private:
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

private slots:
    void setSide();
    void gameOver();
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

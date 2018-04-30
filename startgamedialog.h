#ifndef STARTGAMEDIALOG_H
#define STARTGAMEDIALOG_H

#include <QDialog>
#include "xando.h"

class StartGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartGameDialog(QWidget *parent = 0);
    ~StartGameDialog();
        QString side;

private:
    XandO game;
    QLabel *label;
    QPushButton *pushButtonX;
    QPushButton *pushButtonO;
    QPushButton *pushButtonStart;

private:
void createWidgets();

private slots:
    void slotButtonX();
    void slotButtonO();
    void slotButtonStart();
};

#endif // STARTGAMEDIALOG_H

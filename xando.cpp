#include "xando.h"
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QDebug>

XandO::XandO(QWidget *parent) :
QWidget(parent)
{
resize(300, 300);
setWindowTitle("X's and O's");
createWidgets();
list << pushButton << pushButton << pushButton_2 << pushButton_3 << pushButton_4 << pushButton_5 << pushButton_6 << pushButton_7 << pushButton_8 << pushButton_9;

connect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
connect(pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
connect(pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
connect(pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
connect(pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
connect(pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));
connect(pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_7_clicked()));
connect(pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
connect(pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked()));
connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setSide()));

}

XandO::~XandO()
{

}

bool XandO::isGameOver()
{
    if (isCombinationActive(1, 2, 3) ||
        isCombinationActive(7, 8, 9) ||
        isCombinationActive(1, 4, 7) ||
        isCombinationActive(3, 6, 9) ||
        isCombinationActive(2, 5, 8) ||
        isCombinationActive(4, 5, 6) ||
        isCombinationActive(1, 5, 9) ||
        isCombinationActive(3, 5, 7) ||
        isAllButtonClicked())
        gameOver();
}

bool XandO::isCombinationActive(int value1, int value2, int value3)
{
    if (list.at(value1)->text() == list.at(value2)->text() && list.at(value1)->text() == list.at(value3)->text() && list.at(value2)->text() == list.at(value3)->text() && !list.at(value1)->text().isEmpty())
        return true;
    else
        return false;
}

bool XandO::isAllButtonClicked()
{
    if (pushButton->text()!=NULL && pushButton_2->text()!=NULL && pushButton_3->text()!=NULL && pushButton_4->text()!=NULL && pushButton_5->text()!=NULL && pushButton_6->text()!=NULL && pushButton_7->text()!=NULL && pushButton_8->text()!=NULL && pushButton_9->text()!=NULL)
        return true;
    else
        return false;
}

void XandO::createWidgets()
{
QGridLayout *windowLayout = new QGridLayout;
setLayout(windowLayout);
comboBox = new QComboBox;
comboBox->addItem("X");
comboBox->addItem("O");
label = new QLabel;
label->setVisible(true);
pushButton = new QPushButton;
pushButton_2 = new QPushButton;
pushButton_3 = new QPushButton;
pushButton_4 = new QPushButton;
pushButton_5 = new QPushButton;
pushButton_6 = new QPushButton;
pushButton_7 = new QPushButton;
pushButton_8 = new QPushButton;
pushButton_9 = new QPushButton;

windowLayout->addWidget(comboBox, 0, 0 , 1, 3);
windowLayout->addWidget(pushButton, 1, 0);
windowLayout->addWidget(pushButton_2, 1, 1);
windowLayout->addWidget(pushButton_3, 1, 2);
windowLayout->addWidget(pushButton_4, 2, 0);
windowLayout->addWidget(pushButton_5, 2, 1);
windowLayout->addWidget(pushButton_6, 2, 2);
windowLayout->addWidget(pushButton_7, 3, 0);
windowLayout->addWidget(pushButton_8, 3, 1);
windowLayout->addWidget(pushButton_9, 3, 2);
windowLayout->addWidget(label, 4, 0 , 1, 3);

pushButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButton_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void XandO::setSide()
{
    side=comboBox->currentText();
    if (side=="X")
        enemy="O";
    else if (side=="O")
        enemy="X";
}

void XandO::endOfGameCombinaton(int value1, int value2, int value3)
{
    if (isCombinationActive(value1, value2, value3))
    {
        list.at(value1)->setStyleSheet("background-color: black");
        list.at(value2)->setStyleSheet("background-color: black");
        list.at(value3)->setStyleSheet("background-color: black");
        label->setText(list.at(value1)->text()+" WINS");
    }
}

void XandO::gameOver()
{
    endOfGameCombinaton(1, 2, 3);
    endOfGameCombinaton(7, 8, 9);
    endOfGameCombinaton(1, 4, 7);
    endOfGameCombinaton(3, 6, 9);
    endOfGameCombinaton(2, 5, 8);
    endOfGameCombinaton(4, 5, 6);
    endOfGameCombinaton(1, 5, 9);
    endOfGameCombinaton(3, 5, 7);

    if (isAllButtonClicked()&&label->text().isEmpty())
    {
        label->setText("DRAW");
    }
}

void XandO::buttonClicked(QPushButton *button)
{
    button->setText(side);
    button->setDisabled(true);
    buttonDisconnect(list.indexOf(button));
    isGameOver();
    waitForMove();
}

void XandO::on_pushButton_clicked()
{
    buttonClicked(pushButton);
}

void XandO::on_pushButton_2_clicked()
{
    buttonClicked(pushButton_2);
}

void XandO::on_pushButton_3_clicked()
{
    buttonClicked(pushButton_3);
}

void XandO::on_pushButton_4_clicked()
{
    buttonClicked(pushButton_4);
}

void XandO::on_pushButton_5_clicked()
{
    buttonClicked(pushButton_5);
}

void XandO::on_pushButton_6_clicked()
{
    buttonClicked(pushButton_6);
}

void XandO::on_pushButton_7_clicked()
{
    buttonClicked(pushButton_7);
}

void XandO::on_pushButton_8_clicked()
{
    buttonClicked(pushButton_8);
}

void XandO::on_pushButton_9_clicked()
{
    buttonClicked(pushButton_9);
}

void XandO::waitForMove()
{
    disableAllButtons(true);
    int x = (qrand() % 9)+1;
    qDebug() << isButtonEmpty(x);
    if (isButtonEmpty(x))
        enemyMove(x);
    else
    {
        bool b = false;
        while (b != true)
        {
            x = (qrand() % 9)+1;
            b=isButtonEmpty(x);
            qDebug() << x;
            if (isAllButtonClicked())
                break;
        }
        if (isAllButtonClicked()!=true)
            enemyMove(x);
    }
    isGameOver();
    disableAllButtons(false);
}

void XandO::disableAllButtons(bool value)
{          
    for(int i = 1; i < 10; i++)
    {
        list.at(i)->setDisabled(value);
    }
}

void XandO::enemyMove(int value)
{
    list.at(value)->setText(enemy);
    buttonDisconnect(value);
}

bool XandO::isButtonEmpty(int value)
{
    if (list.at(value)->text().isEmpty())
        return true;
    else
        return false;
}

void XandO::buttonDisconnect(int value)
{
    switch (value)
    {
        case 1: pushButton->disconnect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked())); break;
        case 2: pushButton_2->disconnect(pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked())); break;
        case 3: pushButton_3->disconnect(pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked())); break;
        case 4: pushButton_4->disconnect(pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked())); break;
        case 5: pushButton_5->disconnect(pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked())); break;
        case 6: pushButton_6->disconnect(pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked())); break;
        case 7: pushButton_7->disconnect(pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_7_clicked())); break;
        case 8: pushButton_8->disconnect(pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked())); break;
        case 9: pushButton_9->disconnect(pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked())); break;
    }
}

#include "xando.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QComboBox>
#include <QLabel>
#include <QDebug>

XandO::XandO(QWidget *parent) :
QWidget(parent)
{
resize(300, 300);
setWindowTitle("X's and O's");
createWidgets();


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
connect(this, SIGNAL(allButtonUsed()), this, SLOT(gameOver()));

}

XandO::~XandO()
{

}

void XandO::isAllButtonUsed()
{
    if (isAllButtonClicked())
        emit allButtonUsed();
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

void XandO::gameOver()
{
    if (pushButton->text()==side && pushButton_2->text()==side && pushButton_3->text()==side)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_2->setStyleSheet("background-color: black");
        pushButton_3->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton_7->text()==side && pushButton_8->text()==side && pushButton_9->text()==side)
    {
        pushButton_7->setStyleSheet("background-color: black");
        pushButton_8->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton->text()==side && pushButton_4->text()==side && pushButton_7->text()==side)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_4->setStyleSheet("background-color: black");
        pushButton_7->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton_3->text()==side && pushButton_6->text()==side && pushButton_9->text()==side)
    {
        pushButton_3->setStyleSheet("background-color: black");
        pushButton_6->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton_2->text()==side && pushButton_5->text()==side && pushButton_8->text()==side)
    {
        pushButton_2->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_8->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton_4->text()==side && pushButton_5->text()==side && pushButton_6->text()==side)
    {
        pushButton_4->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_6->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton->text()==side && pushButton_5->text()==side && pushButton_9->text()==side)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }

    else if (pushButton_3->text()==side && pushButton_5->text()==side && pushButton_7->text()==side)
    {
        pushButton_3->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_7->setStyleSheet("background-color: black");
        label->setText(side+" WINS");
    }
    else if (pushButton->text()==enemy && pushButton_2->text()==enemy && pushButton_3->text()==enemy)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_2->setStyleSheet("background-color: black");
        pushButton_3->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton_7->text()==enemy && pushButton_8->text()==enemy && pushButton_9->text()==enemy)
    {
        pushButton_7->setStyleSheet("background-color: black");
        pushButton_8->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton->text()==enemy && pushButton_4->text()==enemy && pushButton_7->text()==enemy)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_4->setStyleSheet("background-color: black");
        pushButton_7->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton_3->text()==enemy && pushButton_6->text()==enemy && pushButton_9->text()==enemy)
    {
        pushButton_3->setStyleSheet("background-color: black");
        pushButton_6->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton_2->text()==enemy && pushButton_5->text()==enemy && pushButton_8->text()==enemy)
    {
        pushButton_2->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_8->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton_4->text()==enemy && pushButton_5->text()==enemy && pushButton_6->text()==enemy)
    {
        pushButton_4->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_6->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton->text()==enemy && pushButton_5->text()==enemy && pushButton_9->text()==enemy)
    {
        pushButton->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_9->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }

    else if (pushButton_3->text()==enemy && pushButton_5->text()==enemy && pushButton_7->text()==enemy)
    {
        pushButton_3->setStyleSheet("background-color: black");
        pushButton_5->setStyleSheet("background-color: black");
        pushButton_7->setStyleSheet("background-color: black");
        label->setText(enemy+" WINS");
    }
    else
    {
        label->setText("DRAW");
    }
}

void XandO::on_pushButton_clicked()
{
    pushButton->setText(side);
    pushButton->setDisabled(true);
    pushButton->disconnect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_2_clicked()
{
    pushButton_2->setText(side);
    pushButton_2->setDisabled(true);
    pushButton_2->disconnect(pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_3_clicked()
{
    pushButton_3->setText(side);
    pushButton_3->setDisabled(true);
    pushButton_3->disconnect(pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_4_clicked()
{
    pushButton_4->setText(side);
    pushButton_4->setDisabled(true);
    pushButton_4->disconnect(pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_5_clicked()
{
    pushButton_5->setText(side);
    pushButton_5->setDisabled(true);
    pushButton_5->disconnect(pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_6_clicked()
{
    pushButton_6->setText(side);
    pushButton_6->setDisabled(true);
    pushButton_6->disconnect(pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_7_clicked()
{
    pushButton_7->setText(side);
    pushButton_7->setDisabled(true);
    pushButton_7->disconnect(pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_7_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_8_clicked()
{
    pushButton_8->setText(side);
    pushButton_8->setDisabled(true);
    pushButton_8->disconnect(pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::on_pushButton_9_clicked()
{
    pushButton_9->setText(side);
    pushButton_9->setDisabled(true);
    pushButton_9->disconnect(pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked()));
    isAllButtonUsed();
    waitForMove();
}

void XandO::waitForMove()
{
    disableButtons(true);
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
    isAllButtonUsed();
    disableButtons(false);
}

void XandO::disableButtons(bool value)
{
    pushButton->setDisabled(value);
    pushButton_2->setDisabled(value);
    pushButton_3->setDisabled(value);
    pushButton_4->setDisabled(value);
    pushButton_5->setDisabled(value);
    pushButton_6->setDisabled(value);
    pushButton_7->setDisabled(value);
    pushButton_8->setDisabled(value);
    pushButton_9->setDisabled(value);
}

void XandO::enemyMove(int value)
{
    switch (value)
    {
    case 1:
            pushButton->setText(enemy);
        break;
    case 2:
            pushButton_2->setText(enemy);
        break;
    case 3:
            pushButton_3->setText(enemy);
        break;
    case 4:
            pushButton_4->setText(enemy);
        break;
    case 5:
            pushButton_5->setText(enemy);
        break;
    case 6:
            pushButton_6->setText(enemy);
        break;
    case 7:
            pushButton_7->setText(enemy);
        break;
    case 8:
            pushButton_8->setText(enemy);
        break;
    case 9:
            pushButton_9->setText(enemy);
        break;
    }
}

bool XandO::isButtonEmpty(int value)
{
    switch (value)
    {
    case 1:
        if (pushButton->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 2:
        if (pushButton_2->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 3:
        if (pushButton_3->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 4:
        if (pushButton_4->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 5:
        if (pushButton_5->text()!="X"&&pushButton_5->text()!="O")
            return true;
        else
            return false;
        break;
    case 6:
        if (pushButton_6->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 7:
        if (pushButton_7->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 8:
        if (pushButton_8->text().isEmpty())
            return true;
        else
            return false;
        break;
    case 9:
        if (pushButton_9->text().isEmpty())
            return true;
        else
            return false;
        break;
    }
}
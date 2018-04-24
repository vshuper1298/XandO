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
connect(this, SIGNAL(allButtonClicked()), this, SLOT(gameOver()));

}

XandO::~XandO()
{

}

void XandO::isAllButtonClicked()
{
    if (pushButton->text()!=NULL&&pushButton_2->text()!=NULL&&pushButton_3->text()!=NULL&&pushButton_4->text()!=NULL&&pushButton_5->text()!=NULL&&pushButton_6->text()!=NULL&&pushButton_7->text()!=NULL&&pushButton_8->text()!=NULL&&pushButton_9->text()!=NULL)
        emit allButtonClicked();
}

void XandO::createWidgets()
{
QGridLayout *lCalcLayout = new QGridLayout;
setLayout(lCalcLayout);
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

lCalcLayout->addWidget(comboBox, 0, 0 , 1, 3);
lCalcLayout->addWidget(pushButton, 1, 0);
lCalcLayout->addWidget(pushButton_2, 1, 1);
lCalcLayout->addWidget(pushButton_3, 1, 2);
lCalcLayout->addWidget(pushButton_4, 2, 0);
lCalcLayout->addWidget(pushButton_5, 2, 1);
lCalcLayout->addWidget(pushButton_6, 2, 2);
lCalcLayout->addWidget(pushButton_7, 3, 0);
lCalcLayout->addWidget(pushButton_8, 3, 1);
lCalcLayout->addWidget(pushButton_9, 3, 2);
lCalcLayout->addWidget(label, 4, 0 , 1, 3);

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
    else
    {
        label->setText("DRAW");
    }
}

void XandO::on_pushButton_clicked()
{
    pushButton->setText(side);
    pushButton->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_2_clicked()
{
    pushButton_2->setText(side);
    pushButton_2->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_3_clicked()
{
    pushButton_3->setText(side);
    pushButton_3->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_4_clicked()
{
    pushButton_4->setText(side);
    pushButton_4->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_5_clicked()
{
    pushButton_5->setText(side);
    pushButton_5->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_6_clicked()
{
    pushButton_6->setText(side);
    pushButton_6->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_7_clicked()
{
    pushButton_7->setText(side);
    pushButton_7->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_8_clicked()
{
    pushButton_8->setText(side);
    pushButton_8->setDisabled(true);
    isAllButtonClicked();
}

void XandO::on_pushButton_9_clicked()
{
    pushButton_9->setText(side);
    pushButton_9->setDisabled(true);
    isAllButtonClicked();
}


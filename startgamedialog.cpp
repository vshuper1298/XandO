#include "startgamedialog.h"
#include "ui_startgamedialog.h"


StartGameDialog::StartGameDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(300, 300);
    setWindowTitle("X's and O's");
    createWidgets();

    connect(pushButtonX, SIGNAL(clicked()), this, SLOT(slotButtonX()));
    connect(pushButtonO, SIGNAL(clicked()), this, SLOT(slotButtonO()));
    connect(pushButtonStart, SIGNAL(clicked()), this, SLOT(slotButtonStart()));
}

StartGameDialog::~StartGameDialog()
{

}

void StartGameDialog::slotButtonX()
{
    game.setSide("X");
    pushButtonX->setDisabled(true);
    pushButtonO->setDisabled(false);
    pushButtonStart->setDisabled(false);
}

void StartGameDialog::slotButtonO()
{
    game.setSide("O");
    pushButtonO->setDisabled(true);
    pushButtonX->setDisabled(false);
    pushButtonStart->setDisabled(false);
}

void StartGameDialog::slotButtonStart()
{
    game.show();
    this->close();
}

void StartGameDialog::createWidgets()
{
QGridLayout *windowLayout = new QGridLayout;
setLayout(windowLayout);

label = new QLabel;
label->setAlignment(Qt::AlignCenter);
label->setText("Choose your side!");
pushButtonX = new QPushButton;
pushButtonX->setText("X");
pushButtonO = new QPushButton;
pushButtonO->setText("O");
pushButtonStart = new QPushButton;
pushButtonStart->setText("Start");
pushButtonStart->setDisabled(true);

windowLayout->addWidget(label, 1, 0, 1, 2);
windowLayout->addWidget(pushButtonX, 2, 0);
windowLayout->addWidget(pushButtonO, 2, 1);
windowLayout->addWidget(pushButtonStart, 3, 0 , 1, 2);

pushButtonX->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButtonO->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
pushButtonStart->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

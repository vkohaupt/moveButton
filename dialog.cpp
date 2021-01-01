
#include <QVBoxLayout>
#include <QPushButton>

#include "dialog.h"
#include "QvkMoveButton.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QvkMoveButton *vkMoveButton = new QvkMoveButton;
    layout->addWidget( vkMoveButton );

    QPushButton *pushButtonOn = new QPushButton();
    pushButtonOn->setGeometry( 100, 80, 100, 30 );
    pushButtonOn->setText( "On" );
    connect( pushButtonOn, SIGNAL( clicked() ), vkMoveButton, SLOT( slot_On() ) );
    layout->addWidget( pushButtonOn );

    QPushButton *pushButtonOff = new QPushButton();
    pushButtonOff->setGeometry( 100, 80, 100, 30 );
    pushButtonOff->setText( "Off" );
    connect( pushButtonOff, SIGNAL( clicked() ), vkMoveButton, SLOT( slot_Off() ) );
    layout->addWidget( pushButtonOff );

    setWindowTitle(tr("MoveButton"));
    resize(300, 200);
}


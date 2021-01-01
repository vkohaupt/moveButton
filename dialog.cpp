
#include <QVBoxLayout>
#include <QPushButton>

#include "dialog.h"
#include "QvkMoveButton.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QvkMoveButton *vkMoveButton = new QvkMoveButton;

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget( vkMoveButton );

    QPushButton *pushButtonStart = new QPushButton();
    pushButtonStart->setGeometry( 100, 80, 100, 30 );
    pushButtonStart->setText( "On" );
    connect( pushButtonStart, SIGNAL( clicked() ), vkMoveButton, SLOT( slot_Start() ) );
    layout->addWidget( pushButtonStart );

    setWindowTitle(tr("MoveButton"));
    resize(360, 145);
}



#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

#include "dialog.h"
#include "QvkMoveButton.h"
#include "QvkSpezialCheckbox.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    ui.setupUi( this );

    QvkSpezialCheckbox *vkSpezialCheckbox = new QvkSpezialCheckbox( this );
    ui.horizontalLayout->insertWidget( 0, vkSpezialCheckbox );
    connect( vkSpezialCheckbox, SIGNAL( clicked( bool ) ), this, SLOT( slot_XYZ( bool ) ) );

/*
    QvkMoveButton *vkMoveButton = new QvkMoveButton( this );
    ui.horizontalLayout->insertWidget( 0, vkMoveButton );
    connect( vkMoveButton, SIGNAL( signal_stateON( bool ) ), this, SLOT( slot_XYZ( bool ) ) );
//    vkMoveButton->setStatus( true );
//    vkMoveButton->slot_clicked();
qDebug() << "000000000000000000000000000000000000000000";
    vkMoveButton->click();
qDebug() << "111111111111111111111111111111111111111111";
*/


    setWindowTitle( tr( "MoveButton" ) );
    resize( 300, 200 );
}

void Dialog::slot_XYZ( bool value )
{
    if ( value == true )
        qDebug() << "true";

    if ( value == false )
        qDebug() << "false";
}

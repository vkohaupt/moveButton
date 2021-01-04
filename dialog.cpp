
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

#include "dialog.h"
#include "QvkMoveButton.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    ui.setupUi( this );

    QvkMoveButton *vkMoveButton = new QvkMoveButton;
    ui.horizontalLayout->insertWidget( 0, vkMoveButton );
    connect( vkMoveButton, SIGNAL( signal_stateON( bool ) ), this, SLOT( slot_XYZ( bool ) ) );
//    connect( vkMoveButton, SIGNAL( signal_stateON( bool ) ), this, SLOT( slot_XYZ( bool ) ) );
//    vkMoveButton->setStatus( true );
//    vkMoveButton->slot_clicked();
//    vkMoveButton->clicked();
qDebug() << "Dialog" << "11111111111111111111111111";
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

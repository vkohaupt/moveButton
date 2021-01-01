
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

#include "dialog.h"
#include "QvkMoveButton.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QvkMoveButton *vkMoveButton = new QvkMoveButton;
    layout->addWidget( vkMoveButton );
    connect( vkMoveButton, SIGNAL( signal_stateON( bool ) ), this, SLOT( slot_XYZ( bool ) ) );

    setWindowTitle(tr("MoveButton"));
    resize(300, 200);
}

void Dialog::slot_XYZ( bool value )
{
    if ( value == true )
        qDebug() << "true";

    if ( value == false )
        qDebug() << "false";
}

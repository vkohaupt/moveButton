
#include <QtWidgets>

#include "QvkMoveButton.h"

QvkMoveButton::QvkMoveButton( QWidget *parent )
    : QPushButton( parent )
{
    setBackgroundRole( QPalette::Midlight );
    setAutoFillBackground( true );

    connect( this, SIGNAL( clicked() ), this, SLOT( slot_clicked() ) );

    setObjectName( "moveButtonOnOff" );
    setMinimumWidth( 100 );
    step = 0;
    isOn = false;
}

void QvkMoveButton::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event );
    QPainter painter( this );
    painter.setRenderHints( QPainter::Antialiasing, true );

    button_x = 2;
    button_y = 4;
    button_width = width() - 4;
    button_height = height() - 8;
    penWidth = 1;
    radius = 11;
    margin = 3;

    if ( isOn == false )
    {
        QPen penOff;
        penOff.setWidthF( penWidth );
        penOff.setColor( Qt::black );
        painter.setPen( penOff );

        QBrush brushButtonOn( Qt::red );
        painter.setBrush( brushButtonOn );

        QRectF rectButtonOff( button_x, button_y, button_width, button_height );
        if ( step > button_width / 2 ) {
            brushButtonOn.setColor( Qt::green );
            painter.setBrush( brushButtonOn );
        }
        QPainterPath painterPathButtonOff;
        painterPathButtonOff.addRoundedRect( rectButtonOff, radius, radius, Qt::AbsoluteSize );
        painter.drawPath( painterPathButtonOff );

        QFont fontOff = painter.font();
        fontOff.setPixelSize( 14 );
        fontOff.setBold( true );
        QPen penFontOff;
        penFontOff.setColor( Qt::white );
        painter.setPen( penFontOff );
        painter.setFont( fontOff );
        painter.drawText( 10, 23, "OFF" );

        QPen penSliderOff;
        penSliderOff.setColor( Qt::black );
        painter.setPen( penSliderOff );
        qreal slider_x = button_width / 3 + button_x;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 3 * 2;
        qreal slider_height = button_height;
        QRectF rectSliderOff( slider_x + margin - step, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin );
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        QPainterPath painterPathSliderOff;
        painterPathSliderOff.addRoundedRect( rectSliderOff, radius - margin, radius - margin, Qt::AbsoluteSize );
        painter.drawPath( painterPathSliderOff );
    }

    if ( isOn == true )
    {
        QPen penOn;
        penOn.setColor( Qt::black );
        penOn.setWidthF( penWidth );
        painter.setPen( penOn );

        QBrush brushButtonOn( Qt::darkGreen );
        painter.setBrush( brushButtonOn );

        QRectF rectButtonOn( button_x, button_y, button_width, button_height );
        if ( step == 0 )
        {
            brushButtonOn.setColor( Qt::red );
            painter.setBrush( brushButtonOn );
        }
        QPainterPath painterPathButtonOn;
        painterPathButtonOn.addRoundedRect( rectButtonOn, radius, radius, Qt::AbsoluteSize );
        painter.drawPath( painterPathButtonOn );

        QFont fontOn = painter.font();
        fontOn.setPixelSize( 14 );
        fontOn.setBold( true );
        QPen penFontOn;
        penFontOn.setColor( Qt::white );
        painter.setPen( penFontOn );
        painter.setFont( fontOn );
        painter.drawText( 67, 23, "ON" );

        QPen penSliderOn;
        penSliderOn.setColor( Qt::black );
        painter.setPen( penSliderOn );
        qreal slider_x = button_width / 3;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 3 * 2;
        qreal slider_height = button_height;
        QRectF rectSliderOn( slider_x + margin - step + 1, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin );
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        QPainterPath painterPathSliderOn;
        painterPathSliderOn.addRoundedRect( rectSliderOn, radius - margin, radius - margin, Qt::AbsoluteSize );
        painter.drawPath( painterPathSliderOn );
    }
}


void QvkMoveButton::timerEvent( QTimerEvent *event )
{
    if ( event->timerId() == timer.timerId() )
    {
        if ( isOn == false )
        {
            if ( step < button_width / 3 )
            {
                step++;
                repaint();
            }
            else
            {
                timer.stop();
                step = button_width / 3;
                isOn = true;
                repaint();
                emit signal_stateON( isOn );
            }
        }

        if ( isOn == true )
        {
            if ( step > 0 )
            {
                step--;
                repaint();
            }
            else
            {
                timer.stop();
                step = 0;
                isOn = false;
                repaint();
                emit signal_stateON( isOn );
            }
        }
    } else
    {
        QWidget::timerEvent( event );
    }
}


void QvkMoveButton::slot_clicked()
{
    timer.start( 10, this );
}


void QvkMoveButton::setStatus( bool value )
{
    if ( value == true )
    {
        isOn = false;
        slot_clicked();
    }
}

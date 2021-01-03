
#include <QtWidgets>

#include "QvkMoveButton.h"

QvkMoveButton::QvkMoveButton( QWidget *parent )
    : QPushButton( parent )
{
    setBackgroundRole( QPalette::Midlight );
    setAutoFillBackground( true );

    connect( this, SIGNAL( clicked() ), this, SLOT( slot_clicked() ) );

    step = 0;
    isOn = false;
}

void QvkMoveButton::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event );
    QPainter painter( this );
    painter.setRenderHints( QPainter::Antialiasing, true );

    qDebug() << x() << y() << width() << height();

    button_x = 2;
    button_y = 2;
    button_width = width() - 4;
    button_height = height() - 4;
    penWidth = 1;
    radius = 11;
    margin = 3;

    if ( isOn == false )
    {
        QPen pen;
        pen.setWidthF( penWidth );
        pen.setColor( Qt::black );
        painter.setPen( pen );

        QBrush brushButton( Qt::red );
        painter.setBrush( brushButton );

        QRectF rectButton( button_x, button_y, button_width, button_height );
        if ( step > button_width / 2 ) {
            brushButton.setColor( Qt::green );
            painter.setBrush( brushButton );
        }
        QPainterPath painterPathButton;
        painterPathButton.addRoundedRect( rectButton, radius, radius, Qt::AbsoluteSize );
        painter.drawPath( painterPathButton );

        QFont fontOn = painter.font();
        fontOn.setPixelSize( 20 );
        painter.setFont( fontOn );
        painter.drawText( 10, 25, "ON" );

        qreal slider_x = button_width / 3 + button_x;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 3 * 2;
        qreal slider_height = button_height;
        QRectF rectSlider( slider_x + margin - step, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin );
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        QPainterPath painterPathSlider;
        painterPathSlider.addRoundedRect( rectSlider, radius - margin, radius - margin, Qt::AbsoluteSize );
        painter.drawPath( painterPathSlider );
    }

    if ( isOn == true )
    {
        QPen pen;
        pen.setWidthF( penWidth );
        painter.setPen( pen );

        QBrush brushButton( Qt::green );
        painter.setBrush( brushButton );

        QRectF rectButton( button_x, button_y, button_width, button_height );
        if ( step == 0 )
        {
            brushButton.setColor( Qt::red );
            painter.setBrush( brushButton );
        }
        QPainterPath painterPathButton;
        painterPathButton.addRoundedRect( rectButton, radius, radius, Qt::AbsoluteSize );
        painter.drawPath( painterPathButton );

        QFont fontOn = painter.font();
        fontOn.setPixelSize( 20 );
        painter.setFont( fontOn );
        painter.drawText( 80, 25, "OFF" );

        qreal slider_x = button_width / 3;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 3 * 2;
        qreal slider_height = button_height;
        QRectF rectSlider( slider_x + margin - step, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin );
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        QPainterPath painterPathSlider;
        painterPathSlider.addRoundedRect( rectSlider, radius - margin, radius - margin, Qt::AbsoluteSize );
        painter.drawPath( painterPathSlider );
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
                update();
            }
            else
            {
                timer.stop();
                step = button_width / 3;
                isOn = true;
                update();
                emit signal_stateON( isOn );
            }
        }

        if ( isOn == true )
        {
            if ( step > 0 )
            {
                step--;
                update();
            }
            else
            {
                timer.stop();
                step = 0;
                isOn = false;
                update();
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

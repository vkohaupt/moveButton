
#include <QtWidgets>

#include "QvkMoveButton.h"

QvkMoveButton::QvkMoveButton(QWidget *parent)
    : QPushButton(parent)
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

    button_x = 1;
    button_y = 1;
    button_width = width();
    button_height = height();

    if ( isOn == false )
    {
        QPen pen;
        qreal penWidth = 1.0;
        pen.setWidthF( penWidth );
        painter.setPen( pen );

        QBrush brushButton( Qt::red );
        painter.setBrush( brushButton );

        QRectF rectButton( button_x, button_y, button_width, button_height );
        if ( step > button_width / 2 ) {
            brushButton.setColor( Qt::green );
            painter.setBrush( brushButton );
        }
        painter.drawRect( rectButton );

        qreal margin = 3;
        qreal slider_x = button_width / 2 + button_x;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 2;
        qreal slider_height = button_height;
        QRectF rectSlider( slider_x + margin - step, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin);
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        painter.drawRect( rectSlider );
    }

    if ( isOn == true )
    {
        QPen pen;
        qreal penWidth = 1.0;
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
        painter.drawRect( rectButton );

        qreal margin = 3;
        qreal slider_x = button_width / 2 + button_x;
        qreal slider_y = button_y;
        qreal slider_width = button_width / 2;
        qreal slider_height = button_height;
        QRectF rectSlider( slider_x + margin - step, slider_y + margin, slider_width - 2 * margin, slider_height - 2 * margin);
        QBrush brushSlider( Qt::lightGray );
        painter.setBrush( brushSlider );
        painter.drawRect( rectSlider );
    }
}


void QvkMoveButton::timerEvent( QTimerEvent *event )
{
    if ( event->timerId() == timer.timerId() )
    {
        if ( isOn == false )
        {
            if ( step < button_width / 2 )
            {
                step++;
                update();
            }
            else
            {
                timer.stop();
                step = button_width / 2;
                isOn = true;
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
                emit signal_stateON( isOn );
            }
        }
    } else
    {
        QWidget::timerEvent(event);
    }
}


void QvkMoveButton::slot_clicked()
{
    timer.start( 10, this );
}



#include <QtWidgets>

#include "QvkMoveButton.h"

QvkMoveButton::QvkMoveButton(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole( QPalette::Midlight );
    setAutoFillBackground( true );

    step = 0;
}

void QvkMoveButton::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event );
    QPainter painter( this );

    painter.setRenderHints( QPainter::Antialiasing, true );
    QPen pen;
    qreal penWidth = 1.0;
    pen.setWidthF( penWidth );
    painter.setPen( pen );

    QBrush brushButton( Qt::red );
    painter.setBrush( brushButton );

    qreal button_x = 100;
    qreal button_y = 30;
    qreal button_width = 90;
    qreal button_height = 30;
    QRectF rectButton( button_x, button_y, button_width, button_height );
    if ( step > button_width / 2 - 1 ) {
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


void QvkMoveButton::timerEvent( QTimerEvent *event )
{
    if ( event->timerId() == timer.timerId() )
    {
        if ( step < 90 / 2 )
        {
            step++;
            update();
        }
        else
        {
            timer.stop();
        }
    } else
    {
        QWidget::timerEvent(event);
    }
}


void QvkMoveButton::slot_Start()
{
    step = 0;
    timer.start( 10, this);
}

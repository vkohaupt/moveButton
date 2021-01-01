
#ifndef QVKMOVEBUTTON_H
#define QVKMOVEBUTTON_H

#include <QBasicTimer>
#include <QWidget>

class QvkMoveButton : public QWidget
{
    Q_OBJECT

public:
    QvkMoveButton(QWidget *parent = 0);

public slots:
    void slot_On();
    void slot_Off();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QBasicTimer timer;
    int step;
    qreal button_x;
    qreal button_y;
    qreal button_width;
    qreal button_height;

};
#endif

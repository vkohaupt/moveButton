
#ifndef QVKMOVEBUTTON_H
#define QVKMOVEBUTTON_H

#include <QBasicTimer>
#include <QWidget>


#include <QPushButton>

class QvkMoveButton : public QPushButton
{
    Q_OBJECT

public:
    QvkMoveButton(QWidget *parent = 0);

public slots:
    void slot_clicked();


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
    bool isOn;

signals:
    void signal_stateON( bool );

};
#endif


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
    void slot_Start();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QBasicTimer timer;
    int step;
};
#endif

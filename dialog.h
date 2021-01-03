
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "ui_dialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    Ui_Dialog ui;

private slots:
    void slot_XYZ( bool value );


};

#endif

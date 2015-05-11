#ifndef TALK_H
#define TALK_H

#include <QMainWindow>
#include "dialog.h"
namespace Ui {
class talk;
}

class talk : public QMainWindow
{
    Q_OBJECT

public:
    explicit talk(QWidget *parent = 0);
    ~talk();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();



private:
    Ui::talk *ui;
    Dialog d1;
};

#endif // TALK_H

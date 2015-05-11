#include "talk.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    talk w;
    w.show();

    return a.exec();
}

#include "mywindow.h"
#include <QApplication>
#include <QtGui>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MyWindow w;
    w.setFixedSize(923, 470);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("C:\\sput.jpg"));
    QPalette plt = w.palette();
    plt.setBrush(QPalette::Background, br);
    w.setPalette(plt);
    w.show();
    return a.exec();
}

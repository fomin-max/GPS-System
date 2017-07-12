#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    int j;
    int sec;
    int min;
    ~MyWindow();

private:
    Ui::MyWindow *ui;
    QTimer *timer;

    ;

public slots:
    void startTime();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // MYWINDOW_H

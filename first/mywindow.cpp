#include "mywindow.h"
#include "ui_mywindow.h"
#include <time.h>
#include <cmath>
#include <QTimer>
#include <QTime>

using namespace std;
const int max_sputnik = 5;



void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}







class ModelGPS {
        double value;
public:
        double get_rand(int q);
};


double ModelGPS::get_rand(int q)
{
       srand(time(0)-50*q);
       value=rand()%(100) + 1;
       value=value/9;
       value=round(value*1000)/1000;
       return value;
}



MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    j = 5;
    min = 0;
    sec = 0;
    }

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::startTime()
{
    sec++;
    if(sec == 60)
    {
        sec=0;
        min++;
    }
    if (sec>9)
    {
        ui->label_4->setText(QString("0%1:%2").arg(min).arg(sec));
    }
    else
    {
        ui->label_4->setText(QString("0%1:0%2").arg(min).arg(sec));
    }
    if (min>9)
    {
        ui->label_4->setText(QString("%1:%2").arg(min).arg(sec));
    }


}


void MyWindow::on_pushButton_clicked()  //START
{
    int k = 0;
    if (sec != 0)
    {
        k++;
       // timer->stop();
       // MyWindow::on_pushButton_3_clicked();
    }
    else
    {
        double aver = 0;
        ModelGPS GPSSystem[max_sputnik];
        timer = new QTimer(this);

        connect(timer, SIGNAL(timeout()), this, SLOT(startTime()));
        timer->start(1000);



            while (1){
                delay(5000);
                aver=(GPSSystem[1].get_rand(1)+GPSSystem[2].get_rand(1774)+GPSSystem[3].get_rand(942)+GPSSystem[4].get_rand(3010))/4;
                ui->label_2->setText(QString("%1 %2 %3 %4 %5 %6 %7 %8 %9").arg(j).arg("second:\n1 sputnik:").arg(GPSSystem[1].get_rand(1)).arg("2 sputnik:").arg(GPSSystem[2].get_rand(2)).arg("\n3 sputnik:").arg(GPSSystem[3].get_rand(3)).arg("4 sputnik:").arg(GPSSystem[4].get_rand(4)));
                ui->label_3->setText(QString("%1 %2").arg("The average is:").arg(aver));
                aver = 0;


                j = j + 5;
    }


        }



}

void MyWindow::on_pushButton_2_clicked() //CANCEL
{
    exit(1);
}

void MyWindow::on_pushButton_3_clicked() //RESTART
{
    if (sec == 0)
    {
        goto main;
    }
    else
    {
        j = 5;
        sec = 0;
        min = 0;
        ui->label_2->setText(QString(""));
        ui->label_3->setText(QString(""));
        timer->stop();
    }

    main:
    MyWindow::on_pushButton_clicked();
}





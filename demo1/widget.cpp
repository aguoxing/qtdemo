#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("图片轮播");

    timer = new QTimer;

    imgId = 2;
    QImage img;
    img.load("E:/qtProject/images/1.png");
    ui->imgLabel->setPixmap(QPixmap::fromImage(img));

    connect(timer, &QTimer::timeout, this, &Widget::timeoutSlot);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeoutSlot()
{
    QString path("E:/qtProject/images/");
    path += QString::number(imgId);
    path += ".png";

    QImage img;
    img.load(path);
    ui->imgLabel->setPixmap(QPixmap::fromImage(img));

    imgId++;

    if(3 == imgId)
        imgId = 1;

}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::on_stopButton_clicked()
{
    timer->stop();
}

void Widget::on_singleButton_clicked()
{
    QTimer::singleShot(1000, this, SLOT(timeoutSlot()));
}

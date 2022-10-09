#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_wOne = new PageOne();
    m_wTwo = new PageTwo();
    ui->stackedWidget->addWidget(m_wOne);//将widget加入到stackedWidget
    ui->stackedWidget->addWidget(m_wTwo);//将widget加入到stackedWidget
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pageOneButton_clicked()//按钮1的槽函数
{
    ui->stackedWidget->setCurrentWidget(m_wOne);//点击按钮显示当前的widget
}

void MainWindow::on_pageTwoButton_clicked()//按钮2的槽函数
{
    ui->stackedWidget->setCurrentWidget(m_wTwo);//点击按钮显示当前的widget
}

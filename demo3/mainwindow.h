#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pageone.h>
#include <pagetwo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pageOneButton_clicked();//按钮1的槽函数
    void on_pageTwoButton_clicked();//按钮2的槽函数

private:
    Ui::MainWindow *ui;

    PageOne *m_wOne;//窗体1
    PageTwo *m_wTwo;//窗体2
};
#endif // MAINWINDOW_H

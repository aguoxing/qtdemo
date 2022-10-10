#ifndef SYSTRAYICONWIDGET_H
#define SYSTRAYICONWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

namespace Ui {
class SysTrayIconWidget;
}

class SysTrayIconWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SysTrayIconWidget(QWidget *parent = nullptr);
    ~SysTrayIconWidget();

private:
    Ui::SysTrayIconWidget *ui;

    QSystemTrayIcon *m_sysTrayIcon; //系统托盘
    void initSysTrayIcon();

    QMenu *m_menu;                  //菜单
    QAction *m_showMainAction;      //动作
    QAction *m_exitAppAction;       //动作
    void createActions();
    void createMenu();

private slots:
    void on_showMainAction();
    void on_exitAppAction();

protected:
    void closeEvent (QCloseEvent *event) override;
};

#endif // SYSTRAYICONWIDGET_H

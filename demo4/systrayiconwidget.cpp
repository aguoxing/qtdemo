#include "systrayiconwidget.h"
#include "ui_systrayiconwidget.h"
#include <QMessageBox>

SysTrayIconWidget::SysTrayIconWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SysTrayIconWidget)
{
    ui->setupUi(this);

    initSysTrayIcon();
}

SysTrayIconWidget::~SysTrayIconWidget()
{
    delete ui;
}

//创建系统托盘
void SysTrayIconWidget::initSysTrayIcon()
{
    //隐藏程序主窗口
    this->hide();

    //新建QSystemTrayIcon对象
    m_sysTrayIcon = new QSystemTrayIcon(this);

    //设置托盘图标
    QIcon icon = QIcon(":/logo.png");    //资源文件添加的图标
    m_sysTrayIcon->setIcon(icon);

    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    m_sysTrayIcon->setToolTip("托盘提示信息");

    //给QSystemTrayIcon添加槽函数
    connect(m_sysTrayIcon, &QSystemTrayIcon::activated,
            [=](QSystemTrayIcon::ActivationReason reason)
    {
        switch(reason)
        {
        case QSystemTrayIcon::Trigger:
            //单击托盘图标
            m_sysTrayIcon->showMessage(QObject::trUtf8("Message Title"),
                                              QObject::trUtf8("欢迎使用此程序"),
                                              QSystemTrayIcon::Information,
                                              1000);
            break;
        case QSystemTrayIcon::DoubleClick:
            //双击托盘图标
            //双击后显示主程序窗口
            this->show();
            break;
        default:
            break;
        }
    });

    //建立托盘操作的菜单
    createActions();
    createMenu();
    //在系统托盘显示此对象
    m_sysTrayIcon->show();
}

//创建动作
void SysTrayIconWidget::createActions()
{
    m_showMainAction = new QAction("关于系统", this);
    connect(m_showMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));
    m_exitAppAction = new QAction("退出", this);
    connect(m_exitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
}

//创建托盘菜单
void SysTrayIconWidget::createMenu()
{
    m_menu = new QMenu(this);
    //新增菜单项---显示主界面
    m_menu->addAction(m_showMainAction);
    //增加分隔符
    m_menu->addSeparator();
    //新增菜单项---退出程序
    m_menu->addAction(m_exitAppAction);
    //把QMenu赋给QSystemTrayIcon对象
    m_sysTrayIcon->setContextMenu(m_menu);
}

//当在系统托盘点击菜单内的显示主界面操作
void SysTrayIconWidget::on_showMainAction()
{
    QApplication::setQuitOnLastWindowClosed( false );
    QMessageBox::information(nullptr, "xxxx", "xxxx有限公司copyright©2022");
}

//当在系统托盘点击菜单内的退出程序操作
void SysTrayIconWidget::on_exitAppAction()
{
    qApp->exit();
}

//关闭事件
void SysTrayIconWidget::closeEvent(QCloseEvent *event)
{
    //忽略窗口关闭事件
    QApplication::setQuitOnLastWindowClosed( true );
    this->hide();
    event->ignore();
}


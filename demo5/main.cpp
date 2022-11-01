#include "mainwindow.h"
#include "sqliteoperator.h"
#include <QCoreApplication>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //创建并打开SQLite数据库
    SqliteOperator sqlTest;
    sqlTest.openDb();

    // 创建数据表
    sqlTest.createTable();

    // 判断数据表是否存在
    QString str1 = QString("student");
    qDebug() << "isTabelExist：" <<sqlTest.isTableExist(str1);

    // 插入单条数据
    w2dba w2dbaTest1 = {1, "zhangSan", 24};
    w2dba w2dbaTest2 = {2, "lisi", 28};
    sqlTest.singleInsertData(w2dbaTest1);
    sqlTest.singleInsertData(w2dbaTest2);

    // 插入多条数据
    QList<w2dba> list;
    w2dba w2dbaTest3 = {3, "liwu", 26};
    w2dba w2dbaTest4 = {4, "niuer", 27};
    list.append(w2dbaTest3);
    list.append(w2dbaTest4);
    sqlTest.moreInsertData(list);
    // 查询全部数据
    sqlTest.queryTable();
    qDebug() << endl;

    // 修改数据
    sqlTest.modifyData(2, "modify", 10);
    // 查询全部数据
    sqlTest.queryTable();
    qDebug() << endl;

    // 删除数据
    sqlTest.deleteData(2);
    // 查询全部数据
    sqlTest.queryTable();
    qDebug() << endl;

    // 删除数据表
//    QString str2 = QString("student");
//    sqlTest.deleteTable(str2);

    //关闭数据库
    sqlTest.closeDb();


    MainWindow w;
    w.show();
    return a.exec();
}

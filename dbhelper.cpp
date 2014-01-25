#include "dbhelper.h"
#include <QtDebug>
#include <QCoreApplication>

QSqlDatabase DBHelper::CreateDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        qWarning() << "can not create SQLite database!";
        QCoreApplication::exit(1);
    }

    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(1, 'Marc', 'Dillon')");
    query.exec("insert into person values(2, 'Stefano', 'Mosconi')");
    query.exec("insert into person values(3, 'Iekku ', 'Pylkkä')");
    query.exec("insert into person values(4, 'Carol', 'Chen')");
    query.exec("insert into person values(5, 'Vesku', 'Hartikainen')");
    // and many, many more!

    return db;
}

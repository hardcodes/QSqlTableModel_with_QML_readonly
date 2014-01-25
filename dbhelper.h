#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class DBHelper
{
public:
    DBHelper() = delete;
    static QSqlDatabase CreateDatabase();
};

#endif // DBHELPER_H

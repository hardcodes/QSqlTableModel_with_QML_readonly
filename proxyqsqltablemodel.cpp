/*
 * (c) 2014 by Sven Putze
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 */
 
#include "proxyqsqltablemodel.h"
#include <QDebug>

namespace QmlProxyModels{

ProxyQSqlTableModel::ProxyQSqlTableModel(QObject *parent, QSqlDatabase db) :
    QSqlTableModel(parent, db),
    m_roles(QHash<int, QByteArray>())
{
}

QHash<int, QByteArray> ProxyQSqlTableModel::roleNames() const
{
    return m_roles;
}

QVariant ProxyQSqlTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();
    if (index.row() > QSqlTableModel::rowCount())
            return QVariant();
    // non QML column data
    if(role <= Qt::UserRole)
        return QSqlTableModel::data(index, role);
    // column data identified by role name = column name
    return QSqlTableModel::data(
                this->index(index.row(),
                    role - Qt::UserRole -1),
                Qt::DisplayRole);
}

QHash<int, QByteArray> ProxyQSqlTableModel::extractRoleNames() const
{
    // get the predefined role names
    auto roles = QSqlTableModel::roleNames();
    // add our own roles = column names
    for (int i = 0; i < QSqlTableModel::columnCount(); i++) {
        roles.insert(
                    Qt::UserRole + i + 1,
                    QVariant(this->headerData(i, Qt::Horizontal).toString()).toByteArray()
                    );
    }
    return roles;
}

bool ProxyQSqlTableModel::select()
{
    // this way the roles are only built once
    m_roles = extractRoleNames();
    return QSqlTableModel::select();
}

} // namespace QmlProxyModels


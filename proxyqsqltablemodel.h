#ifndef PROXYQSQLTABLEMODEL_H
#define PROXYQSQLTABLEMODEL_H

#include <QSqlTableModel>
#include <QSqlDatabase>

namespace QmlProxyModels{

class ProxyQSqlTableModel : public QSqlTableModel
{
public:
    ProxyQSqlTableModel() = delete;
    explicit ProxyQSqlTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    virtual ~ProxyQSqlTableModel() {}

    QHash<int, QByteArray> roleNames() const;
    QVariant data ( const QModelIndex & index, int role ) const;
    bool select();

private:
    QHash<int, QByteArray> extractRoleNames() const;
    QHash<int, QByteArray> m_roles;
};

} // namespace QmlProxyModels

#endif // PROXYQSQLTABLEMODEL_H

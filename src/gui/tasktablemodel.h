#pragma once

#include <QAbstractTableModel>

class TaskTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Columns
    {
        Title,
        TimeCreated,
        Count,
    };

    TaskTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QMap<int, QString> m_headerNames;
};

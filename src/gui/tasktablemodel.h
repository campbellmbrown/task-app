#pragma once

#include <QAbstractTableModel>

class TaskTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TaskTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

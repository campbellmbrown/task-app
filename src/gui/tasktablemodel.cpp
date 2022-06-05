#include "tasktablemodel.h"

TaskTableModel::TaskTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TaskTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return 5;
}

int TaskTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return Count;
}

QVariant TaskTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);

    return QVariant();
}

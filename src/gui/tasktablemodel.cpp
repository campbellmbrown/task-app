#include "tasktablemodel.h"
#include <QDebug>
#include <QFont>
#include <QBrush>

TaskTableModel::TaskTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_headerNames.insert(Title, "Title");
    m_headerNames.insert(TimeCreated, "Time created");
    assert(m_headerNames.count() == Count);
}

int TaskTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return 2;
}

int TaskTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return Count;
}

QVariant TaskTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
    }
    return QVariant();
}

QVariant TaskTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole:
                return m_headerNames[section];
            case Qt::TextAlignmentRole:
                return int(Qt::AlignLeft | Qt::AlignVCenter);
            case Qt::FontRole: {
                QFont boldFont;
                boldFont.setBold(true);
                return boldFont;
            }
        }
    }
    return QVariant();
}

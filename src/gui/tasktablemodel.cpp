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
    // generate a log message when this method gets called
    qDebug() << QString("row %1, col%2, role %3")
            .arg(row).arg(col).arg(role);

    switch (role) {
    case Qt::DisplayRole:
        if (row == 0 && col == 1) return QString("<--left");
        if (row == 1 && col == 1) return QString("right-->");

        return QString("Row%1, Column%2")
                .arg(row + 1)
                .arg(col +1);
    case Qt::FontRole:
        if (row == 0 && col == 0) { //change font only for cell(0,0)
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    case Qt::BackgroundRole:
        if (row == 1 && col == 1)  //change background only for cell(1,2)
            return QBrush(Qt::red);
        break;
    case Qt::TextAlignmentRole:
        if (row == 1 && col == 1) //change text alignment only for cell(1,1)
            return int(Qt::AlignRight | Qt::AlignVCenter);
        break;
    case Qt::CheckStateRole:
        if (row == 1 && col == 0) //add a checkbox to cell(1,0)
            return Qt::Checked;
        break;
    }
    return QVariant();
}

QVariant TaskTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return m_headerNames[section];
    }
    return QVariant();
}

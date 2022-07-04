#include "projecttablemodel.h"
#include "models/projectcollection.h"
#include <QFont>

ProjectTableModel::ProjectTableModel(ProjectCollection& projectCollection, QObject *parent)
    : QAbstractTableModel(parent),
      m_projectCollection(projectCollection)
{
    m_headerNames.insert(Name, "Name");
    assert(m_headerNames.count() == Count);
}

int ProjectTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_projectCollection.projects().count();
}

int ProjectTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return Count;
}

QVariant ProjectTableModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
        case Qt::DisplayRole:
            switch (col) {
                case Name:
                    return m_projectCollection.projects().at(row).name;
            }

        case Qt::UserRole:
            switch (col) {
                case Name:
                    return m_projectCollection.projects().at(row).name;
            }
    }
    return QVariant();
}

QVariant ProjectTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole:
                return m_headerNames[section];

            case Qt::TextAlignmentRole:
                return int(Qt::AlignLeft | Qt::AlignVCenter);

            case Qt::FontRole:
            {
                QFont boldFont;
                boldFont.setBold(true);
                return boldFont;
            }
        }
    }
    return QVariant();
}

bool ProjectTableModel::insertRow(int row, const QModelIndex& parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row);
    endInsertRows();
    return true;
}

bool ProjectTableModel::removeRow(int row, const QModelIndex& parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row);
    endRemoveRows();
    return true;
}

void ProjectTableModel::addProject(const Project& project)
{
    m_projectCollection.insert(0, project);
    insertRow(0);
}

void ProjectTableModel::removeProjectAt(int row)
{
    removeRow(row);
    m_projectCollection.removeAt(row);
}

Project& ProjectTableModel::projectAt(int row)
{
    return m_projectCollection.projects()[row];
}

void ProjectTableModel::forceUpdate()
{
    auto topLeft = index(0, 0);
    auto bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
}

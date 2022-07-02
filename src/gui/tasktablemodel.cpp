#include "tasktablemodel.h"
#include "models/projectcollection.h"
#include <QBrush>
#include <QFont>

TaskTableModel::TaskTableModel(QList<Task>& tasks, ProjectCollection& projectCollection, QObject *parent)
    : QAbstractTableModel(parent),
      m_tasks(tasks),
      m_projectCollection(projectCollection)
{
    m_headerNames.insert(Title, "Title");
    m_headerNames.insert(Priority, "Priority");
    m_headerNames.insert(ProjectCol, "Project"),
    m_headerNames.insert(TimeCreated, "Time created");
    assert(m_headerNames.count() == Count);
}

int TaskTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_tasks.count();
}

int TaskTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return Count;
}

QVariant TaskTableModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
        case Qt::DisplayRole:
            switch (col) {
                case Title:
                    return m_tasks.at(row).title;

                case Priority:
                    return PriorityDisplay::text(m_tasks.at(row).priority);

                case ProjectCol:
                    return m_projectCollection.name(m_tasks.at(row).projectId);

                case TimeCreated:
                    return m_tasks.at(row).timeCreated.toString(Task::DATE_FORMAT);
            }

        case Qt::UserRole:
            switch (col) {
                case Title:
                    return m_tasks.at(row).title;

                case Priority:
                    return m_tasks.at(row).priority;

                case ProjectCol:
                    return m_projectCollection.name(m_tasks.at(row).projectId);

                case TimeCreated:
                    return m_tasks.at(row).timeCreated;
            }

        case Qt::DecorationRole:
            switch (col) {
                case Priority:
                    return PriorityDisplay::icon(m_tasks.at(row).priority);
            }
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

bool TaskTableModel::insertRow(int row, const QModelIndex& parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row);
    endInsertRows();
    return true;
}

bool TaskTableModel::removeRow(int row, const QModelIndex& parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row);
    endRemoveRows();
    return true;
}

void TaskTableModel::addTask(const Task& task)
{
    m_tasks.insert(0, task);
    insertRow(0);
}

void TaskTableModel::removeTaskAt(int row)
{
    removeRow(row);
    m_tasks.removeAt(row);
}

Task& TaskTableModel::taskAt(int row) const
{
    return m_tasks[row];
}

void TaskTableModel::forceUpdate()
{
    auto topLeft = index(0, 0);
    auto bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
}

#pragma once

#include "models/task.h"
#include <QAbstractTableModel>

class TaskTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Columns
    {
        Title = 0,
        TimeCreated,
        Count,
    };

    TaskTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRow(int row, const QModelIndex& parent = QModelIndex());

    void addTask(const Task& task);

private:
    QMap<int, QString> m_headerNames;
    QList<Task> m_tasks;
};

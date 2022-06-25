#pragma once

#include "models/task.h"
#include <QAbstractTableModel>

class TaskTableModel : public QAbstractTableModel
{
    Q_OBJECT

    friend class TaskTableModelTest;

public:
    enum Columns
    {
        Title = 0,
        Priority,
        TimeCreated,
        Count,
    };

    explicit TaskTableModel(QList<Task>& tasks, QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRow(int row, const QModelIndex& parent = QModelIndex());
    bool removeRow(int row, const QModelIndex& parent = QModelIndex());

    void addTask(const Task& task);
    void removeTaskAt(int row);
    Task& taskAt(int row);
    void forceUpdate();

private:
    QMap<int, QString> m_headerNames;
    QList<Task>& m_tasks;
};

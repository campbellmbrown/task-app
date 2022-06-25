#pragma once

#include "models/project.h"
#include <QAbstractTableModel>

class ProjectTableModel : public QAbstractTableModel
{
    Q_OBJECT

    friend class ProjectTableModelTest;

public:
    enum Columns
    {
        Name,
        Count,
    };

    ProjectTableModel(QList<Project>& projects, QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRow(int row, const QModelIndex& parent = QModelIndex());
    bool removeRow(int row, const QModelIndex& parent = QModelIndex());

    void addProject(const Project& task);
    void removeProjectAt(int row);
    Project& projectAt(int row);
    void forceUpdate();

private:
    QMap<int, QString> m_headerNames;
    QList<Project>& m_projects;
};

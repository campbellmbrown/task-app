#pragma once

#include "ui_tasksection.h"
#include <QWidget>

struct Task;
class ProjectCollection;
class TaskTableModel;
class QSortFilterProxyModel;
class TaskSection : public QWidget
{
    Q_OBJECT

    friend class TaskSectionTest;

public:
    TaskSection(QList<Task>& tasks, ProjectCollection& projectCollection, QWidget *parent = nullptr);

    void forceTableUpdate();

signals:
    void taskSelected(Task& selected);
    void nothingSelected();

private:
    void initTableView();
    void initButtons();

private slots:
    void onNewBtnClicked();
    void onDeleteBtnClicked();
    void onSelectedTaskChanged(const QModelIndex& current, const QModelIndex& previous);

private:
    Ui::TaskSection m_ui;
    TaskTableModel *m_taskTableModel;
    QSortFilterProxyModel *m_proxyModel;
    ProjectCollection& m_projectCollection;
};

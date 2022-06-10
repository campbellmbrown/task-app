#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class Task;
class TaskTableModel;
class QSortFilterProxyModel;
class TaskListView : public QWidget
{
    Q_OBJECT

    friend class TaskListViewTest;

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initTableSections();
    void initButtons();

private slots:
    void onNewBtnClicked();
    void onDeleteBtnClicked();
    void onSelectedTaskChanged(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::TaskListView m_ui;
    TaskTableModel *m_taskTableModel;
    QSortFilterProxyModel *m_proxyModel;
};

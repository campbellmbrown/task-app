#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class Task;
class TaskTableModel;
class QSortFilterProxyModel;
class TaskListView : public QWidget
{
    Q_OBJECT

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initTableSections();
    void initButtons();

private slots:
    void onNewBtnClicked();

private:
    Ui::TaskListView m_ui;
    TaskTableModel *m_taskTableModel;
    QSortFilterProxyModel *m_proxyModel;
};

#pragma once

#include "ui_tasklistview.h"
#include <QStandardItemModel>
#include <QWidget>

class Task;
class TaskTableModel;
class TaskListView : public QWidget
{
    Q_OBJECT

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initTableSections();
    void initButtons();
    // TODO
    // void addNewTask(Task &task);

private slots:
    void onNewBtnClicked();

private:
    Ui::TaskListView m_ui;
    TaskTableModel *m_taskTableModel;
};

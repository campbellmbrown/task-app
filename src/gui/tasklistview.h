#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class Task;
class TaskListHeader;
class TaskListView : public QWidget
{
    Q_OBJECT

    static auto constexpr COL_HEADER_TITLE = "Title";

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initTreeSections();
    void initButtons();
    void addNewTask(Task &task);

private slots:
    void onNewBtnClicked();

private:
    Ui::TaskListView m_ui;
    TaskListHeader *m_taskListHeader;
};

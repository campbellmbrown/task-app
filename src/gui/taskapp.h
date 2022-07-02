#pragma once

#include "models/task.h"
#include "models/projectcollection.h"
#include "ui_taskapp.h"
#include <QtWidgets/QMainWindow>

class TaskSection;
class TaskDetailSection;
class ProjectSection;
class ProjectDetailSection;
class TaskApp : public QMainWindow
{
    Q_OBJECT

public:
    TaskApp(QWidget *parent = Q_NULLPTR);

private:
    void initTasksTab();
    void initProjectsTab();

private:
    Ui::TaskApp m_ui;

    // Tasks tab
    TaskSection *m_taskSection;
    TaskDetailSection *m_taskDetailSection;
    QList<Task> m_tasks;
    // Projects tab
    ProjectSection *m_projectSection;
    ProjectDetailSection *m_projectDetailSection;
    ProjectCollection m_projectCollection;
};

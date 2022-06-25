#pragma once

#include "models/task.h"
#include "models/project.h"
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
    TaskSection *taskSection;
    TaskDetailSection *taskDetailSection;
    QList<Task> m_tasks;
    // Projects tab
    ProjectSection *projectSection;
    ProjectDetailSection *projectDetailSection;
    QList<Project> m_projects;
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_taskapp.h"

class TaskSection;
class TaskDetailSection;
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

    TaskSection *taskSection;
    TaskDetailSection *taskDetailSection;
};

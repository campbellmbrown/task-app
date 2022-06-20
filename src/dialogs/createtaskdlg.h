#pragma once

#include "ui_createtaskdlg.h"
#include <QDialog>

struct Task;
class ProjectsCollection;
class CreateTaskDlg : public QDialog
{
    Q_OBJECT
    using SuperClass = QDialog;

    friend class CreateTaskDlgTest;

public:
    CreateTaskDlg(Task& task, ProjectsCollection& projectsCollection, QWidget *parent = nullptr);
    void accept() override;

private:
    bool checkFields();

private:
    Ui::CreateTaskDlg m_ui;
    Task& m_task;
};

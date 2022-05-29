#pragma once

#include "ui_createtaskdlg.h"
#include <QDialog>

class ProjectsCollection;
class CreateTaskDlg : public QDialog
{
    Q_OBJECT

    friend class CreateTaskDialogTest;

public:
    CreateTaskDlg(ProjectsCollection& projectsCollection, QWidget *parent = nullptr);

private:
    Ui::CreateTaskDlg m_ui;
};

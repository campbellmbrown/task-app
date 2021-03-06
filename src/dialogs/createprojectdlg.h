#pragma once

#include "ui_createprojectdlg.h"
#include <QDialog>

struct Project;
class ProjectCollection;
class CreateProjectDlg : public QDialog
{
    Q_OBJECT
    using SuperClass = QDialog;

    friend class CreateProjectDlgTest;

public:
    CreateProjectDlg(Project& project, ProjectCollection& projectCollection, QWidget *parent = nullptr);
    void accept() override;

private:
    bool checkFields();

private:
    Ui::CreateProjectDlg m_ui;
    Project& m_project;
    ProjectCollection& m_projectCollection;
};

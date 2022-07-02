#pragma once

#include "ui_createtaskdlg.h"
#include <QDialog>

struct Task;
class ProjectCollection;

/**
 * @brief Dialog for creating tasks.
 *
 * Inputs:
 * - Collection of projects
 * - input selection from the user
 *
 * Outputs:
 * - Task based on user input selection
 */
class CreateTaskDlg : public QDialog
{
    Q_OBJECT
    using SuperClass = QDialog;

    friend class CreateTaskDlgTest;

public:
    CreateTaskDlg(Task& task, ProjectCollection& projectCollection, QWidget *parent = nullptr);
    void accept() override;

private:
    void fillInComboBoxes();
    bool checkFields();

private:
    Ui::CreateTaskDlg m_ui;
    Task& m_task;
    ProjectCollection& m_projectCollection;
};

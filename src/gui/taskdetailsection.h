#pragma once

#include "models/task.h"
#include "ui_taskdetailsection.h"
#include <QWidget>

class ProjectCollection;
class TaskDetailSection : public QWidget
{
    Q_OBJECT

    friend class TaskDetailSectionTest;

public:
    TaskDetailSection(ProjectCollection& projects, QWidget *parent = nullptr);

public slots:
    void onTaskSelected(Task& selected);
    void onNothingSelected();
    void refresh();

signals:
    void taskUpdated();

private:
    void reset();
    bool checkFields();

private slots:
    void onApply();

private:
    Ui::TaskDetailSection m_ui;
    Task *m_selectedTask = nullptr;
    ProjectCollection& m_projectCollection;
};

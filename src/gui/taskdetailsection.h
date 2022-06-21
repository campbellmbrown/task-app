#pragma once

#include "models/task.h"
#include "ui_taskdetailsection.h"
#include <QWidget>

class TaskDetailSection : public QWidget
{
    Q_OBJECT

    friend class TaskDetailSectionTest;

public:
    TaskDetailSection(QWidget *parent = nullptr);

public slots:
    void onTaskSelected(Task& selected);
    void onNothingSelected();

signals:
    void taskUpdated();

private:
    void reset();

private slots:
    void onApply();

private:
    Ui::TaskDetailSection m_ui;
    Task *m_selectedTask = nullptr;
};

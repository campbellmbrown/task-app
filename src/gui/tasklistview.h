#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class TaskListView : public QWidget
{
    Q_OBJECT

public:
    TaskListView(QWidget *parent = nullptr);

private:
    Ui::TaskListView m_ui;
};
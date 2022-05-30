#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class TaskListView : public QWidget
{
    Q_OBJECT

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initButtons();

private slots:
    void onNewBtnClicked();

private:
    Ui::TaskListView m_ui;
};

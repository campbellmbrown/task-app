#pragma once

#include "ui_tasklistview.h"
#include <QWidget>

class TaskListView : public QWidget
{
    Q_OBJECT

    // TODO: Consider the correct location for these.
    static auto constexpr COL_HEADER_COMPLETED = "";
    static auto constexpr COL_HEADER_TITLE = "Title";
    static auto constexpr COL_HEADER_PRIORITY = "Priority";

public:
    TaskListView(QWidget *parent = nullptr);

private:
    void initTreeSections();
    void initButtons();

private slots:
    void onNewBtnClicked();

private:
    Ui::TaskListView m_ui;
};

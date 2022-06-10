#pragma once

#include "ui_tasksection.h"
#include <QWidget>

struct Task;
class TaskTableModel;
class QSortFilterProxyModel;
class TaskSection : public QWidget
{
    Q_OBJECT

    friend class TaskSectionTest;

public:
    TaskSection(QWidget *parent = nullptr);

private:
    void initTableSections();
    void initButtons();

private slots:
    void onNewBtnClicked();
    void onDeleteBtnClicked();
    void onSelectedTaskChanged(const QModelIndex& current, const QModelIndex& previous);

private:
    Ui::TaskSection m_ui;
    TaskTableModel *m_taskTableModel;
    QSortFilterProxyModel *m_proxyModel;
};

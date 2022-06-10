#include "gui/tasklistview.h"
#include "gui/tasktablemodel.h"
#include <QtTest/QtTest>

class TaskListViewTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_deleteButton_disabledByDefault();
    void check_deleteButton_enabledWhenRowSelected();
    void check_deleteButton_disabledWhenNoRowSelected();

private:
    std::unique_ptr<TaskListView> m_taskListView;
};

void TaskListViewTest::init()
{
    m_taskListView.reset(new TaskListView());
}

void TaskListViewTest::check_deleteButton_disabledByDefault()
{
    QCOMPARE(m_taskListView->m_ui.deleteBtn->isEnabled(), false);
}

void TaskListViewTest::check_deleteButton_enabledWhenRowSelected()
{
    // Given:
    QCOMPARE(m_taskListView->m_ui.deleteBtn->isEnabled(), false);

    // When:
    const int DONT_CARE = 1;
    // Add a task so we can get the index of it and simulate the
    // user selecting that task
    Task task;
    m_taskListView->m_taskTableModel->addTask(task);
    auto current = m_taskListView->m_taskTableModel->index(0, DONT_CARE);
    m_taskListView->onSelectedTaskChanged(current, QModelIndex());

    // Then:
    QCOMPARE(m_taskListView->m_ui.deleteBtn->isEnabled(), true);
}

void TaskListViewTest::check_deleteButton_disabledWhenNoRowSelected()
{
    // Given:
    check_deleteButton_enabledWhenRowSelected();
    const int DONT_CARE = 1;
    // Select a really high index so it doesn't return a valid QModelIndex
    auto current = m_taskListView->m_taskTableModel->index(9999, DONT_CARE);

    m_taskListView->onSelectedTaskChanged(current, QModelIndex());

    // When:
    QCOMPARE(m_taskListView->m_ui.deleteBtn->isEnabled(), false);
}

QTEST_MAIN(TaskListViewTest)
#include "tasklistviewtest.moc"

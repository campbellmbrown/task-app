#include "gui/tasklistview.h"

#include <QtTest/QtTest>

class TaskListViewTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_deleteButtonDisabledByDefault();

private:
    std::unique_ptr<TaskListView> m_taskListView;
};

void TaskListViewTest::init()
{
    m_taskListView.reset(new TaskListView());
}

void TaskListViewTest::check_deleteButtonDisabledByDefault()
{
    QCOMPARE(m_taskListView->m_ui.deleteBtn->isEnabled(), false);
}

QTEST_MAIN(TaskListViewTest)
#include "tasklistviewtest.moc"

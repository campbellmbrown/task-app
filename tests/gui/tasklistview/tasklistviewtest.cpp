#include "gui/tasklistview.h"

#include <QtTest/QtTest>

class TaskListViewTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_something();
};

void TaskListViewTest::init()
{
}

void TaskListViewTest::check_something()
{
    QVERIFY(true);
}

QTEST_MAIN(TaskListViewTest)
#include "tasklistviewtest.moc"

#include "gui/taskapp.h"

#include <QtTest/QtTest>

class TaskAppTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_something();
};

void TaskAppTest::init()
{
}

void TaskAppTest::check_something()
{
    QVERIFY(true);
}

QTEST_MAIN(TaskAppTest)
#include "taskapptest.moc"

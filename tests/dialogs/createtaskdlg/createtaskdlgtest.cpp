#include "dialogs/createtaskdlg.h"
#include <memory>
#include <QtTest/QtTest>

class CreateTaskDlgTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_something();

private:
    std::unique_ptr<CreateTaskDlg> m_createTaskDlg;
};

void CreateTaskDlgTest::init()
{
    m_createTaskDlg.reset(new CreateTaskDlg());
}

void CreateTaskDlgTest::check_something()
{
    QVERIFY(true);
}

QTEST_MAIN(CreateTaskDlgTest)
#include "createtaskdlgtest.moc"

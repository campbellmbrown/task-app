#include "gui/tasksection.h"
#include "gui/tasktablemodel.h"
#include <QtTest/QtTest>

class TaskSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_deleteButton_disabledByDefault();
    void check_deleteButton_enabledWhenRowSelected();

private:
    std::unique_ptr<TaskSection> m_taskSection;
};

void TaskSectionTest::init()
{
    m_taskSection.reset(new TaskSection());
}

void TaskSectionTest::check_deleteButton_disabledByDefault()
{
    QCOMPARE(m_taskSection->m_ui.deleteBtn->isEnabled(), false);
}

void TaskSectionTest::check_deleteButton_enabledWhenRowSelected()
{
    // Given:
    QCOMPARE(m_taskSection->m_ui.deleteBtn->isEnabled(), false);
    Task task;
    m_taskSection->m_taskTableModel->addTask(task);

    // When:
    m_taskSection->m_ui.taskTableView->selectRow(0);

    // Then:
    QCOMPARE(m_taskSection->m_ui.deleteBtn->isEnabled(), true);
}

QTEST_MAIN(TaskSectionTest)
#include "tasksectiontest.moc"

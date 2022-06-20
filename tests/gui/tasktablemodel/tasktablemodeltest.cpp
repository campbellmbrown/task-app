#include "gui/tasktablemodel.h"
#include <QDateTime>
#include <QFont>
#include <QtTest/QtTest>

class TaskTableModelTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_onStartup();
    void check_headerData_data();
    void check_headerData();
    void check_addTask();
    void check_removeTask_beginning();
    void check_removeTask_middle();
    void check_removeTask_end();
    void check_removeTask_all();

private:
    void addCustomTask(QString title, Priority priority, QDateTime timeCreated);

private:
    std::unique_ptr<TaskTableModel> m_taskTableModel;
};

void TaskTableModelTest::init()
{
    m_taskTableModel.reset(new TaskTableModel());
}

void TaskTableModelTest::check_onStartup()
{
    // Given: fresh table
    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 0);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 0);
    QCOMPARE(m_taskTableModel->columnCount(), TaskTableModel::Count);
}

void TaskTableModelTest::check_headerData_data()
{
    QTest::addColumn<int>("column");
    QTest::addColumn<QString>("expectedHeader");
    auto titleIdx = (int)TaskTableModel::Title;
    auto priorityIdx = (int)TaskTableModel::Priority;
    auto timeCreatedIdx = (int)TaskTableModel::TimeCreated;
    QTest::addRow("title") << titleIdx << m_taskTableModel->m_headerNames[titleIdx];
    QTest::addRow("priority") << priorityIdx << m_taskTableModel->m_headerNames[priorityIdx];
    QTest::addRow("time created") << timeCreatedIdx << m_taskTableModel->m_headerNames[timeCreatedIdx];
}

void TaskTableModelTest::check_headerData()
{
    // Given:
    QFETCH(int, column);
    QFETCH(QString, expectedHeader);

    // When:
    auto header = m_taskTableModel->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
    auto font = m_taskTableModel->headerData(column, Qt::Horizontal, Qt::FontRole).value<QFont>();
    auto textAlignment = m_taskTableModel->headerData(column, Qt::Horizontal, Qt::TextAlignmentRole).toInt();

    // Then:
    QCOMPARE(header, expectedHeader);
    QCOMPARE(font.bold(), true);
    QCOMPARE(textAlignment, int(Qt::AlignLeft | Qt::AlignVCenter));
}

void TaskTableModelTest::addCustomTask(QString title, Priority priority, QDateTime timeCreated)
{
    Task task;
    task.title = title;
    task.priority = priority;
    task.timeCreated = timeCreated;
    m_taskTableModel->addTask(task);
}

void TaskTableModelTest::check_addTask()
{
    // Given:
    QCOMPARE(m_taskTableModel->rowCount(), 0);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 0);

    // When:
    addCustomTask("taskTitle", Priority::High, QDateTime::fromSecsSinceEpoch(10921, Qt::UTC, 0));

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 1);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 1);

    auto firstRowTitle = m_taskTableModel->index(0, TaskTableModel::Title);
    auto firstRowPriority = m_taskTableModel->index(0, TaskTableModel::Priority);
    auto firstRowTimeCreated = m_taskTableModel->index(0, TaskTableModel::TimeCreated);
    QCOMPARE(m_taskTableModel->data(firstRowTitle, Qt::DisplayRole).toString(), "taskTitle");
    QCOMPARE(m_taskTableModel->data(firstRowTitle, Qt::UserRole).toString(), "taskTitle");
    QCOMPARE(m_taskTableModel->data(firstRowPriority, Qt::DisplayRole).toString(), PriorityDisplay::text(Priority::High));
    QCOMPARE(m_taskTableModel->data(firstRowPriority, Qt::UserRole).toInt(), Priority::High);
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::DisplayRole).toString(), "01/01/70 03:02:01 am");
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::UserRole).toDateTime().date(), QDate(1970, 1, 1));
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::UserRole).toDateTime().time(), QTime(3, 2, 1));
}

void TaskTableModelTest::check_removeTask_beginning()
{
    // Given:
    addCustomTask("task1", Priority::Low, QDateTime());
    addCustomTask("task2", Priority::Low, QDateTime());
    addCustomTask("task3", Priority::Low, QDateTime());

    // When:
    m_taskTableModel->removeTaskAt(0);

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 2);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 2);
    auto firstRowTitle = m_taskTableModel->index(0, TaskTableModel::Title);
    auto secondRowTitle = m_taskTableModel->index(1, TaskTableModel::Title);
    QCOMPARE(m_taskTableModel->data(firstRowTitle).toString(), "task2");
    QCOMPARE(m_taskTableModel->data(secondRowTitle).toString(), "task1");
}

void TaskTableModelTest::check_removeTask_middle()
{
    // Given:
    addCustomTask("task1", Priority::Low, QDateTime());
    addCustomTask("task2", Priority::Low, QDateTime());
    addCustomTask("task3", Priority::Low, QDateTime());

    // When:
    m_taskTableModel->removeTaskAt(1);

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 2);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 2);
    auto firstRowTitle = m_taskTableModel->index(0, TaskTableModel::Title);
    auto secondRowTitle = m_taskTableModel->index(1, TaskTableModel::Title);
    QCOMPARE(m_taskTableModel->data(firstRowTitle).toString(), "task3");
    QCOMPARE(m_taskTableModel->data(secondRowTitle).toString(), "task1");
}

void TaskTableModelTest::check_removeTask_end()
{
    // Given:
    addCustomTask("task1", Priority::Low, QDateTime());
    addCustomTask("task2", Priority::Low, QDateTime());
    addCustomTask("task3", Priority::Low, QDateTime());

    // When:
    m_taskTableModel->removeTaskAt(2);

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 2);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 2);
    auto firstRowTitle = m_taskTableModel->index(0, TaskTableModel::Title);
    auto secondRowTitle = m_taskTableModel->index(1, TaskTableModel::Title);
    QCOMPARE(m_taskTableModel->data(firstRowTitle).toString(), "task3");
    QCOMPARE(m_taskTableModel->data(secondRowTitle).toString(), "task2");
}

void TaskTableModelTest::check_removeTask_all()
{
    // Given:
    addCustomTask("task1", Priority::Low, QDateTime());
    addCustomTask("task2", Priority::Low, QDateTime());
    addCustomTask("task3", Priority::Low, QDateTime());

    // When:
    m_taskTableModel->removeTaskAt(0);
    m_taskTableModel->removeTaskAt(0);
    m_taskTableModel->removeTaskAt(0);

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 0);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 0);
}

QTEST_MAIN(TaskTableModelTest);
#include "tasktablemodeltest.moc"

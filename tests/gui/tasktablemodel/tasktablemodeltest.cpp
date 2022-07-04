#include "gui/tasktablemodel.h"
#include "models/projectcollection.h"
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
    void addCustomTask(QString title, Priority priority, QUuid projectId, QDateTime timeCreated);

private:
    QList<Task> m_tasks;
    std::shared_ptr<ProjectCollection> m_projectCollection;
    std::unique_ptr<TaskTableModel> m_taskTableModel;
};

void TaskTableModelTest::init()
{
    m_tasks.clear();
    m_projectCollection.reset(new ProjectCollection());
    m_taskTableModel.reset(new TaskTableModel(m_tasks, *m_projectCollection));
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
    auto projectIdx = (int)TaskTableModel::ProjectCol;
    auto timeCreatedIdx = (int)TaskTableModel::TimeCreated;
    QTest::addRow("title") << titleIdx << m_taskTableModel->m_headerNames[titleIdx];
    QTest::addRow("priority") << priorityIdx << m_taskTableModel->m_headerNames[priorityIdx];
    QTest::addRow("projectCol") << projectIdx << m_taskTableModel->m_headerNames[projectIdx];
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

void TaskTableModelTest::addCustomTask(QString title, Priority priority, QUuid projectId, QDateTime timeCreated)
{
    Task task;
    task.title = title;
    task.projectId = projectId;
    task.priority = priority;
    task.timeCreated = timeCreated;
    m_taskTableModel->addTask(task);
}

void TaskTableModelTest::check_addTask()
{
    // Given:
    QCOMPARE(m_taskTableModel->rowCount(), 0);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 0);
    Project proj;
    proj.name = "projectA";
    proj.uuid = QUuid("00000000-0000-0000-0000-000123456789");
    m_projectCollection->insert(0, proj);

    // When:
    addCustomTask(
        "taskTitle", Priority::High, proj.uuid, QDateTime::fromSecsSinceEpoch(10921, Qt::UTC, 0));

    // Then:
    QCOMPARE(m_taskTableModel->rowCount(), 1);
    QCOMPARE(m_taskTableModel->m_tasks.count(), 1);

    auto firstRowTitle = m_taskTableModel->index(0, TaskTableModel::Title);
    auto firstRowPriority = m_taskTableModel->index(0, TaskTableModel::Priority);
    auto firstRowProject = m_taskTableModel->index(0, TaskTableModel::ProjectCol);
    auto firstRowTimeCreated = m_taskTableModel->index(0, TaskTableModel::TimeCreated);
    QCOMPARE(m_taskTableModel->data(firstRowTitle, Qt::DisplayRole).toString(), "taskTitle");
    QCOMPARE(m_taskTableModel->data(firstRowTitle, Qt::UserRole).toString(), "taskTitle");
    QCOMPARE(m_taskTableModel->data(firstRowPriority, Qt::DisplayRole).toString(),
             PriorityDisplay::text(Priority::High));
    QCOMPARE(m_taskTableModel->data(firstRowPriority, Qt::UserRole).toInt(), Priority::High);
    QCOMPARE(m_taskTableModel->data(firstRowProject, Qt::UserRole).toString(), "projectA");
    QCOMPARE(m_taskTableModel->data(firstRowProject, Qt::DisplayRole).toString(), "projectA");
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::DisplayRole).toString(), "01/01/70 03:02:01 am");
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::UserRole).toDateTime().date(), QDate(1970, 1, 1));
    QCOMPARE(m_taskTableModel->data(firstRowTimeCreated, Qt::UserRole).toDateTime().time(), QTime(3, 2, 1));
}

void TaskTableModelTest::check_removeTask_beginning()
{
    // Given:
    addCustomTask("task1", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task2", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task3", Priority::Low, QUuid(), QDateTime());

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
    addCustomTask("task1", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task2", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task3", Priority::Low, QUuid(), QDateTime());

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
    addCustomTask("task1", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task2", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task3", Priority::Low, QUuid(), QDateTime());

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
    addCustomTask("task1", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task2", Priority::Low, QUuid(), QDateTime());
    addCustomTask("task3", Priority::Low, QUuid(), QDateTime());

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

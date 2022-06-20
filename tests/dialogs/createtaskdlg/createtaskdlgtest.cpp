#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include <memory>
#include <QRegularExpression>
#include <QtTest/QtTest>

class CreateTaskDlgTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_comboBoxes_arePopulated();
    void check_savesOnAccept();
    void check_preventEmptyTitle();
    void check_preventEmptyPriority();
    void check_doesntSaveTaskOnReject();

private:
    Task m_task;
    std::unique_ptr<CreateTaskDlg> m_createTaskDlg;
};

void CreateTaskDlgTest::init()
{
    m_task = Task();
    ProjectsCollection projectCollection;
    projectCollection.addProject("project foo");
    projectCollection.addProject("project bar");
    m_createTaskDlg.reset(new CreateTaskDlg(m_task, projectCollection));
}

void CreateTaskDlgTest::check_comboBoxes_arePopulated()
{
    QCOMPARE(m_createTaskDlg->m_ui.projectComboBox->count(), 2);
    QCOMPARE(m_createTaskDlg->m_ui.priorityComboBox->count(), Priority::Count);
}

void CreateTaskDlgTest::check_savesOnAccept()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("someTitle");
    m_createTaskDlg->m_ui.notesPlainTextEdit->setPlainText("some\nNotes");
    m_createTaskDlg->m_ui.priorityComboBox->setCurrentIndex(Priority::High);

    // When:
    m_createTaskDlg->accept();

    // Then:
    QCOMPARE(m_task.title, "someTitle");
    QCOMPARE(m_task.notes, "some\nNotes");
    auto regex = QRegularExpression("[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}");
    QCOMPARE(regex.match(m_task.uuid.toString(QUuid::WithoutBraces)).hasMatch(), true);
    QCOMPARE(m_task.priority, Priority::High);
}

void CreateTaskDlgTest::check_preventEmptyTitle()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("");

    // When:
    m_createTaskDlg->accept();

    // Then:
    QCOMPARE(m_task.title, "");
    QCOMPARE(m_task.notes, "");
    QCOMPARE(m_task.uuid.toString(QUuid::WithoutBraces), "00000000-0000-0000-0000-000000000000");
    QCOMPARE(m_task.timeCreated, QDateTime());
    QCOMPARE(m_task.priority, Priority::Medium);
}

void CreateTaskDlgTest::check_preventEmptyPriority()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("something");
    m_createTaskDlg->m_ui.priorityComboBox->setCurrentIndex(-1);

    // When:
    m_createTaskDlg->accept();

    // Then:
    QCOMPARE(m_task.title, "");
    QCOMPARE(m_task.notes, "");
    QCOMPARE(m_task.uuid.toString(QUuid::WithoutBraces), "00000000-0000-0000-0000-000000000000");
    QCOMPARE(m_task.timeCreated, QDateTime());
    QCOMPARE(m_task.priority, Priority::Medium);
}

void CreateTaskDlgTest::check_doesntSaveTaskOnReject()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("someTitle");
    m_createTaskDlg->m_ui.notesPlainTextEdit->setPlainText("some\nNotes");

    // When:
    m_createTaskDlg->reject();

    // Then:
    QCOMPARE(m_task.title, "");
    QCOMPARE(m_task.notes, "");
    QCOMPARE(m_task.uuid.toString(QUuid::WithoutBraces), "00000000-0000-0000-0000-000000000000");
    QCOMPARE(m_task.timeCreated, QDateTime());
    QCOMPARE(m_task.priority, Priority::Medium);
}

QTEST_MAIN(CreateTaskDlgTest)
#include "createtaskdlgtest.moc"

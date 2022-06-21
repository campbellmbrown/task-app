#include "gui/taskdetailsection.h"

#include <QtTest/QtTest>

class TaskDetailSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_initResets();
    void check_onSelected();
    void check_onNothingSelected();
    void check_onApply();

private:
    std::unique_ptr<TaskDetailSection> m_detailSection;
};

void TaskDetailSectionTest::init()
{
    m_detailSection.reset(new TaskDetailSection());
}

void TaskDetailSectionTest::check_initResets()
{
    // General
    QCOMPARE(m_detailSection->m_ui.titleLineEdit->text(), "");
    QCOMPARE(m_detailSection->m_ui.priorityComboBox->currentText(), "");
    QCOMPARE(m_detailSection->m_ui.notesPlainTextEdit->toPlainText(), "");
    // Metadata
    QCOMPARE(m_detailSection->m_ui.timeCreatedDisplayLabel->text(), "-");
    QCOMPARE(m_detailSection->m_ui.uuidDisplayLabel->text(), "00000000-0000-0000-0000-000000000000");

    QCOMPARE(m_detailSection->isEnabled(), false);
}

void TaskDetailSectionTest::check_onSelected()
{
    // Given:
    Task task;
    task.title = "some title";
    task.notes = "some notes";
    task.priority = Priority::High;
    task.timeCreated = QDateTime::fromSecsSinceEpoch(10921, Qt::UTC, 0);
    task.uuid = QUuid("01234567-8901-2345-6789-012345678901");

    // When:
    m_detailSection->onTaskSelected(task);

    // Then:
    // General
    QCOMPARE(m_detailSection->m_ui.titleLineEdit->text(), "some title");
    QCOMPARE(m_detailSection->m_ui.priorityComboBox->currentIndex(), Priority::High);
    QCOMPARE(m_detailSection->m_ui.notesPlainTextEdit->toPlainText(), "some notes");
    // Metadata
    QCOMPARE(m_detailSection->m_ui.timeCreatedDisplayLabel->text(), "01/01/70 03:02:01 am");
    QCOMPARE(m_detailSection->m_ui.uuidDisplayLabel->text(), "01234567-8901-2345-6789-012345678901");

    QCOMPARE(m_detailSection->isEnabled(), true);
}

void TaskDetailSectionTest::check_onNothingSelected()
{
    check_initResets();
}

void TaskDetailSectionTest::check_onApply()
{
    // Given:
    Task task;
    m_detailSection->onTaskSelected(task);
    m_detailSection->m_ui.titleLineEdit->setText("some title");
    m_detailSection->m_ui.priorityComboBox->setCurrentIndex(Priority::High);
    m_detailSection->m_ui.notesPlainTextEdit->setPlainText("some notes");

    // When:
    m_detailSection->onApply();

    // Then:
    QCOMPARE(task.title, "some title");
    QCOMPARE(task.priority, Priority::High);
    QCOMPARE(task.notes, "some notes");
}

QTEST_MAIN(TaskDetailSectionTest)
#include "taskdetailsectiontest.moc"

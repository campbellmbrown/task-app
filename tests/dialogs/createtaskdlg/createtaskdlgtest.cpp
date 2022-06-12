#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include <memory>
#include <QtTest/QtTest>

class CreateTaskDlgTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_projectsComboBox_isPopulated();
    void check_savesOnAccept();
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

void CreateTaskDlgTest::check_projectsComboBox_isPopulated()
{
    QCOMPARE(m_createTaskDlg->m_ui.projectComboBox->count(), 2);
}

#include <QRegularExpression>

void CreateTaskDlgTest::check_savesOnAccept()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("someTitle");

    // When:
    m_createTaskDlg->accept();

    // Then:
    QCOMPARE(m_task.title, "someTitle");
    auto regex = QRegularExpression("[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}");
    QCOMPARE(regex.match(m_task.uuid.toString(QUuid::WithoutBraces)).hasMatch(), true);
}

void CreateTaskDlgTest::check_doesntSaveTaskOnReject()
{
    // Given:
    m_createTaskDlg->m_ui.titleLineEdit->setText("someTitle");

    // When:
    m_createTaskDlg->reject();

    // Then:
    QCOMPARE(m_task.title, "");
    QCOMPARE(m_task.uuid.toString(QUuid::WithoutBraces), "00000000-0000-0000-0000-000000000000");
}

QTEST_MAIN(CreateTaskDlgTest)
#include "createtaskdlgtest.moc"

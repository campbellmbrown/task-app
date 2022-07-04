#include "dialogs/createprojectdlg.h"
#include "models/project.h"
#include "models/projectcollection.h"
#include <QtTest/QtTest>

class CreateProjectDlgTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_savesOnAccept();
    void check_preventEmptyName();
    void check_preventDuplicateNames();

private:
    Project m_project;
    std::shared_ptr<ProjectCollection> m_projectCollection;
    std::unique_ptr<CreateProjectDlg> m_createProjectDlg;
};

void CreateProjectDlgTest::init()
{
    m_project = Project();
    m_projectCollection.reset(new ProjectCollection());
    m_createProjectDlg.reset(new CreateProjectDlg(m_project, *m_projectCollection));
}

void CreateProjectDlgTest::check_savesOnAccept()
{
    // Given:
    m_createProjectDlg->m_ui.nameLineEdit->setText("someName");
    m_createProjectDlg->m_ui.notesPlainTextEdit->setPlainText("some\nNotes");

    // When:
    m_createProjectDlg->accept();

    // Then:
    QCOMPARE(m_project.name, "someName");
    QCOMPARE(m_project.notes, "some\nNotes");
}

void CreateProjectDlgTest::check_preventEmptyName()
{
    // Given:
    m_createProjectDlg->m_ui.nameLineEdit->setText("");

    // When:
    m_createProjectDlg->accept();

    // Then:
    QCOMPARE(m_project.name, "");
    QCOMPARE(m_project.notes, "");
}

void CreateProjectDlgTest::check_preventDuplicateNames()
{
    // Given:
    Project existingProject;
    existingProject.name = "alreadyExisting";
    m_projectCollection->insert(0, existingProject);
    m_createProjectDlg->m_ui.nameLineEdit->setText("alreadyExisting");

    // When:
    m_createProjectDlg->accept();

    // Then:
    QCOMPARE(m_project.name, "");
    QCOMPARE(m_project.notes, "");
}

QTEST_MAIN(CreateProjectDlgTest)
#include "createprojectdlgtest.moc"

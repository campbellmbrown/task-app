#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include <memory>
#include <QtTest/QtTest>

class CreateTaskDlgTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_projectsComboBox_isPopulated();

private:
    std::unique_ptr<CreateTaskDlg> m_createTaskDlg;
};

void CreateTaskDlgTest::init()
{
    ProjectsCollection projectCollection;
    projectCollection.addProject("project foo");
    projectCollection.addProject("project bar");
    m_createTaskDlg.reset(new CreateTaskDlg(projectCollection));
}

void CreateTaskDlgTest::check_projectsComboBox_isPopulated()
{
    QVERIFY(m_createTaskDlg->m_ui.projectComboBox->count(), 2);
}

QTEST_MAIN(CreateTaskDlgTest)
#include "createtaskdlgtest.moc"

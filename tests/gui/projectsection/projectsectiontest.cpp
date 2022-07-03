#include "gui/projectsection.h"
#include "gui/projecttablemodel.h"
#include "models/projectcollection.h"
#include <QtTest/QtTest>

class ProjectSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_deleteButton_disabledByDefault();
    void check_deleteButton_enabledWhenRowSelected();

private:
    std::shared_ptr<ProjectCollection> m_projectCollection;
    std::unique_ptr<ProjectSection> m_projectSection;
};

void ProjectSectionTest::init()
{
    m_projectCollection.reset(new ProjectCollection());
    m_projectSection.reset(new ProjectSection(*m_projectCollection));
}

void ProjectSectionTest::check_deleteButton_disabledByDefault()
{
    QCOMPARE(m_projectSection->m_ui.deleteBtn->isEnabled(), false);
}

void ProjectSectionTest::check_deleteButton_enabledWhenRowSelected()
{
    // Given:
    QCOMPARE(m_projectSection->m_ui.deleteBtn->isEnabled(), false);
    Project project;
    m_projectSection->m_projectTableModel->addProject(project);

    // When:
    m_projectSection->m_ui.projectTableView->selectRow(0);

    // Then:
    QCOMPARE(m_projectSection->m_ui.deleteBtn->isEnabled(), true);
}

QTEST_MAIN(ProjectSectionTest)
#include "projectsectiontest.moc"

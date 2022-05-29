#include "models/projectscollection.h"

#include <QtTest/QtTest>
#include <memory>

class ProjectsCollectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_addProject();

private:
    std::unique_ptr<ProjectsCollection> m_projectsCollection;
};

void ProjectsCollectionTest::init()
{
    m_projectsCollection->reset(new ProjectsCollection());
}

void ProjectsCollectionTest::check_addProject()
{
    // Given:
    // When:
    m_projectsCollection->addProject("Project A");
    m_projectsCollection->addProject("Project B");

    // Then:
    QCOMPARE(m_projectsCollection->projects().at(0), "Project A");
    QCOMPARE(m_projectsCollection->projects().at(1), "Project B");
}

QTEST_MAIN(ProjectsCollectionTest)
#include "projectscollectiontest.moc"

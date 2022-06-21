#include "gui/projectsection.h"
#include <QtTest/QtTest>

class ProjectSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();

private:
    std::unique_ptr<ProjectSection> m_projectSection;
};

void ProjectSectionTest::init()
{
    m_projectSection.reset(new ProjectSection());
}

QTEST_MAIN(ProjectSectionTest)
#include "projectsectiontest.moc"

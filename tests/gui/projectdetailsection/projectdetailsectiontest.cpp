#include "gui/projectdetailsection.h"

#include <QtTest/QtTest>

class ProjectDetailSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();

private:
    std::unique_ptr<ProjectDetailSection> m_detailSection;
};

void ProjectDetailSectionTest::init()
{
    m_detailSection.reset(new ProjectDetailSection());
}

QTEST_MAIN(ProjectDetailSectionTest)
#include "projectdetailsectiontest.moc"

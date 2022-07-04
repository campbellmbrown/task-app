#include "gui/projecttablemodel.h"
#include "models/projectcollection.h"
#include <QtTest/QtTest>

class ProjectTableModelTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_onStartup();
    void check_headerData_data();
    void check_headerData();
    void check_addProject();
    void check_removeProject_beginning();
    void check_removeProject_middle();
    void check_removeProject_end();
    void check_removeProject_all();

private:
    void addCustomProject(QString name);

private:
    std::shared_ptr<ProjectCollection> m_projectCollection;
    std::unique_ptr<ProjectTableModel> m_projectTableModel;
};

void ProjectTableModelTest::init()
{
    m_projectCollection.reset(new ProjectCollection());
    m_projectTableModel.reset(new ProjectTableModel(*m_projectCollection));
}

void ProjectTableModelTest::check_onStartup()
{
    // Given: fresh table
    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 0);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 0);
    QCOMPARE(m_projectTableModel->columnCount(), ProjectTableModel::Count);
}

void ProjectTableModelTest::check_headerData_data()
{
    QTest::addColumn<int>("column");
    QTest::addColumn<QString>("expectedHeader");
    auto nameIdx = (int)ProjectTableModel::Name;
    QTest::addRow("name") << nameIdx << m_projectTableModel->m_headerNames[nameIdx];
}

void ProjectTableModelTest::check_headerData()
{
    // Given:
    QFETCH(int, column);
    QFETCH(QString, expectedHeader);

    // When:
    auto header = m_projectTableModel->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
    auto font = m_projectTableModel->headerData(column, Qt::Horizontal, Qt::FontRole).value<QFont>();
    auto textAlignment = m_projectTableModel->headerData(column, Qt::Horizontal, Qt::TextAlignmentRole).toInt();

    // Then:
    QCOMPARE(header, expectedHeader);
    QCOMPARE(font.bold(), true);
    QCOMPARE(textAlignment, int(Qt::AlignLeft | Qt::AlignVCenter));
}

void ProjectTableModelTest::addCustomProject(QString name)
{
    Project project;
    project.name = name;
    project.uuid = QUuid::createUuid();
    m_projectTableModel->addProject(project);
}

void ProjectTableModelTest::check_addProject()
{
    // Given:
    QCOMPARE(m_projectTableModel->rowCount(), 0);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 0);

    // When:
    addCustomProject("projectName");

    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 1);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 1);

    auto firstRowName = m_projectTableModel->index(0, ProjectTableModel::Name);
    QCOMPARE(m_projectTableModel->data(firstRowName, Qt::DisplayRole).toString(), "projectName");
    QCOMPARE(m_projectTableModel->data(firstRowName, Qt::UserRole).toString(), "projectName");
}

void ProjectTableModelTest::check_removeProject_beginning()
{
    // Given:
    addCustomProject("project1");
    addCustomProject("project2");
    addCustomProject("project3");

    // When:
    m_projectTableModel->removeProjectAt(0);

    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 2);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 2);
    auto firstRowName = m_projectTableModel->index(0, ProjectTableModel::Name);
    auto secondRowName = m_projectTableModel->index(1, ProjectTableModel::Name);
    QCOMPARE(m_projectTableModel->data(firstRowName).toString(), "project2");
    QCOMPARE(m_projectTableModel->data(secondRowName).toString(), "project1");
}

void ProjectTableModelTest::check_removeProject_middle()
{
    // Given:
    addCustomProject("project1");
    addCustomProject("project2");
    addCustomProject("project3");

    // When:
    m_projectTableModel->removeProjectAt(1);

    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 2);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 2);
    auto firstRowName = m_projectTableModel->index(0, ProjectTableModel::Name);
    auto secondRowName = m_projectTableModel->index(1, ProjectTableModel::Name);
    QCOMPARE(m_projectTableModel->data(firstRowName).toString(), "project3");
    QCOMPARE(m_projectTableModel->data(secondRowName).toString(), "project1");
}

void ProjectTableModelTest::check_removeProject_end()
{
    // Given:
    addCustomProject("project1");
    addCustomProject("project2");
    addCustomProject("project3");

    // When:
    m_projectTableModel->removeProjectAt(2);

    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 2);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 2);
    auto firstRowName = m_projectTableModel->index(0, ProjectTableModel::Name);
    auto secondRowName = m_projectTableModel->index(1, ProjectTableModel::Name);
    QCOMPARE(m_projectTableModel->data(firstRowName).toString(), "project3");
    QCOMPARE(m_projectTableModel->data(secondRowName).toString(), "project2");
}

void ProjectTableModelTest::check_removeProject_all()
{
    // Given:
    addCustomProject("project1");
    addCustomProject("project2");
    addCustomProject("project3");

    // When:
    m_projectTableModel->removeProjectAt(0);
    m_projectTableModel->removeProjectAt(0);
    m_projectTableModel->removeProjectAt(0);

    // Then:
    QCOMPARE(m_projectTableModel->rowCount(), 0);
    QCOMPARE(m_projectTableModel->m_projectCollection.projects().count(), 0);
}

QTEST_MAIN(ProjectTableModelTest);
#include "projecttablemodeltest.moc"

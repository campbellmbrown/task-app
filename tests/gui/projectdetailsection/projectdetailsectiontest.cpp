#include "gui/projectdetailsection.h"
#include "models/projectcollection.h"
#include <QtTest/QtTest>

class ProjectDetailSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_init();
    void check_onProjectSelected();
    void check_onNothingSelected();
    void check_preventEmptyName();
    void check_preventDuplicateProject();
    void check_onApply();

private:
    std::shared_ptr<ProjectCollection> m_projectCollection;
    std::unique_ptr<ProjectDetailSection> m_detailSection;
};

void ProjectDetailSectionTest::init()
{
    m_projectCollection.reset(new ProjectCollection());
    m_detailSection.reset(new ProjectDetailSection(*m_projectCollection));
}

void ProjectDetailSectionTest::check_init()
{
    // Given:
    m_detailSection->m_ui.nameLineEdit->setText("foo");
    m_detailSection->m_ui.notesPlainTextEdit->setPlainText("bar");
    m_detailSection->m_ui.uuidDisplayLabel->setText("qux");

    // When:
    m_detailSection->reset();

    // Then:
    QCOMPARE(m_detailSection->m_ui.nameLineEdit->text(), "");
    QCOMPARE(m_detailSection->m_ui.notesPlainTextEdit->toPlainText(), "");
    QCOMPARE(m_detailSection->m_ui.uuidDisplayLabel->text(), "00000000-0000-0000-0000-000000000000");
    QCOMPARE(m_detailSection->isEnabled(), false);
}

void ProjectDetailSectionTest::check_onProjectSelected()
{
    // Given:
    Project project;
    project.name = "foo";
    project.notes = "some\nNotes";
    project.uuid = QUuid("11111111-2222-3333-4444-555555555555");

    // When:
    m_detailSection->onProjectSelected(project);

    // Then:
    QCOMPARE(m_detailSection->m_ui.nameLineEdit->text(), "foo");
    QCOMPARE(m_detailSection->m_ui.notesPlainTextEdit->toPlainText(), "some\nNotes");
    QCOMPARE(m_detailSection->m_ui.uuidDisplayLabel->text(), "11111111-2222-3333-4444-555555555555");
    QCOMPARE(m_detailSection->isEnabled(), true);
}

void ProjectDetailSectionTest::check_onNothingSelected()
{
    // Given:
    m_detailSection->m_ui.nameLineEdit->setText("foo");
    m_detailSection->m_ui.notesPlainTextEdit->setPlainText("bar");
    m_detailSection->m_ui.uuidDisplayLabel->setText("qux");

    // When:
    m_detailSection->onNothingSelected();

    // Then:
    QCOMPARE(m_detailSection->m_ui.nameLineEdit->text(), "");
    QCOMPARE(m_detailSection->m_ui.notesPlainTextEdit->toPlainText(), "");
    QCOMPARE(m_detailSection->m_ui.uuidDisplayLabel->text(), "00000000-0000-0000-0000-000000000000");
    QCOMPARE(m_detailSection->isEnabled(), false);
}

void ProjectDetailSectionTest::check_preventEmptyName()
{
    // Given:
    Project selectedProject;
    selectedProject.name = "foo";
    m_detailSection->onProjectSelected(selectedProject);
    m_detailSection->m_ui.nameLineEdit->setText("");
    connect(m_detailSection.get(), &ProjectDetailSection::projectUpdated, this, []() {
        // Then:
        QVERIFY(false);
    });

    // When:
    m_detailSection->onApply();

    // Then:
    QCOMPARE(m_detailSection->m_selectedProject->name, "foo");
}

void ProjectDetailSectionTest::check_preventDuplicateProject()
{
    // Given:
    Project selectedProject;
    selectedProject.name = "foo";
    m_detailSection->onProjectSelected(selectedProject);
    Project anotherProject;
    anotherProject.name = "bar";
    m_projectCollection->insert(0, anotherProject);
    m_detailSection->m_ui.nameLineEdit->setText("bar");

    // When:
    m_detailSection->onApply();

    // Then:
    QCOMPARE(m_detailSection->m_selectedProject->name, "foo");
}

void ProjectDetailSectionTest::check_onApply()
{
    // Given:
    Project selectedProject;
    selectedProject.name = "foo";
    m_detailSection->onProjectSelected(selectedProject);

    // When:
    m_detailSection->onApply();

    // Then:
    QCOMPARE(m_detailSection->m_selectedProject->name, "foo");
}

QTEST_MAIN(ProjectDetailSectionTest)
#include "projectdetailsectiontest.moc"

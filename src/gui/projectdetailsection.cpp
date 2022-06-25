#include "projectdetailsection.h"
#include <QDebug>
#include <QPushButton>

ProjectDetailSection::ProjectDetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    connect(m_ui.generalButtonBox->button(QDialogButtonBox::Apply),
            &QPushButton::clicked,
            this,
            &ProjectDetailSection::onApply);

    reset();
}

void ProjectDetailSection::reset()
{
    // General
    m_ui.nameLineEdit->setText("");
    m_ui.notesPlainTextEdit->setPlainText("");

    // Metadata
    m_ui.uuidDisplayLabel->setText(QUuid().toString(QUuid::WithoutBraces));

    setDisabled(true);
}

void ProjectDetailSection::onProjectSelected(Project& selected)
{
    m_selectedProject = &selected;

    // General
    m_ui.nameLineEdit->setText(m_selectedProject->name);
    m_ui.notesPlainTextEdit->setPlainText(m_selectedProject->notes);

    // Metadata
    m_ui.uuidDisplayLabel->setText(m_selectedProject->uuid.toString(QUuid::WithoutBraces));

    setEnabled(true);
}

void ProjectDetailSection::onNothingSelected()
{
    m_selectedProject = nullptr;
    reset();
}

void ProjectDetailSection::onApply()
{
    qInfo() << "Updating project" << m_selectedProject->uuid.toString(QUuid::WithoutBraces);

    // General
    m_selectedProject->name = m_ui.nameLineEdit->text();
    m_selectedProject->notes = m_ui.notesPlainTextEdit->toPlainText();

    emit projectUpdated();
}

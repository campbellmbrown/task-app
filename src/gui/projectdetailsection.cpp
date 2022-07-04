#include "projectdetailsection.h"
#include "models/projectcollection.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

ProjectDetailSection::ProjectDetailSection(ProjectCollection& projectCollection, QWidget *parent)
    : QWidget(parent),
      m_projectCollection(projectCollection)
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

bool ProjectDetailSection::checkFields()
{
    QString message;
    bool valid = false;
    if (m_ui.nameLineEdit->text() == "") {
        message = "Name cannot be empty.";
    }
    else if (m_projectCollection.contains(m_ui.nameLineEdit->text())) {
        message = "Project already exists.";
    }
    else {
        valid = true;
    }

    if (!valid) {
#ifndef IGNORE_DIALOG
        QMessageBox::warning(this, "Invalid project", message, QMessageBox::Ok);
#endif
    }

    return valid;
}

void ProjectDetailSection::onApply()
{
    if (!checkFields()) {
        return;
    }

    qInfo() << "Updating project" << m_selectedProject->uuid.toString(QUuid::WithoutBraces);

    // General
    m_selectedProject->name = m_ui.nameLineEdit->text();
    m_selectedProject->notes = m_ui.notesPlainTextEdit->toPlainText();

    emit projectUpdated();
}

#include "taskdetailsection.h"
#include "models/projectcollection.h"
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

TaskDetailSection::TaskDetailSection(ProjectCollection& projectCollection, QWidget *parent)
    : QWidget(parent),
      m_projectCollection(projectCollection)
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    connect(m_ui.generalButtonBox->button(QDialogButtonBox::Apply),
            &QPushButton::clicked,
            this,
            &TaskDetailSection::onApply);

    for (int idx = 0; idx < (int)Priority::Count; idx++) {
        auto priority = static_cast<Priority>(idx);
        m_ui.priorityComboBox->addItem(PriorityDisplay::icon(priority), PriorityDisplay::text(priority));
    }

    reset();
}

void TaskDetailSection::reset()
{
    // General
    m_ui.titleLineEdit->setText("");
    m_ui.notesPlainTextEdit->setPlainText("");
    m_ui.priorityComboBox->setCurrentIndex(-1);

    // Metadata
    m_ui.timeCreatedDisplayLabel->setText("-");
    m_ui.uuidDisplayLabel->setText(QUuid().toString(QUuid::WithoutBraces));

    setDisabled(true);

    qDebug() << "Task detail section reset.";
}

void TaskDetailSection::refresh()
{
    if (!isEnabled()) {
        return;
    }

    m_ui.projectComboBox->clear();
    for (auto proj : m_projectCollection.projects()) {
        m_ui.projectComboBox->addItem(proj.name);
    }
    m_ui.projectComboBox->setDisabled(m_projectCollection.projects().empty());

    // General
    m_ui.titleLineEdit->setText(m_selectedTask->title);
    m_ui.priorityComboBox->setCurrentIndex(m_selectedTask->priority);
    if (m_projectCollection.contains(m_selectedTask->projectId)) {
        m_ui.projectComboBox->setCurrentText(m_projectCollection.name(m_selectedTask->projectId));
    }
    else { // Either when no project is selected, or the project was removed
        m_ui.projectComboBox->setCurrentIndex(-1);
    }
    m_ui.notesPlainTextEdit->setPlainText(m_selectedTask->notes);

    // Metadata
    m_ui.timeCreatedDisplayLabel->setText(m_selectedTask->timeCreated.toString(Task::DATE_FORMAT));
    m_ui.uuidDisplayLabel->setText(m_selectedTask->uuid.toString(QUuid::WithoutBraces));

    qDebug() << "Task detail section refreshed.";
}

void TaskDetailSection::onTaskSelected(Task& selected)
{
    m_selectedTask = &selected;
    setEnabled(true);
    refresh();
}

void TaskDetailSection::onNothingSelected()
{
    m_selectedTask = nullptr;
    reset();
}

bool TaskDetailSection::checkFields()
{
    QString message;
    bool valid = false;
    if (m_ui.titleLineEdit->text() == "") {
        message = "Title cannot be empty.";
    }
    else {
        valid = true;
    }

    if (!valid) {
#ifndef IGNORE_DIALOG
        QMessageBox::warning(this, "Invalid task", message, QMessageBox::Ok);
#endif
    }

    return valid;
}

void TaskDetailSection::onApply()
{
    if (!checkFields()) {
        return;
    }

    qInfo() << "Updating task" << m_selectedTask->uuid.toString(QUuid::WithoutBraces);

    // General
    m_selectedTask->title = m_ui.titleLineEdit->text();
    m_selectedTask->priority = static_cast<Priority>(m_ui.priorityComboBox->currentIndex());
    auto projectIndex = m_ui.projectComboBox->currentIndex();
    if (projectIndex >= 0) {
        // The order of the projects shouldn't have changed, so we can
        // just get the project at the same index.
        auto project = m_projectCollection.projects().at(projectIndex);
        m_selectedTask->projectId = project.uuid;
    }
    m_selectedTask->notes = m_ui.notesPlainTextEdit->toPlainText();

    emit taskUpdated();
}

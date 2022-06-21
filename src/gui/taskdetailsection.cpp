#include "taskdetailsection.h"
#include <QDebug>
#include <QPushButton>

TaskDetailSection::TaskDetailSection(QWidget *parent)
    : QWidget(parent)
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
}

void TaskDetailSection::onTaskSelected(Task& selected)
{
    m_selectedTask = &selected;

    // General
    m_ui.titleLineEdit->setText(m_selectedTask->title);
    m_ui.priorityComboBox->setCurrentIndex(m_selectedTask->priority);
    m_ui.notesPlainTextEdit->setPlainText(m_selectedTask->notes);

    // Metadata
    m_ui.timeCreatedDisplayLabel->setText(m_selectedTask->timeCreated.toString(Task::DATE_FORMAT));
    m_ui.uuidDisplayLabel->setText(m_selectedTask->uuid.toString(QUuid::WithoutBraces));

    setEnabled(true);
}

void TaskDetailSection::onNothingSelected()
{
    m_selectedTask = nullptr;
    reset();
}

void TaskDetailSection::onApply()
{
    qInfo() << "Updating task" << m_selectedTask->uuid.toString(QUuid::WithoutBraces);

    // General
    m_selectedTask->title = m_ui.titleLineEdit->text();
    m_selectedTask->priority = static_cast<Priority>(m_ui.priorityComboBox->currentIndex());
    m_selectedTask->notes = m_ui.notesPlainTextEdit->toPlainText();

    emit taskUpdated();
}

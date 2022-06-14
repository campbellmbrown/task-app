#include "detailsection.h"
#include "models/task.h"

DetailSection::DetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
    reset();
}

void DetailSection::reset()
{
    // General
    m_ui.titleLineEdit->setText("");

    // Metadata
    m_ui.dataCreatedDisplayLabel->setText("-");
    m_ui.uuidDisplayLabel->setText(QUuid().toString(QUuid::WithoutBraces));
}

void DetailSection::onTaskSelected(std::shared_ptr<Task> selected)
{
    m_selectedTask = selected;

    // General
    m_ui.titleLineEdit->setText(m_selectedTask->title);

    // Metadata
    m_ui.dataCreatedDisplayLabel->setText(m_selectedTask->timeCreated.toString(Task::DATE_FORMAT));
    m_ui.uuidDisplayLabel->setText(m_selectedTask->uuid.toString(QUuid::WithoutBraces));
}

void DetailSection::onNothingSelected()
{
    m_selectedTask = nullptr;
    reset();
}

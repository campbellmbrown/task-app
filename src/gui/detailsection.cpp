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
    m_ui.titleLineEdit->setText("");
}

void DetailSection::onTaskSelected(std::shared_ptr<Task> selected)
{
    m_selectedTask = selected;
    m_ui.titleLineEdit->setText(m_selectedTask->title);
}

void DetailSection::onNothingSelected()
{
    m_selectedTask = nullptr;
    reset();
}

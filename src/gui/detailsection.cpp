#include "detailsection.h"
#include "models/task.h"

DetailSection::DetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
}

void DetailSection::onTaskSelected(Task& selected)
{
    m_ui.titleLineEdit->setText(selected.title);
}

void DetailSection::onNothingSelected()
{
    m_ui.titleLineEdit->setText("");
}

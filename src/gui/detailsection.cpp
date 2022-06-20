#include "detailsection.h"
#include <QDebug>
#include <QPushButton>

DetailSection::DetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    connect(m_ui.generalButtonBox->button(QDialogButtonBox::Apply), &QPushButton::clicked, this,
            &DetailSection::onApply);

    reset();
}

void DetailSection::reset()
{
    // General
    m_ui.titleLineEdit->setText("");
    m_ui.notesPlainTextEdit->setPlainText("");

    // Metadata
    m_ui.timeCreatedDisplayLabel->setText("-");
    m_ui.uuidDisplayLabel->setText(QUuid().toString(QUuid::WithoutBraces));

    setDisabled(true);
}

void DetailSection::onTaskSelected(Task& selected)
{
    m_selectedTask = &selected;

    // General
    m_ui.titleLineEdit->setText(m_selectedTask->title);
    m_ui.notesPlainTextEdit->setPlainText(m_selectedTask->notes);

    // Metadata
    m_ui.timeCreatedDisplayLabel->setText(m_selectedTask->timeCreated.toString(Task::DATE_FORMAT));
    m_ui.uuidDisplayLabel->setText(m_selectedTask->uuid.toString(QUuid::WithoutBraces));

    setEnabled(true);
}

void DetailSection::onNothingSelected()
{
    m_selectedTask = nullptr;
    reset();
}

void DetailSection::onApply()
{
    qInfo() << "Updating task" << m_selectedTask->uuid.toString(QUuid::WithoutBraces);

    // General
    m_selectedTask->title = m_ui.titleLineEdit->text();
    m_selectedTask->notes = m_ui.notesPlainTextEdit->toPlainText();

    emit taskUpdated();
}

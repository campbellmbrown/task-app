#include "createtaskdlg.h"
#include "models/project.h"
#include "models/task.h"
#include <QDateTime>
#include <QDialogButtonBox>
#include <QMessageBox>

CreateTaskDlg::CreateTaskDlg(Task& task, QList<Project>& projects, QWidget *parent)
    : QDialog(parent),
      m_task(task),
      m_projects(projects)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    for (int idx = 0; idx < m_projects.count(); idx++) {
        m_ui.projectComboBox->addItem(m_projects.at(idx).name);
    }

    for (int idx = 0; idx < (int)Priority::Count; idx++) {
        auto priority = static_cast<Priority>(idx);
        m_ui.priorityComboBox->addItem(PriorityDisplay::icon(priority), PriorityDisplay::text(priority));
    }
    m_ui.priorityComboBox->setCurrentIndex(-1);
}

bool CreateTaskDlg::checkFields()
{
    QString message;
    bool valid = false;
    if (m_ui.titleLineEdit->text() == "") {
        message = "Title cannot be empty.";
    }
    else if (m_ui.priorityComboBox->currentIndex() == -1) {
        message = "Priority must be selected.";
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

#include <QDebug>
void CreateTaskDlg::accept()
{
    if (!checkFields()) {
        return;
    }
    // General
    m_task.title = m_ui.titleLineEdit->text();
    auto projectIndex = m_ui.projectComboBox->currentIndex();
    qDebug() << projectIndex;
    if (projectIndex >= 0) {
        m_task.projectId = m_projects.at(projectIndex).uuid;
        qDebug() << "Selected" << projectIndex << m_task.projectId;
    }
    m_task.priority = static_cast<Priority>(m_ui.priorityComboBox->currentIndex());
    m_task.notes = m_ui.notesPlainTextEdit->toPlainText();
    // Metadata
    m_task.timeCreated = QDateTime::currentDateTime();
    m_task.uuid = QUuid::createUuid();
    SuperClass::accept();
}

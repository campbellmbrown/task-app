#include "createtaskdlg.h"
#include "models/projectcollection.h"
#include "models/task.h"
#include <QDateTime>
#include <QDialogButtonBox>
#include <QMessageBox>

CreateTaskDlg::CreateTaskDlg(Task& task, ProjectCollection& projectCollection, QWidget *parent)
    : QDialog(parent),
      m_task(task),
      m_projectCollection(projectCollection)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    fillInComboBoxes();
}

/**
 * @brief Populates the GUI combo boxes.
 */
void CreateTaskDlg::fillInComboBoxes()
{
    for (auto proj : m_projectCollection.projects()) {
        m_ui.projectComboBox->addItem(proj.name);
    }
    // Default selected none.
    m_ui.projectComboBox->setCurrentIndex(-1);
    m_ui.projectComboBox->setDisabled(m_projectCollection.projects().empty());

    for (int idx = 0; idx < (int)Priority::Count; idx++) {
        auto priority = static_cast<Priority>(idx);
        m_ui.priorityComboBox->addItem(PriorityDisplay::icon(priority), PriorityDisplay::text(priority));
    }
    // Default selected none.
    m_ui.priorityComboBox->setCurrentIndex(-1);
}

/**
 * @brief Some of the fields cannot be empty. This function checks the
 * GUI inputs and validates if the required fields are filled.
 *
 * @return true if the required fields are filled, false otherwise.
 */
bool CreateTaskDlg::checkFields()
{
    QString message;
    bool valid = false;
    if (m_ui.titleLineEdit->text() == "") {
        message = "Title cannot be empty.";
    }
    else if (m_ui.priorityComboBox->currentIndex() < 0) {
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

/**
 * @brief Override for the dialog accept method.
 * This function will pull the values from the GUI inputs and form
 * a task from them.
 */
void CreateTaskDlg::accept()
{
    if (!checkFields()) {
        return;
    }
    // General
    m_task.title = m_ui.titleLineEdit->text();
    auto projectIndex = m_ui.projectComboBox->currentIndex();
    if (projectIndex >= 0) {
        // The order of the projects shouldn't have changed, so we can
        // just get the project at the same index.
        auto project = m_projectCollection.projects().at(projectIndex);
        m_task.projectId = project.uuid;
    }
    m_task.priority = static_cast<Priority>(m_ui.priorityComboBox->currentIndex());
    m_task.notes = m_ui.notesPlainTextEdit->toPlainText();
    // Metadata
    m_task.timeCreated = QDateTime::currentDateTime();
    m_task.uuid = QUuid::createUuid();
    SuperClass::accept();
}

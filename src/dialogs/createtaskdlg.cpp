#include "createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include <QDateTime>
#include <QDialogButtonBox>
#include <QMessageBox>

CreateTaskDlg::CreateTaskDlg(Task& task, ProjectsCollection& projectsCollection, QWidget *parent)
    : QDialog(parent),
      m_task(task)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    for (int idx = 0; idx < projectsCollection.projects().count(); idx++) {
        m_ui.projectComboBox->addItem(projectsCollection.projects().at(idx));
    }

    for (int idx = 0; idx < (int)Priority::Count; idx++) {
        m_ui.priorityComboBox->addItem(PriorityDisplay::text(static_cast<Priority>(idx)));
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

void CreateTaskDlg::accept()
{
    if (!checkFields()) {
        return;
    }
    m_task.title = m_ui.titleLineEdit->text();
    m_task.notes = m_ui.notesPlainTextEdit->toPlainText();
    m_task.timeCreated = QDateTime::currentDateTime();
    m_task.uuid = QUuid::createUuid();
    m_task.priority = static_cast<Priority>(m_ui.priorityComboBox->currentIndex());
    SuperClass::accept();
}

#include "createprojectdlg.h"
#include "models/project.h"
#include "models/projectcollection.h"
#include <QDialogButtonBox>
#include <QMessageBox>

CreateProjectDlg::CreateProjectDlg(Project& project, ProjectCollection& projectCollection, QWidget *parent)
    : QDialog(parent),
      m_project(project),
      m_projectCollection(projectCollection)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

bool CreateProjectDlg::checkFields()
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

void CreateProjectDlg::accept()
{
    if (!checkFields()) {
        return;
    }
    m_project.name = m_ui.nameLineEdit->text();
    m_project.notes = m_ui.notesPlainTextEdit->toPlainText();
    m_project.uuid = QUuid::createUuid();
    SuperClass::accept();
}

#include "createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include <QDateTime>
#include <QDialogButtonBox>

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
        m_ui.priorityComboBox->addItem(QString("%1").arg(idx));
    }
}

void CreateTaskDlg::accept()
{
    m_task.title = m_ui.titleLineEdit->text();
    m_task.notes = m_ui.notesPlainTextEdit->toPlainText();
    m_task.timeCreated = QDateTime::currentDateTime();
    m_task.uuid = QUuid::createUuid();
    SuperClass::accept();
}

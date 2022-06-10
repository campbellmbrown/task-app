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
}

void CreateTaskDlg::accept()
{
    m_task.title = m_ui.titleLineEdit->text();
    m_task.timeCreated = QDateTime::currentDateTime();
    SuperClass::accept();
}

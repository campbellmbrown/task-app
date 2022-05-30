#include "createtaskdlg.h"
#include "models/projectscollection.h"
#include <QDialogButtonBox>

CreateTaskDlg::CreateTaskDlg(ProjectsCollection& projectsCollection, QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    for (int idx = 0; idx < projectsCollection.projects().count(); idx++) {
        m_ui.projectComboBox->addItem(projectsCollection.projects().at(idx));
    }
}

#include "createtaskdlg.h"
#include "models/projectscollection.h"

CreateTaskDlg::CreateTaskDlg(ProjectsCollection& projectsCollection, QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    for (int idx = 0; idx < projectsCollection.projects().count(); idx++) {
        m_ui.projectComboBox->addItem(projectsCollection.projects().at(idx));
    }
}

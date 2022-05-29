#include "tasklistview.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include <QAbstractButton>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initButtons();
}

void TaskListView::initButtons()
{
    connect(m_ui.newBtn, &QAbstractButton::clicked, this, &TaskListView::onNewBtnClicked);
}

void TaskListView::onNewBtnClicked()
{
    // Temporary - TODO: remove
    ProjectsCollection projectsCollection;
    projectsCollection.addProject("Hi!");
    projectsCollection.addProject("Hello!");
    projectsCollection.addProject("Howdy!");

    CreateTaskDlg createTaskDlg(projectsCollection, this);
    createTaskDlg.exec();
}

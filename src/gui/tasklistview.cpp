#include "tasklistview.h"
#include "taskitem.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include <QAbstractButton>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initTreeSections();
    initButtons();
}

void TaskListView::initTreeSections()
{
    auto tree = m_ui.taskListTree;
    tree->setColumnCount(TaskItem::Count);
    tree->setHeaderLabels({ COL_HEADER_TITLE, COL_HEADER_PRIORITY });
    auto header = tree->header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(TaskItem::Title, QHeaderView::Stretch);
    header->setSectionResizeMode(TaskItem::Priority, QHeaderView::ResizeToContents);
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

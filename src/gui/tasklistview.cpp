#include "tasklistview.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include "tasktablemodel.h"
#include <QAbstractButton>
#include <QCheckBox>
#include <QComboBox>
#include <QHeaderView>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent),
      m_taskTableModel(new TaskTableModel())
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    initTableSections();
    initButtons();
}

void TaskListView::initTableSections()
{
    auto table = m_ui.taskListTable;
    table->setModel(m_taskTableModel);
    table->horizontalHeader()->setStretchLastSection(false);
    table->horizontalHeader()->setSectionResizeMode(TaskTableModel::Title, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(TaskTableModel::TimeCreated, QHeaderView::ResizeToContents);
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

    Task task;
    CreateTaskDlg createTaskDlg(task, projectsCollection, this);
    if (createTaskDlg.exec() == QDialog::Accepted) {
        // TODO
    }
}

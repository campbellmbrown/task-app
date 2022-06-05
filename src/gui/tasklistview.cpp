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
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initTableSections();
    initButtons();

    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
}

void TaskListView::initTableSections()
{
    auto table = m_ui.taskListTable;
    TaskTableModel taskTableModel;
    table->setModel(&taskTableModel);
    // table->setColumnCount(TaskTableModel::Count);
    // table->setHorizontalHeaderLabels({ COL_HEADER_TITLE });

    // auto header = table->horizontalHeader();
    // header->setSectionResizeMode(TaskTableModel::Title, QHeaderView::Stretch);
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

#include "tasklistview.h"
#include "tasklistitem.h"
#include "tasklistheader.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include <QAbstractButton>
#include <QCheckBox>
#include <QComboBox>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initTreeSections();
    initButtons();

    m_taskListHeader = new TaskListHeader();
    m_taskListHeader->setText(0, "Incomplete");
    m_ui.taskListTree->addTopLevelItem(m_taskListHeader);
    m_ui.taskListTree->expandItem(m_taskListHeader);
    m_taskListHeader->setFirstColumnSpanned(true);

    // auto temp2 = new TaskListItem();
    // temp2->setText(TaskListItem::Title, "foo");
    // // temp2->setData(TaskListItem::Priority, Qt::DisplayRole, 1);
    // temp->addChild(temp2);
    // auto comboBox1 = new QComboBox(this);
    // for (int idx = 0; idx < 5; idx++) {
    //     comboBox1->addItem(QString::number(idx));
    // }
    // m_ui.taskListTree->setItemWidget(temp2, TaskListItem::Priority, comboBox1);
    // m_ui.taskListTree->setItemWidget(temp2, TaskListItem::Completed, new QCheckBox(this));
}

void TaskListView::initTreeSections()
{
    auto tree = m_ui.taskListTree;
    tree->setColumnCount(TaskListItem::Count);
    tree->setHeaderLabels({ COL_HEADER_TITLE });
    auto header = tree->header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(TaskListItem::Title, QHeaderView::Stretch);
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
        addNewTask(task);
    }
}

void TaskListView::addNewTask(Task& task)
{
    auto taskListItem = new TaskListItem();
    // TODO: set internal to TaskListItem
    taskListItem->setText(TaskListItem::Title, task.title);
    m_taskListHeader->addChild(taskListItem);
}

#include "tasklistview.h"
#include "taskitem.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include <QAbstractButton>
#include <QCheckBox>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initTreeSections();
    initButtons();

    auto temp = new QTreeWidgetItem();
    temp->setText(0, "Incomplete");
    m_ui.taskListTree->addTopLevelItem(temp);
    m_ui.taskListTree->expandItem(temp);
    temp->setFirstColumnSpanned(true);

    auto temp2 = new QTreeWidgetItem();
    temp2->setText(TaskItem::Title, "foo");
    temp2->setData(TaskItem::Priority, Qt::DisplayRole, 1);
    temp->addChild(temp2);
    m_ui.taskListTree->setItemWidget(temp2, TaskItem::Completed, new QCheckBox(this));

    auto temp3 = new QTreeWidgetItem();
    temp3->setText(TaskItem::Title, "bar");
    temp3->setData(TaskItem::Priority, Qt::DisplayRole, 2);
    temp->addChild(temp3);
    m_ui.taskListTree->setItemWidget(temp3, TaskItem::Completed, new QCheckBox(this));

    auto temp4 = new QTreeWidgetItem();
    temp4->setText(0, "Complete");
    m_ui.taskListTree->addTopLevelItem(temp4);
    m_ui.taskListTree->expandItem(temp4);
    temp4->setFirstColumnSpanned(true);

    auto temp5 = new QTreeWidgetItem();
    temp5->setText(TaskItem::Title, "hello");
    temp5->setData(TaskItem::Priority, Qt::DisplayRole, 3);
    temp4->addChild(temp5);
    m_ui.taskListTree->setItemWidget(temp5, TaskItem::Completed, new QCheckBox(this));

    auto temp6 = new QTreeWidgetItem();
    temp6->setText(TaskItem::Title, "yo");
    temp6->setData(TaskItem::Priority, Qt::DisplayRole, -1);
    temp4->addChild(temp6);
    m_ui.taskListTree->setItemWidget(temp6, TaskItem::Completed, new QCheckBox(this));
}

void TaskListView::initTreeSections()
{
    auto tree = m_ui.taskListTree;
    tree->setColumnCount(TaskItem::Count);
    tree->setHeaderLabels({ COL_HEADER_COMPLETED, COL_HEADER_TITLE, COL_HEADER_PRIORITY });
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

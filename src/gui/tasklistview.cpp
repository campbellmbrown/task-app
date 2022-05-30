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

    auto temp = new QTreeWidgetItem();
    temp->setText(0, "Incomplete");
    m_ui.taskListTree->addTopLevelItem(temp);
    m_ui.taskListTree->expandItem(temp);
    temp->setFirstColumnSpanned(true);

    auto temp2 = new QTreeWidgetItem();
    temp2->setText(0, "foo");
    temp2->setData(1, Qt::DisplayRole, 1);
    temp->addChild(temp2);

    auto temp3 = new QTreeWidgetItem();
    temp3->setText(0, "bar");
    temp3->setData(1, Qt::DisplayRole, 2);
    temp->addChild(temp3);

    auto temp4 = new QTreeWidgetItem();
    temp4->setText(0, "Complete");
    m_ui.taskListTree->addTopLevelItem(temp4);
    m_ui.taskListTree->expandItem(temp4);
    temp4->setFirstColumnSpanned(true);

    auto temp5 = new QTreeWidgetItem();
    temp5->setText(0, "hello");
    temp5->setData(1, Qt::DisplayRole, 3);
    temp4->addChild(temp5);

    auto temp6 = new QTreeWidgetItem();
    temp6->setText(0, "yo");
    temp6->setData(1, Qt::DisplayRole, -1);
    temp4->addChild(temp6);
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

#include "tasklistview.h"
#include "tasklistitem.h"
#include "tasklistheader.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include <QAbstractButton>
#include <QCheckBox>
#include <QComboBox>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initTreeSections();
    initButtons();

    auto temp = new TaskListHeader();
    temp->setText(0, "Incomplete");
    m_ui.taskListTree->addTopLevelItem(temp);
    m_ui.taskListTree->expandItem(temp);
    temp->setFirstColumnSpanned(true);

    auto temp2 = new TaskListItem();
    temp2->setText(TaskListItem::Title, "foo");
    // temp2->setData(TaskListItem::Priority, Qt::DisplayRole, 1);
    temp->addChild(temp2);
    auto comboBox1 = new QComboBox(this);
    for (int idx = 0; idx < 5; idx++) {
        comboBox1->addItem(QString::number(idx));
    }
    m_ui.taskListTree->setItemWidget(temp2, TaskListItem::Priority, comboBox1);
    m_ui.taskListTree->setItemWidget(temp2, TaskListItem::Completed, new QCheckBox(this));

    auto temp3 = new QTreeWidgetItem();
    temp3->setText(TaskListItem::Title, "bar");
    temp3->setData(TaskListItem::Priority, Qt::DisplayRole, 2);
    temp->addChild(temp3);
    m_ui.taskListTree->setItemWidget(temp3, TaskListItem::Completed, new QCheckBox(this));

    auto temp4 = new TaskListHeader();
    temp4->setText(0, "Complete");
    m_ui.taskListTree->addTopLevelItem(temp4);
    m_ui.taskListTree->expandItem(temp4);
    temp4->setFirstColumnSpanned(true);

    auto temp5 = new QTreeWidgetItem();
    temp5->setText(TaskListItem::Title, "hello");
    temp5->setData(TaskListItem::Priority, Qt::DisplayRole, 3);
    temp4->addChild(temp5);
    m_ui.taskListTree->setItemWidget(temp5, TaskListItem::Completed, new QCheckBox(this));

    auto temp6 = new QTreeWidgetItem();
    temp6->setText(TaskListItem::Title, "yo");
    temp6->setData(TaskListItem::Priority, Qt::DisplayRole, -1);
    temp4->addChild(temp6);
    m_ui.taskListTree->setItemWidget(temp6, TaskListItem::Completed, new QCheckBox(this));
}

void TaskListView::initTreeSections()
{
    auto tree = m_ui.taskListTree;
    tree->setColumnCount(TaskListItem::Count);
    tree->setHeaderLabels({ COL_HEADER_COMPLETED, COL_HEADER_TITLE, COL_HEADER_PRIORITY });
    auto header = tree->header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(TaskListItem::Completed, QHeaderView::Fixed);
    header->setSectionResizeMode(TaskListItem::Title, QHeaderView::Stretch);
    header->setSectionResizeMode(TaskListItem::Priority, QHeaderView::ResizeToContents);
    header->resizeSection(TaskListItem::Completed, 60);
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

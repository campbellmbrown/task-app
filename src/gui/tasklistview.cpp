#include "tasklistview.h"
#include "dialogs/createtaskdlg.h"
#include "models/projectscollection.h"
#include "models/task.h"
#include "tasktablemodel.h"
#include <QAbstractButton>
#include <QSortFilterProxyModel>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent),
      m_taskTableModel(new TaskTableModel()),
      m_proxyModel(new QSortFilterProxyModel())
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    initTableSections();
    initButtons();
}

void TaskListView::initTableSections()
{
    // Enabling sorting/filtering
    m_proxyModel->setSortRole(Qt::UserRole);
    m_proxyModel->setSourceModel(m_taskTableModel);
    auto table = m_ui.taskTableView;
    table->setModel(m_proxyModel);

    // Setting up the headers
    table->horizontalHeader()->setStretchLastSection(false);
    table->horizontalHeader()->setSectionResizeMode(TaskTableModel::Title, QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(TaskTableModel::TimeCreated, QHeaderView::ResizeToContents);
    connect(table->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &TaskListView::onSelectedTaskChanged);
}

void TaskListView::initButtons()
{
    m_ui.deleteBtn->setEnabled(false);
    connect(m_ui.newBtn, &QAbstractButton::clicked, this, &TaskListView::onNewBtnClicked);
    connect(m_ui.deleteBtn, &QAbstractButton::clicked, this, &TaskListView::onDeleteBtnClicked);
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
        m_taskTableModel->addTask(task);
    }
}

void TaskListView::onDeleteBtnClicked()
{
    auto selectedRows = m_ui.taskTableView->selectionModel()->selectedRows();
    assert(selectedRows.count() == 1);
    m_taskTableModel->removeTaskAt(selectedRows[0].row());
}

void TaskListView::onSelectedTaskChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    // The button should only be enabled if we have selected something.
    m_ui.deleteBtn->setEnabled(current.row() >= 0);
}

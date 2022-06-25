#include "tasksection.h"
#include "dialogs/createtaskdlg.h"
#include "models/project.h"
#include "models/task.h"
#include "tasktablemodel.h"
#include <QSortFilterProxyModel>

TaskSection::TaskSection(QList<Task>& tasks, QList<Project>& projects, QWidget *parent)
    : QWidget(parent),
      m_projects(projects),
      m_taskTableModel(new TaskTableModel(tasks)),
      m_proxyModel(new QSortFilterProxyModel())
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    initTableView();
    initButtons();
}

void TaskSection::initTableView()
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
    connect(table->selectionModel(), &QItemSelectionModel::currentRowChanged, this,
            &TaskSection::onSelectedTaskChanged);
}

void TaskSection::initButtons()
{
    m_ui.deleteBtn->setEnabled(false);
    connect(m_ui.newBtn, &QAbstractButton::clicked, this, &TaskSection::onNewBtnClicked);
    connect(m_ui.deleteBtn, &QAbstractButton::clicked, this, &TaskSection::onDeleteBtnClicked);
}

void TaskSection::onNewBtnClicked()
{
    Task task;
    CreateTaskDlg createTaskDlg(task, m_projects, this);
    if (createTaskDlg.exec() == QDialog::Accepted) {
        m_taskTableModel->addTask(task);
    }
}

void TaskSection::onDeleteBtnClicked()
{
    auto selectedRows = m_ui.taskTableView->selectionModel()->selectedRows();
    assert(selectedRows.count() == 1);
    auto sourceIndex = m_proxyModel->mapToSource(selectedRows[0]);
    m_taskTableModel->removeTaskAt(sourceIndex.row());
}

void TaskSection::onSelectedTaskChanged(const QModelIndex& current, const QModelIndex& previous)
{
    Q_UNUSED(previous);

    auto sourceIndex = m_proxyModel->mapToSource(current);
    auto row = sourceIndex.row();

    // The button should only be enabled if we have selected something.
    bool someRowSelected = (row >= 0);

    m_ui.deleteBtn->setEnabled(someRowSelected);
    if (someRowSelected) {
        Task& task = m_taskTableModel->taskAt(row);
        emit taskSelected(task);
    }
    else {
        emit nothingSelected();
    }
}

void TaskSection::forceTableUpdate()
{
    m_taskTableModel->forceUpdate();
}

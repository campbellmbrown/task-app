#include "projectsection.h"
#include "dialogs/createprojectdlg.h"
#include "models/project.h"
#include "projecttablemodel.h"
#include <QSortFilterProxyModel>

ProjectSection::ProjectSection(QList<Project>& projects, QWidget *parent)
    : QWidget(parent),
      m_projectTableModel(new ProjectTableModel(projects)),
      m_proxyModel(new QSortFilterProxyModel())
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);

    initTableView();
    initButtons();
}

void ProjectSection::initTableView()
{
    // Enabling sorting/filtering
    m_proxyModel->setSortRole(Qt::UserRole);
    m_proxyModel->setSourceModel(m_projectTableModel);
    auto table = m_ui.projectTableView;
    table->setModel(m_proxyModel);

    // Setting up the headers
    table->horizontalHeader()->setStretchLastSection(false);
    table->horizontalHeader()->setSectionResizeMode(ProjectTableModel::Name, QHeaderView::Stretch);
    connect(table->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this,
            &ProjectSection::onSelectedProjectChanged);
}

void ProjectSection::initButtons()
{
    m_ui.deleteBtn->setEnabled(false);
    connect(m_ui.newBtn, &QAbstractButton::clicked, this, &ProjectSection::onNewBtnClicked);
    connect(m_ui.deleteBtn, &QAbstractButton::clicked, this, &ProjectSection::onDeleteBtnClicked);
}

void ProjectSection::onNewBtnClicked()
{
    Project project;
    CreateProjectDlg createProjectDlg(project, this);
    if (createProjectDlg.exec() == QDialog::Accepted) {
        m_projectTableModel->addProject(project);
    }
}

void ProjectSection::onDeleteBtnClicked()
{
    auto selectedRows = m_ui.projectTableView->selectionModel()->selectedRows();
    assert(selectedRows.count() == 1);
    auto sourceIndex = m_proxyModel->mapToSource(selectedRows[0]);
    m_projectTableModel->removeProjectAt(sourceIndex.row());
}

void ProjectSection::onSelectedProjectChanged(const QModelIndex& current, const QModelIndex& previous)
{
    Q_UNUSED(previous);

    auto sourceIndex = m_proxyModel->mapToSource(current);
    auto row = sourceIndex.row();

    // The button should only be enabled if we have selected something.
    bool someRowSelected = (row >= 0);

    m_ui.deleteBtn->setEnabled(someRowSelected);
    if (someRowSelected) {
        Project& project = m_projectTableModel->projectAt(row);
        emit projectSelected(project);
    }
    else {
        emit nothingSelected();
    }
}

void ProjectSection::forceTableUpdate()
{
    m_projectTableModel->forceUpdate();
}

#include "taskapp.h"
#include "projectsection.h"
#include "projectdetailsection.h"
#include "taskdetailsection.h"
#include "tasksection.h"

TaskApp::TaskApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);
    m_ui.tasksDetailsSplitter->setStretchFactor(0, 5);
    m_ui.tasksDetailsSplitter->setStretchFactor(1, 2);
    m_ui.projectsDetailsSplitter->setStretchFactor(0, 5);
    m_ui.projectsDetailsSplitter->setStretchFactor(1, 2);

    initTasksTab();
    initProjectsTab();
}

void TaskApp::initTasksTab()
{
    m_taskSection = new TaskSection(m_tasks, m_projectCollection, this);
    m_ui.taskListLayout->addWidget(m_taskSection, 0, 0);

    m_taskDetailSection = new TaskDetailSection(m_projectCollection, this);
    m_ui.taskDetailLayout->addWidget(m_taskDetailSection, 0, 0);

    connect(m_taskSection, &TaskSection::taskSelected, m_taskDetailSection, &TaskDetailSection::onTaskSelected);
    connect(m_taskSection, &TaskSection::nothingSelected, m_taskDetailSection, &TaskDetailSection::onNothingSelected);
    connect(m_taskDetailSection, &TaskDetailSection::taskUpdated, m_taskSection, &TaskSection::forceTableUpdate);
}

void TaskApp::initProjectsTab()
{
    m_projectSection = new ProjectSection(m_projectCollection, this);
    m_ui.projectListLayout->addWidget(m_projectSection, 0, 0);

    m_projectDetailSection = new ProjectDetailSection(this);
    m_ui.projectDetailLayout->addWidget(m_projectDetailSection, 0, 0);

    connect(m_projectSection,
            &ProjectSection::projectSelected,
            m_projectDetailSection,
            &ProjectDetailSection::onProjectSelected);
    connect(m_projectSection,
            &ProjectSection::nothingSelected,
            m_projectDetailSection,
            &ProjectDetailSection::onNothingSelected);
    connect(m_projectDetailSection, &ProjectDetailSection::projectUpdated, this, [=]() {
        m_projectSection->forceTableUpdate();
        m_projectCollection.setupQuickFind();
        m_taskDetailSection->refresh();
    });
    connect(m_projectSection, &ProjectSection::projectDeleted, m_taskDetailSection, &TaskDetailSection::refresh);
}

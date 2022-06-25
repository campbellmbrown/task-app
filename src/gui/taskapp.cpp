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
    taskSection = new TaskSection(m_tasks, m_projects, this);
    m_ui.taskListLayout->addWidget(taskSection, 0, 0);

    taskDetailSection = new TaskDetailSection(this);
    m_ui.taskDetailLayout->addWidget(taskDetailSection, 0, 0);

    connect(taskSection, &TaskSection::taskSelected, taskDetailSection, &TaskDetailSection::onTaskSelected);
    connect(taskSection, &TaskSection::nothingSelected, taskDetailSection, &TaskDetailSection::onNothingSelected);
    connect(taskDetailSection, &TaskDetailSection::taskUpdated, taskSection, &TaskSection::forceTableUpdate);
}

void TaskApp::initProjectsTab()
{
    projectSection = new ProjectSection(m_projects, this);
    m_ui.projectListLayout->addWidget(projectSection, 0, 0);

    projectDetailSection = new ProjectDetailSection(this);
    m_ui.projectDetailLayout->addWidget(projectDetailSection, 0, 0);

    connect(projectSection,
            &ProjectSection::projectSelected,
            projectDetailSection,
            &ProjectDetailSection::onProjectSelected);
    connect(projectSection,
            &ProjectSection::nothingSelected,
            projectDetailSection,
            &ProjectDetailSection::onNothingSelected);
    connect(projectDetailSection,
            &ProjectDetailSection::projectUpdated,
            projectSection,
            &ProjectSection::forceTableUpdate);
}

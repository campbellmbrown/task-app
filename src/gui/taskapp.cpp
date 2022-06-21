#include "taskapp.h"
#include "detailsection.h"
#include "tasksection.h"

TaskApp::TaskApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);
    m_ui.tasksDetailsSplitter->setStretchFactor(0, 5);
    m_ui.tasksDetailsSplitter->setStretchFactor(1, 2);
    m_ui.projectsDetailsSplitter->setStretchFactor(0, 5);
    m_ui.projectsDetailsSplitter->setStretchFactor(1, 2);

    initGuiElements();
}

void TaskApp::initGuiElements()
{
    taskSection = new TaskSection(this);
    m_ui.taskListLayout->addWidget(taskSection, 0, 0);

    detailSection = new DetailSection(this);
    m_ui.taskDetailLayout->addWidget(detailSection, 0, 0);

    connect(taskSection, &TaskSection::taskSelected, detailSection, &DetailSection::onTaskSelected);
    connect(taskSection, &TaskSection::nothingSelected, detailSection, &DetailSection::onNothingSelected);
    connect(detailSection, &DetailSection::taskUpdated, taskSection, &TaskSection::forceTableUpdate);
}

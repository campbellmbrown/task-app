#include "taskapp.h"
#include "detailSection.h"
#include "tasksection.h"

TaskApp::TaskApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);
    m_ui.tasksDetailsSplitter->setStretchFactor(0, 5);
    m_ui.tasksDetailsSplitter->setStretchFactor(1, 2);

    initGuiElements();
}

void TaskApp::initGuiElements()
{
    taskSection = new TaskSection(this);
    m_ui.taskListLayout->addWidget(taskSection, 0, 0);

    detailSection = new DetailSection(this);
    m_ui.detailsLayout->addWidget(detailSection, 0, 0);

    connect(taskSection, &TaskSection::taskSelected, detailSection, &DetailSection::onTaskSelected);
}

#include "taskapp.h"

TaskApp::TaskApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);
    m_ui.taskListSplitter->setStretchFactor(0, 5);
    m_ui.taskListSplitter->setStretchFactor(1, 1);
}

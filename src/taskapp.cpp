#include "taskapp.h"

TaskApp::TaskApp(QWidget* parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	m_ui.tasksSplitter->setStretchFactor(0, 5);
	m_ui.tasksSplitter->setStretchFactor(1, 2);
}

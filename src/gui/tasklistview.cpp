#include "tasklistview.h"
#include "dialogs/createtaskdlg.h"
#include <QAbstractButton>

TaskListView::TaskListView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    initButtons();
}

void TaskListView::initButtons()
{
    connect(m_ui.newBtn, &QAbstractButton::clicked, this, &TaskListView::onNewBtnClicked);
}

void TaskListView::onNewBtnClicked()
{
    CreateTaskDlg createTaskDlg(this);
    createTaskDlg.exec();
}

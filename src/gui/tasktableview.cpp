#include "tasktableview.h"
#include <QKeyEvent>

TaskTableView::TaskTableView(QWidget *parent)
    : QTableView(parent)
{
}

void TaskTableView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
            selectionModel()->clear();
            break;
    }
}

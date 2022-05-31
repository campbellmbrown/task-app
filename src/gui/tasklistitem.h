#pragma once

#include <QTreeWidgetItem>

class TaskListItem : public QTreeWidgetItem
{
public:
    enum Columns
    {
        Title = 0,
        Count,
    };

    TaskListItem();
};

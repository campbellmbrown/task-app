#pragma once

#include <QTreeWidgetItem>

class TaskListItem : public QTreeWidgetItem
{
public:
    enum Columns
    {
        Completed = 0,
        Title,
        Priority,
        Count
    };

    TaskListItem();
};

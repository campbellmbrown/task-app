#pragma once

#include <QTreeWidgetItem>

class TaskItem : public QTreeWidgetItem
{
public:
    enum Columns
    {
        Completed = 0,
        Title,
        Priority,
        Count
    };

    TaskItem();
};

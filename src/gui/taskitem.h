#pragma once

#include <QTreeWidgetItem>

class TaskItem : public QTreeWidgetItem
{
public:
    enum Columns
    {
        Title = 0,
        Priority,
        Count
    };

    TaskItem();
};

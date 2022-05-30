#pragma once

#include <QTreeWidgetItem>

class TaskListHeader : public QTreeWidgetItem
{
public:
    TaskListHeader();

    bool operator < (const QTreeWidgetItem &other) const { return false; }
};

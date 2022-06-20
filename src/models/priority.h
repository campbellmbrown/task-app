#pragma once

#include <QIcon>
#include <QMap>
#include <QString>

enum Priority
{
    Downtime,
    Low,
    Medium,
    High,
    Blocker,
    Count,
};

class PriorityDisplay
{
public:
    static QString text(Priority priority);
    static QIcon icon(Priority priority);

private:
    static QMap<Priority, QString> m_labelMap;
};

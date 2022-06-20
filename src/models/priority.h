#pragma once

#include <QString>
#include <QMap>

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

private:
    static QMap<Priority, QString> m_labelMap;
};

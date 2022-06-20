#include "priority.h"

QMap<Priority, QString> PriorityDisplay::m_labelMap{ {
    { Priority::Downtime, "Downtime" },
    { Priority::Low, "Low" },
    { Priority::Medium, "Medium" },
    { Priority::High, "High" },
    { Priority::Blocker, "Blocker" },
} };

QString PriorityDisplay::text(Priority priority)
{
    return m_labelMap[priority];
}

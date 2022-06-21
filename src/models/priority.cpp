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

QIcon PriorityDisplay::icon(Priority priority)
{
    static QIcon downtimePriorityIcon(":/icons/downtimepriority.png");
    static QIcon lowPriorityIcon(":/icons/lowpriority.png");
    static QIcon mediumPriorityIcon(":/icons/mediumpriority.png");
    static QIcon highPriorityIcon(":/icons/highpriority.png");
    static QIcon blockerPriorityIcon(":/icons/blockerpriority.png");
    switch (priority) {
        case Priority::Downtime:
            return downtimePriorityIcon;

        case Priority::Low:
            return lowPriorityIcon;

        case Priority::Medium:
            return mediumPriorityIcon;

        case Priority::High:
            return highPriorityIcon;

        case Priority::Blocker:
            return blockerPriorityIcon;

        default:
            assert(false);
            return QIcon();
    }
}

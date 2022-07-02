#pragma once

#include "priority.h"
#include <QString>
#include <QDateTime>
#include <QUuid>

struct Task
{
    static constexpr auto VERSION = 3;
    static constexpr auto DATE_FORMAT = "dd/MM/yy hh:mm:ss ap";

    explicit Task() {}

    // ===============
    //     General
    // ===============
    QString title;
    Priority priority = Priority::Medium;
    // Only store the projectId because the project name can change.
    QUuid projectId;
    QString notes;
    // ===============
    //    Metadata
    // ===============
    QUuid uuid;
    QDateTime timeCreated;
};

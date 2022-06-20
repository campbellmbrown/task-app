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

    QString title;
    QDateTime timeCreated;
    QUuid uuid;
    QString notes;
    Priority priority = Priority::Medium;
};

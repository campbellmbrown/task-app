#pragma once

#include <QString>
#include <QDateTime>

struct Task
{
    explicit Task() {}

    QString title;
    QDateTime timeCreated;
};

#pragma once

#include <QString>
#include <QDateTime>
#include <QUuid>

struct Task
{
    static constexpr auto VERSION = 1;

    explicit Task() {}

    QString title;
    QDateTime timeCreated;
    QUuid uuid;
};

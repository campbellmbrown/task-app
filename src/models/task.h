#pragma once

#include <QString>
#include <QDateTime>
#include <QUuid>

struct Task
{
    static constexpr auto VERSION = 2;
    static constexpr auto DATE_FORMAT = "dd/MM/yy hh:mm:ss ap";

    explicit Task() {}

    QString title;
    QDateTime timeCreated;
    QUuid uuid;
    QString notes;
};

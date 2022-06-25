#pragma once

#include <QString>
#include <QUuid>

struct Project
{
    static constexpr auto VERSION = 1;

    explicit Project() {}

    QString name;
    QUuid uuid;
    QString notes;
};

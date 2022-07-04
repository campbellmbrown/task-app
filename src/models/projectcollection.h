#pragma once

#include "models/project.h"
#include <QList>
#include <QMap>
#include <QObject>

class ProjectCollection : public QObject
{
    Q_OBJECT

public:
    ProjectCollection(QObject *parent = nullptr);

    QList<Project>& projects();
    void removeAt(int i);
    void insert(int i, const Project& project);
    QString name(QUuid id) const;
    bool contains(QUuid id) const;
    bool contains(QString name) const;

public slots:
    void setupQuickFind();

private:
    QList<Project> m_projects;
    QMap<QUuid, QString> m_quickFindName;
};

#include "projectcollection.h"

ProjectCollection::ProjectCollection(QObject *parent)
    : QObject(parent)
{
    setupQuickFind();
}

QList<Project>& ProjectCollection::projects()
{
    return m_projects;
}

void ProjectCollection::removeAt(int i)
{
    auto project = m_projects.at(i);
    m_quickFindName.remove(project.uuid);
    m_projects.removeAt(i);
    assert(m_projects.count() == m_quickFindName.count());
}

void ProjectCollection::insert(int i, const Project& project)
{
    m_projects.insert(i, project);
    m_quickFindName.insert(project.uuid, project.name);
    assert(m_projects.count() == m_quickFindName.count());
}

void ProjectCollection::setupQuickFind()
{
    m_quickFindName.clear();
    for (auto proj : m_projects) {
        m_quickFindName.insert(proj.uuid, proj.name);
    }
}

QString ProjectCollection::name(QUuid id) const
{
    if (id == QUuid()) {
        return "";
    }
    if (m_quickFindName.contains(id)) {
        return m_quickFindName.value(id);
    }
    return "UNKNOWN";
}

bool ProjectCollection::contains(QUuid id) const
{
    return m_quickFindName.contains(id);
}

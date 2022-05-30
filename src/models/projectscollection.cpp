#include "projectscollection.h"

ProjectsCollection::ProjectsCollection()
{
}

ProjectsCollection::Projects ProjectsCollection::projects() const
{
    return m_projects;
}

void ProjectsCollection::addProject(QString project)
{
    assert(!m_projects.contains(project));
    m_projects.append(project);
}

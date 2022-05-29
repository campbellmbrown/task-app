#pragma once

#include <QList>

class ProjectsCollection
{
public:
    using Projects = QList<QString>;

public:
    ProjectsCollection();

    Projects projects() const;
    void addProject(QString project);

private:
    Projects m_projects;
};

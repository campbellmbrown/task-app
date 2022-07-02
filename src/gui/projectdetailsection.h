#pragma once

#include "models/project.h"
#include "ui_projectdetailsection.h"
#include <QWidget>

class ProjectCollection;
class ProjectDetailSection : public QWidget
{
    Q_OBJECT

    friend class ProjectDetailSectionTest;

public:
    ProjectDetailSection(ProjectCollection& projectCollection, QWidget *parent = nullptr);

public slots:
    void onProjectSelected(Project& selected);
    void onNothingSelected();

signals:
    void projectUpdated();

private:
    void reset();
    bool checkFields();

private slots:
    void onApply();

private:
    Ui::ProjectDetailSection m_ui;
    Project *m_selectedProject = nullptr;
    ProjectCollection& m_projectCollection;
};

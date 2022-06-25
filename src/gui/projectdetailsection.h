#pragma once

#include "models/project.h"
#include "ui_projectdetailsection.h"
#include <QWidget>

class ProjectDetailSection : public QWidget
{
    Q_OBJECT

    friend class ProjectDetailSectionTest;

public:
    ProjectDetailSection(QWidget *parent = nullptr);

public slots:
    void onProjectSelected(Project& selected);
    void onNothingSelected();

signals:
    void projectUpdated();

private:
    void reset();

private slots:
    void onApply();

private:
    Ui::ProjectDetailSection m_ui;
    Project *m_selectedProject = nullptr;
};

#pragma once

#include "ui_projectsection.h"
#include <QWidget>

class ProjectSection : public QWidget
{
    Q_OBJECT

    friend class ProjectSectionTest;

public:
    ProjectSection(QWidget *parent = nullptr);

private:
    Ui::ProjectSection m_ui;
};

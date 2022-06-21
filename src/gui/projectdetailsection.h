#pragma once

#include "ui_projectdetailsection.h"
#include <QWidget>

class ProjectDetailSection : public QWidget
{
    Q_OBJECT

    friend class ProjectDetailSection;

public:
    ProjectDetailSection(QWidget *parent = nullptr);

private:
    Ui::ProjectDetailSection m_ui;
};

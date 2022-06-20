#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_taskapp.h"

class TaskApp : public QMainWindow
{
    Q_OBJECT

public:
    TaskApp(QWidget *parent = Q_NULLPTR);

private:
    void initGuiElements();

private:
    Ui::TaskApp m_ui;

    TaskSection *taskSection;
    DetailSection *detailSection;
};

#pragma once

#include "models/task.h"
#include "ui_detailsection.h"
#include <QWidget>

class DetailSection : public QWidget
{
    Q_OBJECT

public:
    DetailSection(QWidget *parent = nullptr);

    void onTaskSelected(Task& selected);
    void onNothingSelected();

private:
    void reset();

private slots:
    void onApply();

private:
    Ui::DetailSection m_ui;
    Task *m_selectedTask = nullptr;
};

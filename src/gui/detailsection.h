#pragma once

#include "models/task.h"
#include "ui_detailsection.h"
#include <QWidget>

class DetailSection : public QWidget
{
    Q_OBJECT

    friend class DetailSectionTest;

public:
    DetailSection(QWidget *parent = nullptr);

    void onTaskSelected(Task& selected);
    void onNothingSelected();

signals:
    void taskUpdated();

private:
    void reset();

private slots:
    void onApply();

private:
    Ui::DetailSection m_ui;
    Task *m_selectedTask = nullptr;
};

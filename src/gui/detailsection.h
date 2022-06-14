#pragma once

#include "ui_detailsection.h"
#include <QWidget>

struct Task;
class DetailSection : public QWidget
{
    Q_OBJECT

public:
    DetailSection(QWidget *parent = nullptr);

    void onTaskSelected(std::shared_ptr<Task> selected);
    void onNothingSelected();

private:
    void reset();

private:
    Ui::DetailSection m_ui;
    std::shared_ptr<Task> m_selectedTask = nullptr;
};

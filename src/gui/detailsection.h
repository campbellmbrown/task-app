#pragma once

#include "ui_detailsection.h"
#include <QWidget>

struct Task;
class DetailSection : public QWidget
{
    Q_OBJECT

public:
    DetailSection(QWidget *parent = nullptr);

    void onTaskSelected(Task& selected);
    void onNothingSelected();

private:
    Ui::DetailSection m_ui;
};

#pragma once

#include "ui_detailsection.h"
#include <QWidget>

class Task;
class DetailSection : public QWidget
{
    Q_OBJECT

public:
    DetailSection(QWidget *parent = nullptr);

    void onTaskSelected(Task& selected);

private:
    Ui::DetailSection m_ui;
};

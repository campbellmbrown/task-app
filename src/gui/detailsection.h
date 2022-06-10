#pragma once

#include "ui_detailsection.h"
#include <QWidget>

class DetailSection : public QWidget
{
    Q_OBJECT

public:
    DetailSection(QWidget *parent = nullptr);

private:
    Ui::DetailSection m_ui;
};

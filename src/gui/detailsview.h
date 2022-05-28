#pragma once

#include "ui_detailsview.h"
#include <QWidget>

class DetailsView : public QWidget
{
    Q_OBJECT

public:
    DetailsView(QWidget *parent = nullptr);

private:
    Ui::DetailsView m_ui;
};

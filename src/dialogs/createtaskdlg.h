#pragma once

#include "ui_createtaskdlg.h"
#include <QDialog>

class CreateTaskDlg : public QDialog
{
    Q_OBJECT

public:
    CreateTaskDlg(QWidget *parent = nullptr);

private:
    Ui::CreateTaskDlg m_ui;
};

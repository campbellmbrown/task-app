#pragma once

#include <QTableView>

class TaskTableView : public QTableView
{
public:
    explicit TaskTableView(QWidget *parent = nullptr);

private:
    void keyPressEvent(QKeyEvent *event) override;
};

#pragma once

#include "ui_projectsection.h"
#include <QWidget>

struct Project;
class ProjectTableModel;
class QSortFilterProxyModel;
class ProjectSection : public QWidget
{
    Q_OBJECT

    friend class ProjectSectionTest;

public:
    ProjectSection(QWidget *parent = nullptr);

    void forceTableUpdate();

signals:
    void projectSelected(Project& selected);
    void nothingSelected();

private:
    void initTableView();
    void initButtons();

private slots:
    void onNewBtnClicked();
    void onDeleteBtnClicked();
    void onSelectedProjectChanged(const QModelIndex& current, const QModelIndex& previous);

private:
    Ui::ProjectSection m_ui;
    ProjectTableModel *m_projectTableModel;
    QSortFilterProxyModel *m_proxyModel;
};

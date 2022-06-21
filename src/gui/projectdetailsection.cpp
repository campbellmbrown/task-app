#include "projectdetailsection.h"

ProjectDetailSection::ProjectDetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
}

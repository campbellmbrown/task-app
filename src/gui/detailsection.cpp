#include "detailsection.h"

DetailSection::DetailSection(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    m_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
}

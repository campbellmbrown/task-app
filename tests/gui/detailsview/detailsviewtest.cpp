#include "gui/detailsview.h"

#include <QtTest/QtTest>

class DetailsViewTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_something();
};

void DetailsViewTest::init()
{
}

void DetailsViewTest::check_something()
{
    QVERIFY(true);
}

QTEST_MAIN(DetailsViewTest)
#include "detailsviewtest.moc"

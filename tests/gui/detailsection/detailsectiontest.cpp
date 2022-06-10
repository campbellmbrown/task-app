#include "gui/detailsection.h"

#include <QtTest/QtTest>

class DetailSectionTest : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void check_something();
};

void DetailSectionTest::init()
{
}

void DetailSectionTest::check_something()
{
    QVERIFY(true);
}

QTEST_MAIN(DetailSectionTest)
#include "detailsectiontest.moc"

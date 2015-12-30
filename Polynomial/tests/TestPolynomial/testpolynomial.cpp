#include <QtTest/QtTest>
#include <string>

#include "../../polynomial.h"

class TestPolynomial: public QObject
{
    Q_OBJECT

private slots:
    void getPoly();
};

void TestPolynomial::getPoly()
{
    std::string polyString = "-x^2+3*x-7";
    Polynomial poly(polyString);
    QCOMPARE(poly.getPoly(), polyString);
}

QTEST_MAIN(TestPolynomial)
#include "testpolynomial.moc"

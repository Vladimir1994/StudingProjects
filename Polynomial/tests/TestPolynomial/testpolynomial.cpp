#include <QtTest/QtTest>
#include <string>

#include "../../polynomial.h"

class TestPolynomial: public QObject
{
    Q_OBJECT

private slots:
    void getPoly();
    void setPoly();
    void equal();
    void plus();
    void minus();
    void miltiplicate();
    void derivative();
};

void TestPolynomial::getPoly() {
    std::string polyString = "-x^2+3*x-7";
    Polynomial poly(polyString);
    QCOMPARE(poly.getPoly(), polyString);
}

void TestPolynomial::setPoly() {
    std::string polyStringOne = "-x^2+3*x-7";
    Polynomial poly(polyStringOne);
    std::string polyStringTwo = "-2*x^2+4*x-37";
    poly.setPoly(polyStringTwo);
    QCOMPARE(poly.getPoly(), polyStringTwo);
}

void TestPolynomial::equal() {
    std::string polyStringOne = "-x^2+3*x-7";
    Polynomial polyOne(polyStringOne);

    std::string polyStringTwo = "-2*x^2+4*x-37";
    Polynomial polyTwo(polyStringTwo);

    polyOne = polyTwo;
    QCOMPARE(polyOne.getPoly(), polyStringTwo);
}

void TestPolynomial::plus() {
    std::string polyStringOne = "-x^2+3*x-7";
    Polynomial polyOne(polyStringOne);

    std::string polyStringTwo = "5*x^3-2*x^2+4*x-37";
    Polynomial polyTwo(polyStringTwo);

    QCOMPARE((polyOne + polyTwo).getPoly(), std::string("5*x^3-3*x^2+7*x-44"));

    polyOne.setPoly("0");
    QCOMPARE((polyOne + polyTwo).getPoly(), polyStringTwo);

    polyOne.setPoly("7+7");
    QCOMPARE((polyOne + polyTwo).getPoly(), std::string("5*x^3-2*x^2+4*x-23"));

    polyOne.setPoly("7*x^2+3*x^2");
    QCOMPARE((polyOne + polyTwo).getPoly(), std::string("5*x^3+8*x^2+4*x-37"));
}

void TestPolynomial::minus() {
    std::string polyStringOne = "-x^2+3*x-7";
    Polynomial polyOne(polyStringOne);

    std::string polyStringTwo = "5*x^3-2*x^2+4*x-37";
    Polynomial polyTwo(polyStringTwo);

    QCOMPARE((polyTwo - polyOne).getPoly(), std::string("5*x^3-x^2+x-30"));

    polyOne.setPoly("0");
    QCOMPARE((polyTwo - polyOne).getPoly(), polyStringTwo);

    polyOne.setPoly("7+7");
    QCOMPARE((polyTwo - polyOne).getPoly(), std::string("5*x^3-2*x^2+4*x-51"));

    polyOne.setPoly("7*x^2+3*x^2");
    QCOMPARE((polyTwo - polyOne).getPoly(), std::string("5*x^3-12*x^2+4*x-37"));
}

void TestPolynomial::miltiplicate() {
    std::string polyStringOne = "-x^2+3*x-7";
    Polynomial polyOne(polyStringOne);

    std::string polyStringTwo = "5*x^3+4*x-37";
    Polynomial polyTwo(polyStringTwo);

    QCOMPARE((polyTwo * polyOne).getPoly(),
        std::string("-5*x^5+15*x^4-39*x^3+49*x^2-139*x+259"));

    polyOne.setPoly("0");
    QCOMPARE((polyTwo * polyOne).getPoly(), std::string("0"));

    polyOne.setPoly("2");
    QCOMPARE((polyTwo * polyOne).getPoly(), std::string("10*x^3+8*x-74"));
}

void TestPolynomial::derivative() {
    std::string polyString = "-x^2+3*x-7";
    Polynomial poly(polyString);

    QCOMPARE(poly.derivative().getPoly(), std::string("-2*x+3"));

    poly.setPoly("0");
    QCOMPARE(poly.derivative().getPoly(), std::string("0"));

    poly.setPoly("7");
    QCOMPARE(poly.derivative().getPoly(), std::string("0"));
}

QTEST_MAIN(TestPolynomial)
#include "testpolynomial.moc"

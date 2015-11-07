#include "idecorator.h"
#include "iostream"

IDecorator::IDecorator(IProduct * product, double price):
    IProduct(price), m_product_(product)  {}

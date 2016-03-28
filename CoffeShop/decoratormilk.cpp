#include "decoratormilk.h"

DecoratorMilk::DecoratorMilk(IProduct *product, double price):
    IDecorator(product, price)
{}

double DecoratorMilk::price()
{
    return m_product_->price() + price_;
}

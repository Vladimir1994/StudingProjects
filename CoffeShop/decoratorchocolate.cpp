#include "decoratorchocolate.h"

DecoratorChocolate::DecoratorChocolate(IProduct *product, double price):
    IDecorator(product, price)
{}

double DecoratorChocolate::price()
{
    return m_product_->price() + price_;
}


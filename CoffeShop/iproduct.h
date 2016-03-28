#ifndef IPRODUCT_H
#define IPRODUCT_H

class IProduct
{
public:
    IProduct(double price = 0);
    virtual double price() = 0;
    virtual ~IProduct() {}

protected:
    const double price_;
};

#endif // IPRODUCT_H

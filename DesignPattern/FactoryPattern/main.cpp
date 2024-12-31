#include "Factory.h"
#include "Product.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Factory *Fac = new ConcreteFactory();
    Product *P = Fac->CreateProduct();
    return 0;
}
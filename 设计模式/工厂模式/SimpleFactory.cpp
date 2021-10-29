#include <string>
#include <iostream>

class Product
{
private:
    /* data */
public:
    Product(/* args */) {}
    virtual ~Product() {}
    virtual std::string getName() = 0;
};

class ConcreteProductA : public Product
{
private:
    /* data */
public:
    ConcreteProductA(/* args */) {}
    ~ConcreteProductA() {}
    std::string getName()
    {
        return "ProductA";
    }
};

class ConcreteProductB : public Product
{
private:
    /* data */
public:
    ConcreteProductB(/* args */) {}
    ~ConcreteProductB() {}
    std::string getName()
    {
        return "ProductB";
    }
};

class SimpleFactory
{
public:
    SimpleFactory() {}
    ~SimpleFactory() {}
    Product *CreateProductA()
    {
        return new ConcreteProductA();
    }
    Product *CreadeProductB()
    {
        return new ConcreteProductB();
    }

    void removeProduct(Product *product)
    {
        delete product;
    }
};

int main()
{
    SimpleFactory *factory = new SimpleFactory();

    Product *p1 = factory->CreateProductA();
    std::cout << "Product: " << p1->getName() << std::endl;
    factory->removeProduct(p1);

    Product *p2 = factory->CreadeProductB();
    std::cout << "Product: " << p2->getName() << std::endl;
    factory->removeProduct(p2);

    delete factory;
    return 0;
}

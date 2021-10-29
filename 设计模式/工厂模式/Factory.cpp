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

class Factory
{
private:
    /* data */
public:
    Factory(/* args */) {}
    virtual ~Factory() {}

    virtual Product* CreateProductA() = 0;
    virtual Product* CreateProductB() = 0;

    virtual void removeProduct(Product *product) = 0;
};

class ConcreteFactory : public Factory
{
private:
    /* data */
public:
    ConcreteFactory(/* args */) {}
    ~ConcreteFactory() {}

    Product* CreateProductA()
    {
        return new ConcreteProductA();
    }

    Product* CreateProductB()
    {
        return new ConcreteProductB();
    }

    void removeProduct(Product* product)
    {
        delete product;
    }
};


int main()
{
  Factory *factory = new ConcreteFactory();
  
  Product *p1 = factory->CreateProductA();
  std::cout << "Product: " << p1->getName() << std::endl;
  factory->removeProduct(p1);
  
  Product *p2 = factory->CreateProductB();
  std::cout << "Product: " << p2->getName() << std::endl;
  factory->removeProduct(p2);
  
  delete factory;
  return 0;
}


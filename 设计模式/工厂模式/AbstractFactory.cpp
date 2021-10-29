#include <iostream>
#include <string>

class ProductA
{
private:
    /* data */
public:
    ProductA(/* args */) {}
    virtual ~ProductA() {}

    virtual std::string getName() = 0;
};

class ProductAX : public ProductA
{
private:
    /* data */
public:
    ProductAX(/* args */) {}
    ~ProductAX() {}

    std::string getName()
    {
        return "ProductAX";
    }
};

class ProductAY : public ProductA
{
private:
    /* data */
public:
    ProductAY(/* args */) {}
    ~ProductAY() {}

    std::string getName()
    {
        return "ProductAY";
    }
};

class ProductB
{
private:
    /* data */
public:
    ProductB(/* args */) {}
    virtual ~ProductB() {}

    virtual std::string getName() = 0;
};

class ProductBX : public ProductB
{
private:
    /* data */
public:
    ProductBX(/* args */) {}
    ~ProductBX() {}

    std::string getName()
    {
        return "ProductBX";
    }
};

class ProductBY : public ProductB
{
private:
    /* data */
public:
    ProductBY(/* args */) {}
    ~ProductBY() {}

    std::string getName()
    {
        return "ProductBY";
    }
};

class AbstractFactory
{
private:
    /* data */
public:
    AbstractFactory(/* args */) {}
    virtual ~AbstractFactory() {}

    virtual ProductA* ConcreteProductA() = 0;
    virtual ProductB* ConcreteProductB() = 0;
};

class ProductXFactory : public AbstractFactory
{
private:
    /* data */
public:
    ProductXFactory(/* args */) {}
    ~ProductXFactory() {}

    ProductA* ConcreteProductA()
    {
        return new ProductAX();
    }

    ProductB* ConcreteProductB()
    {
        return new ProductBX();
    }

};

class ProductYFactory : public AbstractFactory
{
private:
    /* data */
public:
    ProductYFactory(/* args */) {}
    ~ProductYFactory() {}

    ProductA* ConcreteProductA()
    {
        return new ProductAY();
    }

    ProductB* ConcreteProductB()
    {
        return new ProductBY();
    }
};

int main()
{
  ProductXFactory *factoryX = new ProductXFactory();
  ProductYFactory *factoryY = new ProductYFactory();

  ProductA *p1 = factoryX->ConcreteProductA();
  std::cout << "Product: " << p1->getName() << std::endl;
  
  ProductA *p2 = factoryY->ConcreteProductA();
  std::cout << "Product: " << p2->getName() << std::endl;
  
  delete p1;
  delete p2;
  
  delete factoryX;
  delete factoryY;
  
  return 0;
}

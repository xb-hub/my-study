#include <iostream>

class Target
{
private:
    /* data */
public:
    Target(/* args */) {}
    virtual ~Target() {}

    virtual void Request() = 0;
};

class Adaptee
{
private:
    /* data */
public:
    Adaptee(/* args */) {}
    ~Adaptee() {}

    void specificRequest()
    {
        std::cout << "specificRequest" << std::endl;
    }
};

class Adapter : public Target, public Adaptee
{
private:
    /* data */
public:
    Adapter(/* args */) {}
    ~Adapter() {}

    void Request()
    {
        specificRequest();
    }
};

int main()
{
  Target *t = new Adapter();
  t->Request();
  delete t;
  
  return 0;
}


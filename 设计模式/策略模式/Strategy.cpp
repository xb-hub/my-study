#include <iostream>


class ReplaceAlgorithm
{
private:
    /* data */
public:
    ReplaceAlgorithm(/* args */) {}
    ~ReplaceAlgorithm() {}

    virtual void Replace() = 0;
};

class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
private:
    /* data */
public:
    LRU_ReplaceAlgorithm(/* args */) {}
    ~LRU_ReplaceAlgorithm() {}

    void Replace()
    {
        std::cout << "LRU_Replace" << std::endl;
    }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
private:
    /* data */
public:
    FIFO_ReplaceAlgorithm(/* args */) {}
    ~FIFO_ReplaceAlgorithm() {}

    void Replace()
    {
        std::cout << "FIFO_Replace" << std::endl;
    }
};

class Random_ReplaceAlgorithm : public ReplaceAlgorithm
{
private:
    /* data */
public:
    Random_ReplaceAlgorithm(/* args */) {}
    ~Random_ReplaceAlgorithm() {}

    void Replace()
    {
        std::cout << "Random_Replace" << std::endl;
    }
};

enum RA
{
    LRU_Replace = 0,
    FIFO_Replace = 1,
    Random_Repalce = 2
};

class Cache
{
private:
    ReplaceAlgorithm* strategy;
public:
    Cache(RA ra) 
    {
        switch (ra)
        {
        case LRU_Replace:
            strategy = new LRU_ReplaceAlgorithm();
            break;
        case FIFO_Replace:
            strategy = new FIFO_ReplaceAlgorithm();
            break;
        case Random_Repalce:
            strategy = new Random_ReplaceAlgorithm();
            break;
        default:
            break;
        }
    }
    ~Cache() {}

    void Replace()
    {
        strategy->Replace();
    }
};



int main()
{
  Cache* context = new Cache(FIFO_Replace);
  context->Replace();
  return 0;
}




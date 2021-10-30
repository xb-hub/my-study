#include <iostream>

class Resume
{
private:
    /* data */
public:
    Resume(/* args */) {}
    virtual ~Resume() {}

    virtual Resume* Clone() = 0;
};

class ResumeA : public Resume
{
private:
    /* data */
public:
    ResumeA(/* args */) {}
    ~ResumeA() {}

    Resume* Clone()
    {
        return new ResumeA();
    }

    void type()
    {
        cout << 
    }
};

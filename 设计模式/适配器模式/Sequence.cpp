/**
 * ObjectAdapter
 */

#include <iostream>

class Sequence  // Target
{
private:
    /* data */
public:
    Sequence(/* args */) {}
    virtual ~Sequence() {}

    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

class Deque // Adaptee
{
private:
    /* data */
public:
    Deque(/* args */) {}
    ~Deque() {}

    void push_back(int x) { std::cout<<"Deque push_back"<<std::endl; }
	void push_front(int x) { std::cout<<"Deque push_front"<<std::endl; }
	void pop_back() { std::cout<<"Deque pop_back"<<std::endl; }
	void pop_front() { std::cout<<"Deque pop_front"<<std::endl; }
};

class Stack : public Sequence
{
private:
    Deque* deque;
public:
    Stack(/* args */) {}
    ~Stack() {}

    void push(int x)
    {
        deque->push_back(x);
    }
    void pop()
    {
        deque->pop_back();
    }
};

class Queue : public Sequence
{
private:
    Deque* deque;
public:
    Queue(/* args */) {}
    ~Queue() {}

    void push(int x)
    {
        deque->push_back(x);
    }
    void pop()
    {
        deque->pop_front();
    }
};

int main()
{
	Sequence *s1 = new Stack();
	Sequence *s2 = new Queue();
	s1->push(1); s1->pop();
	s2->push(1); s2->pop();
	delete s1; 
    delete s2;
	return 0;
}
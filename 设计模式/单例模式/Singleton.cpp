#include <iostream>
#include <pthread.h>

class Singleton {
private:
    static Singleton* instance; // 静态实例，因为getInstance()方法为静态成员函数，只能访问静态成员。

    Singleton(/* args */) {}
    ~Singleton() {}

public:
    Singleton( Singleton const& ) = delete;
    Singleton& operator=( Singleton const& ) = delete;   // 禁止拷贝和赋值操作，相当于定义成private。

    static Singleton* getInstance();    // 静态方法，因为构造方法为私有，无法在类外创建对象，静态方法可以通过类名调用，不需要创建对象。
    static pthread_mutex_t singleton_lock;
};

/** 
 * 懒汉式单例模式(线程安全)
 */
Singleton* Singleton::instance = nullptr;
pthread_mutex_t Singleton::singleton_lock = PTHREAD_MUTEX_INITIALIZER;

Singleton* Singleton::getInstance() {
    if(instance == nullptr) {
        pthread_mutex_lock(&singleton_lock);
        if(instance == nullptr) {
            instance = new Singleton();
        }
        pthread_mutex_unlock(&singleton_lock);
    }
    return instance;
}

/**
 * 饿汉式单例模式
 * 程序运行就创建对象，不需要考虑线程安全问题
 */
Singleton* Singleton::instance = new Singleton();

Singleton* Singleton::getInstance() {
    return instance;
}

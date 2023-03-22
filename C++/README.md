# C++ Prime

# Effective C++
# Modern Effective C++
## 条款1 理解模板类型推导
```
template<typename T>
void f(ParamType param);

f(expr)      //从expr中推导T和ParamType
```

### ParamType cases：
- case 1: ParamType is a pointer or reference type, but not a universal reference（通用引用）.<br> 
    (1) 如果expr是引用，则忽略引用<br> 
    (2) 根据ParamType和expr类型推导
```
template<typename T>
void f(T& param);       // param is a reference

int x = 27;
const int cx = x;
const int& rx = x;

f(x);   ====>  param: int&          ====> T: int
f(cx);  ====>  param: const int&    ====> T: const int
f(rx);  ====>  param: const int&    ====> T: const int   // rx是引用，忽略引用部分
```
```
template<typename T>
void f(const T& param);// param is now a ref-to-const

int x = 27;
const int cx = x;
const int& rx = x;

f(x);   ====> param: const int&     ====> T: int
f(cx);  ====> param: const int&     ====> T: int
f(rx);  ====> param: const int&     ====> T: int
```

- case 2: ParamType is a universal reference
1. 如果expr是左值，T和ParamType都会被推导为左值引用。这非常不寻常，第一，这是模板类型推导中唯一一种T被推导为引用的情况。第二，虽然ParamType被声明为右值引用类型，但是最后推导的结果是左值引用。
2. 如果expr是右值，就使用正常的（也就是case 1）推导规则
```
template<typename T>
void f(T&& param);// param is now a universal reference
int x = 27;
const int cx = x;
const int& rx = x;

f(x);   ====> x: lvalue     ====> ParamType: int&           ====> T: int&
f(cx);  ====> cx: lvalue    ====> ParamType: const int&     ====> T: const int&
f(rx);  ====> rx: lvalue    ====> ParamType: const int&     ====> T: const int&
f(27);  ====> 29: rvalue    ====> ParamType: T&&            ====> T: int
```
- case 3: ParamType is neither a pointer nor a reference<br>
当ParamType既不是指针也不是引用时，我们通过传值（pass-by-value）的方式处理<br>
这表明着无论传递什么，param都会成为它的一份拷贝，一个完整的新对象。事实上param成为一个新对象这一行为会影响T如何从expr中推导出结果。
1. 如果expr的类型是一个引用，忽略引用部分
2. 如果忽略expr的引用性（reference-ness）之后，expr是一个const，那就再忽略const。如果它是volatile，也忽略volatile
```
template<typename T>
void f(T param);                //以传值的方式处理param

int x = 27;
const int cx = x;
const int& rx = cx;

f(x);     ====> x: int          ====> ParamType: int     ====> T: int
f(cx);    ====> x: const int    ====> ParamType: int     ====> T: int
f(rx);    ====> x: const int&   ====> ParamType: int     ====> T: int
```
拷贝之后，会忽略常量性
```
template<typename T>
void f(T param);                //仍然以传值的方式处理param

const char* const ptr =         //ptr是一个常量指针，指向常量对象 
    "Fun with pointers";

f(ptr);     ====> ptr: const char* const    ====> T: const char*    // 指针ptr经过拷贝后，不具有常量性，但指针指向的字符串并没有进行拷贝，还具有常量性。
```

### 数组实参
```
const char name[] = "J. P. Briggs";     //name的类型是const char[13]
const char* ptrToName = name;          //数组退化为指针

template<typename T>
void f(T param);                        //传值形参的模板
f(name);                                //T和param会推导成什么类型?
数组形参会退化为指针      param: const char*        T: const char 

template<typename T>
void f(T& param);                       //传引用形参的模板
f(name);
T被推导为了真正的数组！这个类型包括了数组的大小，在这个例子中T被推导为const char[13]，f的形参（对这个数组的引用）的类型则为const char (&)[13]。

//在编译期间返回一个数组大小的常量值（//数组形参没有名字，因为我们只关心数组的大小）
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}
```

## 条款2 理解auto类型推导
- auto类型推导通常和模板类型推导相同，但是auto类型推导假定花括号初始化代表std::initializer_list，而模板类型推导不这样做
```
auto x = { 11, 23, 9 };         //x的类型是std::initializer_list<int>

template<typename T>            //带有与x的声明等价的
void f(T param);                //形参声明的模板

f({ 11, 23, 9 });               //错误！不能推导出T


template<typename T>
void f(std::initializer_list<T> initList);

f({ 11, 23, 9 });               //T被推导为int，initList的类型为std::initializer_list<int>
```

## 条款3 理解decltype
在C++11中，decltype最主要的用途就是用于声明函数模板，而这个函数返回类型依赖于形参类型。举个例子，假定我们写一个函数，一个形参为容器，一个形参为索引值，这个函数支持使用方括号的方式（也就是使用“[]”）访问容器中指定索引值的数据，然后在返回索引操作的结果前执行认证用户操作。函数的返回类型应该和索引操作返回的类型相同


## 条款7：区别使用()和{}创建对象
narrowing conversion: A conversion from one data type to another where the new data type’s size is smaller than the old one’s, such that the conversion may result in loss of information.(double->int 错误)

## Modern C++
### nullptr
```
传统C++会把NULL、0 视为同一种东西，这取决于编译器如何定义 NULL，有些编译器会将 NULL 定义为 ((void*)0)，有些则会直接将其定义为 0。
C++ 不允许直接将 void * 隐式转换到其他类型。但如果编译器尝试把 NULL 定义为 ((void*)0)，那么在下面这句代码中：

char *ch = NULL;

没有了 void * 隐式转换的 C++ 只好将 NULL 定义为 0。而这依然会产生新的问题，将 NULL 定义成 0 将导致 C++ 中重载特性发生混乱。考虑下面这两个 foo 函数：

void foo(char*);
void foo(int);
```

### constexpr
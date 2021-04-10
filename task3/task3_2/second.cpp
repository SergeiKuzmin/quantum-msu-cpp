#include <iostream>

class A{
public:
int a;
};

class B{
public:
int b;
};

class C: public A, public B{
public:
int c;
};

int main()
{
    C c;
    std::cout << &c << std::endl;
    std::cout << std::endl;
    std::cout << static_cast<A*>(&c) << std::endl;
    std::cout << static_cast<B*>(&c)<< std::endl;
    std::cout << reinterpret_cast<A*>(&c) << std::endl;
    std::cout << reinterpret_cast<B*>(&c) << std::endl;
    std::cout << std::endl;
    std::cout << (A*)(&c) << std::endl;
    std::cout << (B*)(&c) << std::endl;
    return 0;
}

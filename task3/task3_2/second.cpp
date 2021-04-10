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
    std::cout << "&c: " << &c << std::endl;
    std::cout << std::endl;

    std::cout << "static_cast<A*>(&c): " << static_cast<A*>(&c) << std::endl;
    std::cout << "static_cast<B*>(&c): " << static_cast<B*>(&c) << std::endl;
    std::cout << "reinterpret_cast<A*>(&c): " << reinterpret_cast<A*>(&c) << std::endl;
    std::cout << "reinterpret_cast<B*>(&c): " << reinterpret_cast<B*>(&c) << std::endl;
    std::cout << std::endl;

    std::cout << "(A*)(&c): " << (A*)(&c) << std::endl;
    std::cout << "(B*)(&c): " << (B*)(&c) << std::endl;
    std::cout << std::endl;

    std::cout << "&(c.a): " << &(c.a) << std::endl;
    std::cout << "&(c.b): " << &(c.b) << std::endl;
    std::cout << "&(c.c): " << &(c.c) << std::endl;
    return 0;
}

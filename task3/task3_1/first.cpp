#include <iostream>

class A{
public:
virtual ~A(){
    std::cout << "Destructor of A" << std::endl;
}
};

class B{
public:
~B(){
    std::cout << "Destructor of B" << std::endl;
}
};

class C: public A, public B{
public:
~C(){
    std::cout << "Destructor of C" << std::endl;
}
};

class D: public C{
public:
~D(){
    std::cout << "Destructor of D" << std::endl;
}
};

int main()
{
    A *a = new C();
    delete a;
    std::cout << std::endl;

    B *b = new C();
    delete b;
    std::cout << std::endl;

    C *c = new C();
    delete c;
    std::cout << std::endl;

    C *d = new D();
    delete d;
    std::cout << std::endl;

    return 0;
}

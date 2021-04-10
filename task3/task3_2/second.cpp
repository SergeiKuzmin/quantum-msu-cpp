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
};

int main()
{
    C *c = new C;
    delete c;
    return 0;
}

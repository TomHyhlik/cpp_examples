#include <iostream>
#include <string>

///////////////////////////////////////////////////////
class printable 
{
    public:
        virtual std::string getClassName() = 0;
};

///////////////////////////////////////////////////////
class A : public printable
{
    public:
        std::string getClassName() override 
        {
            return "A";
        }
};

///////////////////////////////////////////////////////
class B : public A
{
    public:
        std::string getClassName() override
        {
            return "B";
        }
};

///////////////////////////////////////////////////////
void printObjectName(printable* obj)
{
    std::cout << obj->getClassName() << std::endl;
}

///////////////////////////////////////////////////////
int main(void)
{
    A a;
    B b;

    printObjectName(&a);
    printObjectName(&b);

    return 0;
}

///////////////////////////////////////////////////////
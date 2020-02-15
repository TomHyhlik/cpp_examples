#include <iostream>
#include <string>


template <typename T>
/* aslso can be written as */
// template <typename T>

void Print(T val)
{
    std::cout << "Printing value: " << val << std::endl;
    val++;
    std::cout << "Printing incremented value: " << val << std::endl;

}


int main()
{
    std::cout << "AppStart..............." << std::endl;

    Print(19);

    Print(3.1421);

    Print("Some data");

    std::cout << "AppEnd..............." << std::endl;
    return 0;
}


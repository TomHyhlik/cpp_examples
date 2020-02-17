#include <iostream>
#include <tuple>

/*
 * Since c++17
 * tuple enables to return multiple variables from function
 */

std::tuple<std::string, int> CreatePerson()
{
    return { "Karl", 25};
}


int main()
{
    std::cout << "AppStart..............." << std::endl;

    auto[name, age] = CreatePerson();
    std::cout   << "Name: " << name << std::endl
                << "Age: " << age << std::endl;

    std::cout << "AppEnd..............." << std::endl;
    return 0;
}

